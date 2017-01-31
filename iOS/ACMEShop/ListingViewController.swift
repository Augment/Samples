//
//  ListingViewController.swift
//  ACMEShop
//
//  Copyright © 2016-present Augment. All rights reserved.
//

import UIKit

/**
 * Listing View controller
 * Show a list of product for a given Category
 */
class ListingViewController: UIViewController {

    fileprivate let ListingToProductSegue = "ListingToProduct"

    // Current category from the previous view controller
    var currentCategory: Category!

    // Basic datasource
    var products = [Product]()

    let flowLayout = UICollectionViewFlowLayout()

    @IBOutlet weak var collectionView: UICollectionView! {
        didSet {
            collectionView.delegate   = self
            collectionView.dataSource = self
            collectionView.alwaysBounceVertical = true
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.title = currentCategory.title
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

        let margin: CGFloat = 0
        let cols:   CGFloat = 1
        let width:  CGFloat = (size.width - ((cols + 1) * margin)) / cols;
        let height: CGFloat = 100 //width * 1 // ratio

        flowLayout.itemSize = CGSize(width: width, height: height)
        flowLayout.minimumInteritemSpacing = margin
        flowLayout.minimumLineSpacing      = margin
        flowLayout.headerReferenceSize     = CGSize.zero
        flowLayout.footerReferenceSize     = CGSize.zero
        flowLayout.sectionInset            = UIEdgeInsets(top: margin, left: margin, bottom: margin, right: margin)

        collectionView.collectionViewLayout = flowLayout
    }

    /**
     * Load the product for that Category
     * We are faking it with our Fake model,
     * it could be an asynchronous query over the network.
     */
    func load() {
        products = Category.GetProducts(forCategory: currentCategory)
        collectionView.reloadData()
    }

    // MARK: - Navigation

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {

        switch segue.identifier! {
        case ListingToProductSegue:
            let vc = segue.destination as! ProductViewController
            if let row = collectionView.indexPathsForSelectedItems?.first?.row {
                vc.product = products[row]
            }

        default: break
        }
    }

}

// MARK: - UICollectionViewDelegate

extension ListingViewController: UICollectionViewDelegate {

    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        performSegue(withIdentifier: ListingToProductSegue, sender: nil)
    }
}

// MARK: - UICollectionViewDataSource

extension ListingViewController: UICollectionViewDataSource {
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return products.count
    }

    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "ProductCell", for: indexPath)
        
        let product = products[indexPath.row]
        
        let pictureView = cell.viewWithTag(1) as! UIImageView
        let titleView   = cell.viewWithTag(2) as! UILabel

        // Fake border
        cell.viewWithTag(3)?.backgroundColor = Colors.PrimaryAlpha8

        pictureView.image = product.image
        titleView.text    = product.title

        return cell
    }
}
