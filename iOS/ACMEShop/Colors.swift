//
//  Colors.swift
//  ACMEShop
//
//  Copyright © 2016-present Augment. All rights reserved.
//

import UIKit

struct Colors {
    static let Primary       = UIColor(fromHex: "096EB2")
    static let PrimaryAlpha8 = UIColor(fromHex: "096EB288")
    static let PrimaryDark   = UIColor(fromHex: "000000")
    static let Accent        = UIColor(fromHex: "B23332")
    static let Background    = UIColor(fromHex: "FFFFFF")
    static let Foreground    = UIColor(fromHex: "111111")
}

extension UIColor {
    convenience init(fromHex: String) {
        let hex = fromHex.replacingOccurrences(of: "#", with: "")
        var r = "00", g = "00", b = "00", a = "FF"
        let i = hex.startIndex
        if hex.characters.count == 6 {
            r = hex[i...hex.index(i, offsetBy: 1)]
            g = hex[hex.index(i, offsetBy: 2)...hex.index(i, offsetBy: 3)]
            b = hex[hex.index(i, offsetBy: 4)...hex.index(i, offsetBy: 5)]
        } else if hex.characters.count == 8 {
            r = hex[i...hex.index(i, offsetBy: 1)]
            g = hex[hex.index(i, offsetBy: 2)...hex.index(i, offsetBy: 3)]
            b = hex[hex.index(i, offsetBy: 4)...hex.index(i, offsetBy: 5)]
            a = hex[hex.index(i, offsetBy: 6)...hex.index(i, offsetBy: 7)]
        }
        
        self.init(
            red:   CGFloat(Int(r, radix: 16)!)/255,
            green: CGFloat(Int(g, radix: 16)!)/255,
            blue:  CGFloat(Int(b, radix: 16)!)/255,
            alpha: CGFloat(Int(a, radix: 16)!)/255
        )
    }
}
