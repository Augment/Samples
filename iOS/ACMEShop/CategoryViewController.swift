//
//  CategoryViewController.swift
//  ACMEShop
//
//  Copyright © 2016-present Augment. All rights reserved.
//

import UIKit

/**
 * Category View controller
 * Entry point of the App
 * Show the list of available Category
 */
class CategoryViewController: UIViewController {
    
    fileprivate let CategoryToListingSegue = "CategoryToListing"
    
    // Basic datasource
    var categories = [Category]()

    @IBOutlet weak var collectionView: UICollectionView! {
        didSet {
            collectionView.delegate   = self
            collectionView.dataSource = self
            collectionView.alwaysBounceVertical = true
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.title = "ACMEShop"
        navigationController?.navigationBar.barTintColor = Colors.Primary
        navigationController?.navigationBar.tintColor    = Colors.Background
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        load()
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        refreshLayoutForSize(size: view.frame.size)
    }
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
        refreshLayoutForSize(size: size)
    }
    
    func refreshLayoutForSize(size: CGSize) {
        
        let margin: CGFloat = 8
        let cols:   CGFloat = 2
        let width:  CGFloat = (size.width - ((cols + 1) * margin)) / cols;
        let height: CGFloat = width * 1 // ratio
        
        let flowLayout = collectionView.collectionViewLayout as! UICollectionViewFlowLayout
        flowLayout.itemSize = CGSize(width: width, height: height)
        flowLayout.minimumInteritemSpacing = margin
        flowLayout.minimumLineSpacing      = margin
        flowLayout.headerReferenceSize     = CGSize.zero
        flowLayout.footerReferenceSize     = CGSize.zero
        flowLayout.sectionInset            = UIEdgeInsets(top: margin, left: margin, bottom: margin, right: margin)
        
        collectionView.collectionViewLayout = flowLayout
    }
    
    /**
     * Load the Categories
     * We are faking it with our Fake model,
     * it could be an asynchronous query over the network.
     */
    func load() {
        self.categories = Category.GetCategories()
        collectionView.reloadData()
    }
    
    // MARK: - Navigation
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        
        switch segue.identifier! {
        case CategoryToListingSegue:
            let vc = segue.destination as! ListingViewController
            if let row = collectionView.indexPathsForSelectedItems?.first?.row {
                vc.currentCategory = categories[row]
            }
            
        default: break
        }
    }
}

// MARK: - UICollectionViewDelegate

extension CategoryViewController: UICollectionViewDelegate {
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        performSegue(withIdentifier: CategoryToListingSegue, sender: nil)
    }
}

// MARK: - UICollectionViewDataSource

extension CategoryViewController: UICollectionViewDataSource {
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return categories.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "CategoryCell", for: indexPath)
        
        let category = categories[indexPath.row]
        
        let pictureView    = cell.viewWithTag(1) as! UIImageView
        let titleView      = cell.viewWithTag(2) as! UILabel
        let blurBackground = cell.viewWithTag(3) as! UIVisualEffectView
        
        pictureView.image = category.image
        titleView.text    = category.title
        blurBackground.backgroundColor = Colors.PrimaryAlpha8

        cell.layer.borderWidth = 1
        cell.layer.borderColor = Colors.Primary.cgColor
        cell.cornerRadius = Dim.RadiusButton

        return cell
    }
}

// Helper as an extension

extension UIViewController {
    func showError(message: String) {
        let alert = UIAlertController(title: "Error", message: message, preferredStyle: UIAlertControllerStyle.alert)
        alert.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
        present(alert, animated: true, completion: nil)
    }
}

extension UIView {
    var cornerRadius: CGFloat {
        get {
            return layer.cornerRadius
        }
        set(newValue) {
            layer.cornerRadius = newValue
            clipsToBounds = newValue > 0
        }
    }
}

