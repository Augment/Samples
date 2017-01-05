<?php
/**
 * This page use the Silex micro framework,
 * see the doc here: http://silex.sensiolabs.org/
 * it is realy easy to get started with
 */
require_once __DIR__ . '/../vendor/autoload.php';
require_once __DIR__ . '/../config.php';
require_once __DIR__ . '/../common.php';

use Silex\Application;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;

class App extends Application {
    use Silex\Application\UrlGeneratorTrait;
    use Silex\Application\SecurityTrait;
    use Silex\Application\FormTrait;
}

$app = new App();
$app['debug']  = $config->get('debug', false);
$app['locale'] = 'en';

// Template engine configuration (optional, you can return HTML instead)
$app
    ->register(new Silex\Provider\TwigServiceProvider(), [
    'twig.path' => __DIR__ . '/../views',
]);

// Routing
require_once __DIR__ . '/../routing.php';

// Error handling
$app
    ->error(function (\Exception $e, Request $request, $code) {
    switch ($code) {
        case 404: return new Response('The requested page could not be found.');
        default:  return new Response($e->getMessage());
    }
});

$app->run();
