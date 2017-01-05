<?php

$details = [
    "lipsum-1" => "Lorem ipsum dolor sit amet, consectetur adipiscing elit. In accumsan a augue pulvinar mollis. Sed et ullamcorper sem, eget accumsan sem. Donec ac leo at lacus sagittis tincidunt. Donec sagittis quam diam, a tempor eros interdum malesuada. Vestibulum sagittis sem ac neque cursus bibendum. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus non dictum turpis. Sed venenatis, dolor sed egestas congue, urna ipsum fringilla ex, sed convallis velit orci vitae enim. Aliquam odio turpis, pretium id quam id, varius volutpat ipsum. Duis pharetra lacus tellus, non dictum nulla aliquam eget.",
    "lipsum-2" => "Duis rhoncus id neque non varius. Phasellus tristique, lorem vel bibendum dictum, orci erat pharetra mi, sit amet dapibus lectus lorem eget est. Mauris consectetur blandit tortor, eu pulvinar mi tempor quis. Vivamus purus sapien, bibendum a nisl consequat, condimentum vestibulum nisi. In hac habitasse platea dictumst. Vivamus nec orci dictum, iaculis lorem et, sollicitudin lacus. Morbi venenatis felis tristique egestas semper. Curabitur at risus cursus, maximus odio vitae, faucibus turpis. Nullam et tristique lacus, sit amet ullamcorper nibh. Nulla quis maximus dolor. Nulla tincidunt nibh tellus. Donec mauris nisi, congue at aliquet at, blandit sit amet nulla. Etiam quis ligula fringilla, finibus lorem vel, maximus mauris.",
    "lipsum-3" => "Interdum et malesuada fames ac ante ipsum primis in faucibus. Nulla consequat fermentum luctus. In a urna in magna viverra elementum bibendum eget metus. Curabitur metus dolor, congue quis tellus nec, ultricies iaculis turpis. Nunc tristique convallis dui, nec fringilla sem tempus ac. In mattis ac nisl eu egestas. Ut sodales odio id mollis commodo. Nullam justo nibh, vehicula ut purus sed, efficitur commodo ligula. Nunc faucibus dapibus turpis vel iaculis.",
    "lipsum-4" => "Nunc aliquam, sapien a placerat imperdiet, turpis metus dapibus nulla, nec molestie est quam id sem. Vestibulum a sem est. Sed tincidunt ipsum ut dapibus pharetra. Quisque iaculis hendrerit odio, eget facilisis sem consequat non. Phasellus tempus, lorem in blandit viverra, odio mauris tempus lorem, ut lacinia quam velit non nulla. Aliquam ac eleifend arcu. Fusce sem elit, tincidunt et pharetra quis, tempor in purus. Aenean eget viverra ante. Suspendisse maximus mi eget eros porta, eget varius mauris consequat. Nunc blandit lectus et mi rutrum lobortis. Proin rhoncus, lectus nec luctus tristique, sem libero facilisis diam, sed aliquam ante leo a ex.",
    "lipsum-5" => "Nam quis lorem ac arcu vulputate commodo. Ut ante erat, convallis id est a, feugiat pellentesque ex. Nunc efficitur erat nec augue venenatis ultrices quis non lectus. Nunc nec ornare quam. Duis turpis nisi, fermentum sit amet mauris a, faucibus semper nisi. Cras egestas justo sem, ac lacinia nulla eleifend id. Suspendisse volutpat dictum scelerisque. Phasellus magna nisl, efficitur at risus eu, efficitur fringilla dolor. Sed est urna, sodales vel pulvinar sit amet, rutrum in augue. Donec rutrum ante vel sem tempor dapibus. In ullamcorper scelerisque lacus nec mollis. Nullam non ultricies libero. Duis id consectetur justo."
];

// ACME Shop data
$data = new stdClass();
$data->categories = [
    1 => new Category(1, "Home Appliance", "category_homeappliance"),
    2 => new Category(2, "Laptops, Tablets", "category_laptop"),
    3 => new Category(3, "Mobile Phones", "category_phone"),
    4 => new Category(4, "Portable Speakers", "category_speakers"),
    5 => new Category(5, "TV", "category_tv"),
];

$data->products = [
    1  => new Product(1,  "3700342425321", "AIR", "Force Extreme", "airforceextreme", 179.99, $details["lipsum-1"]),
    2  => new Product(2,  "0017817704656", "Bose", "Soundlink Mini II", "bosesoundlinkminiii", 199.99, $details["lipsum-2"]),
    3  => new Product(3,  "3045386370108", "Cookeo", " Connect", "cookeoconnect", 319.99, $details["lipsum-3"]),
    4  => new Product(4,  "0888462368285", "Apple", "iPad Mini4", "ipadmini", 339.99, $details["lipsum-4"]),
    5  => new Product(5,  "0888462735605", "Apple", "iPhone SE", "iphonese", 659.99, $details["lipsum-5"]),
    6  => new Product(6,  "0050036326438", "JBL", "Charge 2 plus", "jblchargeplus", 129.99, $details["lipsum-1"]),
    7  => new Product(7,  "0050036327350", "JBL", "Pulse 2", "jblpulse", 159.99, $details["lipsum-2"]),
    8  => new Product(8,  "8806087217100", "LG", "55EG960V", "lgegv", 1669.99, $details["lipsum-3"]),
    9  => new Product(9,  "6068860953717", "Apple", "Macbook Pro", "macbookpro", 1599.99, $details["lipsum-4"]),
    10 => new Product(10, "3016661148095", "Masterchef", "Gourmet", "masterchefgourmet", 199.99, $details["lipsum-5"]),
    11 => new Product(11, "3016661146855", "Moulinex", "Companion", "moulinexcompanion", 699.99, $details["lipsum-1"]),
    12 => new Product(12, "3662734940518", "Nespresso", "Pixie", "nespressopixie", 99.99, $details["lipsum-2"]),
    13 => new Product(13, "5025232824670", "Panasonic", "TX 65CZ950E", "panasonictxcze", 9999.99, $details["lipsum-3"]),
    14 => new Product(14, "8806086511599", "Samsung", "UE 55H6400", "samsungueh", 699.99, $details["lipsum-4"]),
    15 => new Product(15, "3045385736158", "Moulinex", "Toaster Subito", "toastermoulinexsubito", 29.99, $details["lipsum-5"]),
    16 => new Product(16, "8003437261381", "Whirlpool", "FSCR 80421", "whirlpoolfscr80421", 439.99, $details["lipsum-1"]),
    17 => new Product(17, "6438158721470", "Nokia", "Lumia 640", "lumia640", 119.99, $details["lipsum-2"]),
    18 => new Product(18, "6438158744554", "Nokia", "Lumia 550", "lumia550", 99.99, $details["lipsum-1"]),
    19 => new Product(19, "8007842628487", "Indesit", "IWC 5125", "indesitiwc5125", 229.99, $details["lipsum-3"]),
    20 => new Product(20, "0888462570350", "Apple", "iPhone 6S PLUS", "iphone6p", 899.99, $details["lipsum-4"]),
    21 => new Product(21, "",              "Luxy", "Fauteuil", "fauteuil", 899.99, $details["lipsum-4"]),
    // Product that is not present in our database
    99 => new Product(99, "3045385736000", "Moulinex", "Toaster Moulinex", "toastermoulinexsubito", 29.99, "This product does not exist in ou product database, it is here to test that use case. (Warning: missing product)"),
];

$data->products_categories = [
    // Home Applicance
    1 => [21, 1, 2, 10, 11, 12, 15, 16, 19, 99],
    // Laptops
    2 => [9, 4],
    // Mobiles Phones
    3 => [4, 5, 17, 18, 20],
    // Portable Speakers
    4 => [2, 7, 6],
    // TV
    5 => [8, 13, 14],
];
