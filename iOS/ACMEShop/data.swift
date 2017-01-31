//
//  data.swift
//  ACMEShop
//
//  Copyright © 2016-present Augment. All rights reserved.
//

import Foundation

/**
 * This is the Fake data that we use to populate the app
 */
struct data {
    static let categories: [Int : Category] = [
        // This will be ordered by index
        1: Category(id: 1, title: "Small Household Appliances", picture: "category_homeappliance"),
        2: Category(id: 2, title: "Laptops", picture: "category_laptop"),
        3: Category(id: 3, title: "Mobile Phones", picture: "category_phone"),
        4: Category(id: 4, title: "Portable Speakers", picture: "category_speakers"),
        5: Category(id: 5, title: "TV and Projectors", picture: "category_tv"),
    ]
    
    static let products_categories: [Int: [Int]] = [
        // Home Applicances
        1: [1,3,10,11,12,15,16,19],
        // Laptops
        2: [9,4],
        // Mobiles Phones
        3: [4,5,17,18,20],
        // Portables Speakers
        4: [2,6,7],
        // TV
        5: [8,13,14]
    ]

    static let products: [Int : Product] = [
        1: Product(id: 1,  ean:  "3700342425321", brand: "Rowenta", name: "AIR Force Extreme", picture: "AIR-Force-Extreme.png", price: 179.99, details: "Air Force Extreme Lithium is a powerful cordless vacuum cleaner that delivers optimal cleaning results at an outstanding level of convenience. An ultra-modern cleaning tool featuring a DELTA suction head with high-speed power brush and highly efficient cyclonic technology."),
        2: Product(id: 2,  ean:  "0017817704656", brand: "Bose", name: "Soundlink Mini II", picture: "Bose_Soundlink_Mini_II.png", price: 199.99, details: "Enjoy your music on the go, everywhere you go. The Soundlink® Mini Bluetooth speaker II delivers full, natural sound with dramatically deeper bass than you'd expect from an ultra-compact speaker that fits in the palm of your hand. It connects wirelessly to your smartphone, tablet or other Bluetooth device, so you can listen to your music, videos or games anytime, anywhere. And the built-in speakerphone lets you take calls out loud, too."),
        3: Product(id: 3,  ean:  "3045386370108", brand: "Cookeo", name: "Connect", picture: "Cookeo-Connect.png", price: 319.99, details: "<b>Anti-Adhesive Tank</b><br>\n<b>Timer</b><br>\n<b>Vacuum Cooking Function</b><br>\n<b>Pressure Cooker Function</b><br>\n<b>Rice Cooker Function</b><br>\n<br>\nCapable of exchanging information in real time via a dedicated application, the intelligent connected multicooker sounds yet like a revolution for the kitchens!<br>\nUse is so simple: the user chooses a recipe from his tablet or smartphone which is sent to the Cookeo and can then follow it either from the tablet or directly on the appliance."),
        4: Product(id: 4,  ean:  "0888462368285", brand: "Apple", name: "iPad Mini4", picture: "iPad-Mini4.png", price: 339.99, details: "iPad mini 4 puts everything you love about iPad into an incredibly sleek and portable design. So you can enjoy FaceTime calls with friends or get work done, wherever and whenever you want."),
        5: Product(id: 5,  ean:  "0888462735605", brand: "Apple", name: "iPhone SE", picture: "iPhone-SE.png", price: 659.99, details: "Welcome to iPhone SE, the most powerful 4‑inch phone ever. To create it, we started with a beloved design, then reinvented it from the inside out. The A9 is the same advanced chip used in iPhone 6s. The 12‑megapixel camera captures incredible photos and 4K videos. And Live Photos bring your images to life. The result is an iPhone that looks small. But lives large."),
        6: Product(id: 6,  ean:  "0050036326438", brand: "JBL", name: "Charge 2 plus", picture: "JBL-Charge2plus.png", price: 129.99, details: "The JBL Charge 2+ is a well-designed, water-resistant portable Bluetooth speaker that features good battery life and doubles as an external charger for your portable devices. It also has built-in speakerphone capabilities, and plays loudly with relatively strong bass and top-notch performance for its size and price class."),
        7: Product(id: 7,  ean:  "0050036327350", brand: "JBL", name: "Pulse 2", picture: "JBL-Pulse-2.png", price: 159.99, details: "The JBL Charge 2+ is a well-designed, water-resistant portable Bluetooth speaker that features good battery life and doubles as an external charger for your portable devices. It also has built-in speakerphone capabilities, and plays loudly with relatively strong bass and top-notch performance for its size and price class."),
        8: Product(id: 8,  ean:  "8806087217100", brand: "LG", name: "55EG960V", picture: "LG_55EG960V.png", price: 1669.99, details: "Fusing OLED technology with 4K resolution, LG OLED 4K TV brings you the finest viewing experience imaginable. With self-lighting pixels - meaning they switch on and off individually - OLED delivers the purest blacks, most brilliant colours and clearest images."),
        9: Product(id: 9,  ean:  "6068860953717", brand: "Apple", name: "Macbook Pro", picture: "Macbook-Pro.png", price: 1599.99, details: "It’s faster and more powerful than before, yet remarkably thinner and lighter. It has the brightest, most colorful Mac notebook display ever. And it introduces the Touch Bar — a Multi-Touch enabled strip of glass built into the keyboard for instant access to the tools you want, right when you want them. The new MacBook Pro is built on groundbreaking ideas. And it’s ready for yours."),
        10: Product(id: 10, ean: "3016661148095", brand: "Moulinex", name: "Masterchef Gourmet", picture: "Masterchef-Gourmet.png", price: 199.99, details: "The powerful and versatile kitchen machine for effortless meals! Equipped with multiple attachments (blender, shredder/slicer, juice extractor and meat mincer) for a varied preparation"),
        11: Product(id: 11, ean: "3016661146855", brand: "Moulinex", name: "Companion", picture: "Moulinex-Companion.png", price: 699.99, details: "Cuisine Companion invites you to enjoy periods of pleasure in your daily menus, via a simple gesture. The secret of making a perfect, delicate sauce: the combination of a impeccable cooking technique and regular stirring. Enhance your dishes effortlessly."),
        12: Product(id: 12, ean: "3662734940518", brand: "Nespresso", name: "Pixie", picture: "Nespresso-Pixie.png", price: 99.99, details: "Standing a little over 8 Nespresso capsules piled high, and yet with a deep water storage space, PIXIE is no larger or longer than a coffee spoon. Its size is that of a small rabbit, with delicate ears and soft fur."),
        13: Product(id: 13, ean: "5025232824670", brand: "Panasonic", name: "TX 65CZ950E", picture: "Panasonic_TX_65CZ950E.png", price: 9999.99, details: "The Panasonic TX-65CZ952B is the company’s first 4K OLED TV, and it looks so good that it may very well usher in the next phase in television. Yes, really. This is one of the best pictures we’ve seen. Christmas has come early."),
        14: Product(id: 14, ean: "8806086511599", brand: "Samsung", name: "UE 55H6400", picture: "Samsung_UE55H6400.png", price: 699.99, details: "Thanks to a powerful Quad Core processor, your Samsung Smart TV offers enhanced performance. You’ll notice the difference straight away, with faster multitasking and switching between content and web browsing, as well as smoother interaction. With this extra power, your entertainment experience will be so much more enjoyable, with less waiting and more viewing."),
        15: Product(id: 15, ean: "3045385736158", brand: "Moulinex", name: "Toaster Subito", picture: "Toaster-Moulinex-Subito.png", price: 29.99, details: "Thanks to its long toasting slot and 1000W of power, your bread is toasted in double-quick time! Its 6-position thermostat gives you a choice of browning levels, while the stop-eject button means you can interrupt the process at any time, thereby ensuring perfect results. It also boasts settings for defrosting frozen bread and for reheating cold toast."),
        16: Product(id: 16, ean: "8003437261381", brand: "Whirlpool", name: "FSCR 80421", picture: "whirlpoolfscr80421.png", price: 439.99, details: "Discover perfect care. 6th SENSE intelligent sensors adapt resources according to the size and type of load, offering savings of up to 50%* on energy, water and time."),
        17: Product(id: 17, ean: "6438158721470", brand: "Nokia", name: "Lumia 640", picture: "lumia640.png", price: 119.99, details: "You never know when you’ll come up with your next great idea. So be ready to capture your creativity with a phone that has everything you need to turn inspiration into action."),
        18: Product(id: 18, ean: "6438158744554", brand: "Nokia", name: "Lumia 550", picture: "lumia550.png", price: 99.99, details: "Microsoft’s Windows Phone has been pointed at the low-end of the smartphone market since the Lumia 520 was revealed to have sold 25 million units shortly after its debut. In 2014, Nokia attempted to capitalize on this by releasing a successor to the Lumia 520, the 530. The only problem with this device is that it ended up being genuinely worse than its immediate predecessor and, as a result, we are faced with a bizarre situation where the Lumia 520 family can be updated to Windows 10 but the 530 cannot. Microsoft learned from the 530 and 630 debacles when it took over and released the Lumia 540 and 640 series which were much more complete phones and were competitive for the price range. With the Lumia 550, Microsoft seems to have forgotten all that and reverted to Nokia’s cost-cutting ways. The Lumia 550 is a device that is – like the 530 – contextually worse than its immediate predecessor."),
        19: Product(id: 19, ean: "8007842628487", brand: "Indesit", name: "IWC 5125", picture: "indesitiwc5125.png", price: 229.99, details: "No description available"),
        20: Product(id: 20, ean: "0888462570350", brand: "Apple", name: "iPhone 6S PLUS", picture: "iphone6p.png", price: 899.99, details: "No description available")
    ]
}
