//
//  Product.swift
//  ACMEShop
//
//  Copyright © 2016-present Augment. All rights reserved.
//

import Foundation

/**
 * This model is part of the Fake data model that we use to populate the app
 * Each Product is a basic object, fields are self explicits
 */
struct Product {
    
    let id: Int
    let ean: String
    let brand: String
    let name: String
    let picture: String
    let price: Float
    let details: String
    
    var title: String {
        get {
            return "\(brand) \(name)"
        }
    }
    
    /**
     * The identifier is used to query Augment database,
     * here we are using the internal id and convert that to a string
     */
    var identifier: String {
        get {
            return "\(id)"
        }
    }
}
