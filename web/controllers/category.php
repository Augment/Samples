<?php

use Silex\Application;
use Symfony\Component\HttpFoundation\Request;

return function(Application $app, Request $request, $id, $slug) use ($config) {
    return $app['twig']->render('category.twig', [
        'category'   => Category::GetCategory($id),
        'categories' => Category::GetCategories(),
        'products'   => Category::GetProducts($id)
    ]);
};
