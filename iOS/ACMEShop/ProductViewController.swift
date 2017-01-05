//
//  ProductViewController.swift
//  ACMEShop
//
//  Copyright © 2016-present Augment. All rights reserved.
//

import UIKit

/**
 * The Product View controller
 * In this view controller we show a detailed view of a product
 */
class ProductViewController: UIViewController {

    fileprivate let ProductToAugmentSegue = "ProductToAugment"
    
    // Current product from the previous view controller
    var product: Product!
    
    /**
     * Augment SDK
     * It has been initialized on the AppDelegate.swift file
     * So here we get an already configurated instance
     */
    lazy var augmentSDK: AGTAugmentSDK! = {
        return AGTAugmentSDK()
    }()

    @IBOutlet weak var productImageView: UIImageView!
    @IBOutlet weak var productTitleLabel: UILabel!
    @IBOutlet weak var productDetailsTextView: UITextView!
    @IBOutlet weak var productPriceLabel: UILabel!
    @IBOutlet weak var productBorderBottom: UIView! {
        didSet {
            productBorderBottom.backgroundColor = Colors.Primary
        }
    }
    
    @IBOutlet weak var buyButton: UIButton! {
        didSet {
            buyButton.backgroundColor = Colors.Primary
        }
    }
    @IBOutlet weak var seeButton: UIButton! {
        didSet {
            seeButton.backgroundColor = Colors.Primary
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.title = product.title
        
        // We don't know yet if this product is available
        seeButton.isEnabled = false
        
        load()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        productImageView.image = UIImage(named: product.picture)
        productTitleLabel.text = product.title
        productDetailsTextView.text = product.details
        productPriceLabel.text = "\(product.price)€"
    }
    
    /**
     * Load will get the product from Augment (or from the cache if available)
     */
    func load() {
        // Check if the product is already in cache
        if let cachedProduct = augmentSDK.productsDataController.product(forIdentifier: product.identifier) {

            // No product found in Augment Product Database
            if cachedProduct == AGTProduct.unfound() {
                self.seeButton.isEnabled = false
                return
            }
            
            // The product exists, show the button
            self.seeButton.isEnabled = true
        }
        else {
            // Query Augment Product Database
            augmentSDK.productsDataController.checkIfModelDoesExist(forProductIdentifier: product.identifier, brand: product.brand, name: product.name, ean: product.ean) {
                augmentProduct, error in
                
                // Check if an error occured, 
                // if so we consider that the product does not exist, and disable the button
                if let _ = error {
                    self.seeButton.isEnabled = false
                    return
                }
                
                // Check if the product is found
                if let _ = augmentProduct {
                    // The product exists
                    self.seeButton.isEnabled = true
                }
                else {
                    // The product does not exists
                    self.seeButton.isEnabled = false
                }
            }
        }
    }

    @IBAction func buyAction(_ sender: AnyObject) {
        showError(message: "This is a demo App :)")
    }

    @IBAction func seeAction(_ sender: AnyObject) {
        performSegue(withIdentifier: ProductToAugmentSegue, sender: nil)
    }
    
    // MARK: - Navigation
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        
        switch segue.identifier! {
        case ProductToAugmentSegue:
            let vc = segue.destination as! AugmentViewController
            vc.product = product
            
        default: break
        }
    }
}
