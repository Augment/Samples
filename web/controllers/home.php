<?php

use Silex\Application;
use Symfony\Component\HttpFoundation\Request;

return function(Application $app, Request $request) use ($config) {
    // Best product is a fake Category made up here
    $bestProducts = [
        Product::GetProduct(1),
        Product::GetProduct(21),
        Product::GetProduct(3),
        Product::GetProduct(4)
    ];
    return $app['twig']->render('home.twig', [
        'best_products' => $bestProducts,
        'categories'    => Category::GetCategories(),
    ]);
};
