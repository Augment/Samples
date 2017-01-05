//
//  Category.swift
//  ACMEShop
//
//  Copyright © 2016-present Augment. All rights reserved.
//

import Foundation

/**
 * This model is part of the Fake data model that we use to populate the app
 * Each Category has an unique id, a title and a picture, nothing special
 */
struct Category {
    
    let id: Int
    let title: String
    let picture: String
    
    /**
     * This will give the full Category list,
     * in a real app it could be an asynchronous query over the network.
     * We are keeping thing simple in this example.
     *
     * @return Array of Category
     */
    static func GetCategories() -> [Category] {
        return data.categories.map { $1 }
    }
    
    /**
     * This will give the Product list for a given Category
     * in a real app it could be an asynchronous query over the network.
     * We are keeping thing simple in this example.
     *
     * @param category the category you want the product of
     * @return Array of Product for that Category
     */
    static func GetProducts(forCategory category: Category) -> [Product] {
        var products = [Product]()
        for p in data.products_categories[category.id] ?? [] {
            if let product = data.products[p] {
                products.append(product)
            }
        }
        
        return products
    }
    
}
