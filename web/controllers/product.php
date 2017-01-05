<?php

use Silex\Application;
use Symfony\Component\HttpFoundation\Request;

return function(Application $app, Request $request, $id, $slug) use ($config) {
    $snippet  = $config->get('snippet');
    $snippet .= 'augment.authenticate({id: "' . $config->get('augment')['id'] . '", key: "' . $config->get('augment')['key'] . '"});';

    return $app['twig']->render('product.twig', [
        'product'    => Product::GetProduct($id),
        'categories' => Category::GetCategories(),
        'snippet'    => $snippet
    ]);
};
