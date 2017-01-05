<?php

use Silex\Application;
use Symfony\Component\HttpFoundation\Request;

return function(Application $app, Request $request, $id, $type) use ($config) {
    if ($type != "mobile") {
        $type = "desktop";
    }

    $snippet  = $config->get('snippet');
    $snippet .= 'augment.authenticate({id: "' . $config->get('augment')['id'] . '", key: "' . $config->get('augment')['key'] . '"});';

    return $app['twig']->render('fallback.twig', [
        'product' => Product::GetProduct($id),
        'type'    => $type,
        'snippet' => $snippet
    ]);
};
