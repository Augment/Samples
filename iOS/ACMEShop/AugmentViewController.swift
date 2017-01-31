//
//  AugmentViewController.swift
//  ACMEShop
//
//  Copyright © 2016-present Augment. All rights reserved.
//

import UIKit
import AVFoundation

/**
 * The Augmented Reality View controller
 * In this view controller we use all the Augment SDK parts
 */
class AugmentViewController: UIViewController, UIScrollViewDelegate {

    // Current product from the previous view controller
    var product: Product!

    /**
     * Augment SDK
     * It has been initialized on the AppDelegate.swift file
     * So here we get an already configurated instance
     */
    lazy var augmentSDK: AGTAugmentSDK! = AGTAugmentSDK()

    // Augment Player instance
    var augmentPlayer: AGTAugmentPlayer! {
        get {
            return self.augmentSDK.augmentPlayer
        }
    }

    // Our AGTView from the Storyboard
    @IBOutlet weak var augmentView: AGTView! {
        didSet {
            augmentView.augmentPlayer = augmentPlayer
        }
    }

    @IBOutlet weak var loadingContainerView: UIView!
    @IBOutlet weak var loadingLabel: UILabel!
    @IBOutlet weak var loadingActivityIndicator: UIActivityIndicatorView! {
        didSet {
            loadingActivityIndicator.color = Colors.Primary
        }
    }

    // Please see Augment UX recommendations about how to onboard your users
    @IBOutlet weak var tutorialContainer: UIView!
    @IBOutlet weak var tutorialScrollview: UIScrollView! {
        didSet {
            tutorialScrollview.delegate = self
        }
    }
    @IBOutlet weak var helpButton: UIButton! {
        didSet {
            helpButton.backgroundColor = UIColor(white: 1, alpha: 0.5)
            helpButton.cornerRadius    = Dim.RadiusButton / 2
        }
    }
    @IBOutlet weak var tutorialPageControl: UIPageControl! {
        didSet {
            tutorialPageControl.currentPageIndicatorTintColor = Colors.Primary
        }
    }
    @IBOutlet weak var iGotItButton: UIButton! {
        didSet {
            iGotItButton.backgroundColor = Colors.Primary
            iGotItButton.cornerRadius    = Dim.RadiusButton
        }
    }

    @IBOutlet weak var toolbarContainer: UIView!
    @IBOutlet weak var captureButton: UIButton! {
        didSet {
            captureButton.backgroundColor = Colors.Primary
            captureButton.cornerRadius    = Dim.RadiusButton / 2
        }
    }
    @IBOutlet weak var centerObjectsButton: UIButton! {
        didSet {
            centerObjectsButton.backgroundColor = Colors.Primary
            centerObjectsButton.cornerRadius    = Dim.RadiusButton / 2
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.title = product.title
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        // This is related to how Vuforia is working, it will be updated in the future
        if (self.isBeingPresented || self.navigationController?.isBeingPresented ?? false || self.isMovingToParentViewController) {
            prepareARSession(andStart: load)
        }
    }

    /**
     * This is a mandatory overwrite of the lifecycle view controller method
     */
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        augmentPlayer.pause()
    }

    func prepareARSession(andStart start: @escaping (() -> ())) {
        loadingContainerView.isHidden = false

        /**
         * We need to grant camera permission before starting AugmentPlayerSDK
         * otherwise we will have an error during initialization: "Cannot access the camera"
         * Also we must update our Info.plist to allow camera access on the App level, key: NSCameraUsageDescription
         */
        let authStatus = AVCaptureDevice.authorizationStatus(forMediaType: AVMediaTypeVideo)
        if authStatus == AVAuthorizationStatus.authorized {
            start()
        }
        else if authStatus == AVAuthorizationStatus.notDetermined {
            AVCaptureDevice.requestAccess(forMediaType: AVMediaTypeVideo) {
                granted in
                if granted {
                    start()
                } else {
                    self.showError(message: "Augment Player need access to your camera to work.\nGo to Setting and allow access for this App.")
                }
            }
        }
        else {
            showError(message: "Augment Player need access to your camera to work.\nGo to Setting and allow access for this App.")
        }
    }

    /**
     * Load will be called when all the permissions are granted
     * It will get the product from Augment (or from the cache if available)
     */
    func load() {
        // Check if the product is already in cache
        if let cachedProduct = augmentSDK.productsDataController.product(forIdentifier: product.identifier) {

            // No product found in Augment Product Database
            if cachedProduct == AGTProduct.unfound() {
                loadingContainerView.isHidden = true
                showError(message: "This product is not available yet")
                return
            }

            // Add the product to the augmented view
            addProductToAugmentPlayer(cachedProduct)
        } else {
            // Query Augment Product Database
            queryAugmentDatabase()
        }
    }

    /**
     * Query Augment Product database for the current product
     */
    func queryAugmentDatabase() {
        augmentSDK.productsDataController.checkIfModelDoesExist(forProductIdentifier: product.identifier, brand: product.brand, name: product.name, ean: product.ean) {
            augmentProduct, error in

            // Check if an error occured
            if let error = error {
                self.loadingContainerView.isHidden = true
                self.showError(message: error.localizedDescription)
                return
            }

            // Check if the product is found
            if let augmentProduct = augmentProduct {
                self.addProductToAugmentPlayer(augmentProduct)
            } else {
                self.loadingContainerView.isHidden = true
                self.showError(message: "This product is not available yet")
            }
        }
    }

    /**
     * Add the Augment-product to the AR View
     * In this process the 3D model will be downloaded from the network
     *
     * @param augmentProduct AGTProduct The Augment product from the API call
     */
    func addProductToAugmentPlayer(_ augmentProduct: AGTProduct) {
        augmentSDK.addProduct(toAugmentPlayer: augmentProduct, downloadProgress: {
            (progress: Progress) in
            // Progress callback
            DispatchQueue.main.sync {
                self.loadingLabel.text = progress.localizedDescription
            }
        }) {
            itemIdentifier, errors in

            // Check for errors
            if let errors = errors {
                // Tell the user (warning: multiples error possible)
                let errorMessage = errors.map { $0.localizedDescription }.joined(separator: ", ")
                self.loadingContainerView.isHidden = true
                self.showError(message: errorMessage)
                return
            }

            // If everything is ok we start rendering the model
            if let _ = itemIdentifier {
                self.startAR()
            } else {
                self.loadingContainerView.isHidden = true
                self.showError(message: "Impossible to show this product yet")
            }
        }
    }

    func startAR() {
        loadingContainerView.isHidden = true
        augmentPlayer.resume()
        augmentPlayer.fitModel3DsToView()
        
        toolbarContainer.isHidden = false
    }

    @IBAction func centerObjectsAction(_ sender: Any) {
        augmentPlayer.fitModel3DsToView()
    }

    @IBAction func captureAction() {
        augmentPlayer.takeScreenshot {
            image in
            guard let image = image else {
                return
            }

            self.share(image: image)
        }
    }

    func share(image: UIImage) {
        let shareItems : [Any] = [image]
        let shareViewController = UIActivityViewController(activityItems: shareItems, applicationActivities: nil)
        shareViewController.completionWithItemsHandler = {
            activityType, completed, returnedItems, activityError in
            if let activityError = activityError {
                self.showError(message: activityError.localizedDescription)
            }
        }
        if let pop = shareViewController.popoverPresentationController {
            pop.sourceView = captureButton
        }
        present(shareViewController, animated: true, completion: nil)
    }

    // MARK: - Tutorial

    @IBAction func iGotItAction() {
        tutorialContainer.isHidden = true
    }
    
    @IBAction func helpAction() {
        // Reset and show tutorial
        tutorialScrollview.setContentOffset(CGPoint(x: 0, y: 0), animated: false)
        tutorialPageControl.currentPage = 0
        iGotItButton.isHidden = true
        tutorialContainer.isHidden = false
    }

    func scrollViewDidEndDecelerating(_ scrollView: UIScrollView) {
        let pageNumber = round(scrollView.contentOffset.x / scrollView.frame.size.width)
        tutorialPageControl.currentPage = Int(pageNumber)
        iGotItButton.isHidden = pageNumber < 3
    }
}
