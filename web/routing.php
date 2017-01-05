<?php

use Silex\Application;
use Symfony\Component\HttpFoundation\Request;

$app->get('/', require('../controllers/home.php'))
    ->bind('root');

$app->get('/category/{id}-{slug}', require('../controllers/category.php'))
    ->bind('category');

$app->get('/product/{id}-{slug}', require('../controllers/product.php'))
    ->bind('product');

$app->get('/fallback/{id}/{type}', require('../controllers/fallback.php'))
    ->bind('fallback');
