<?php

require_once __DIR__ . '/vendor/autoload.php';

use Symfony\Component\HttpFoundation\ParameterBag;

class Config extends ParameterBag {}
$config = new Config();
$config->set('debug', false);
$config->set('snippet', /* Copy/past from https://cdn.augment.com/web-sdk/0.2/snippet.js */ '
// Augment SDK v0.2
!function(n,e){var i,t="augment",o={q:[]},c="authenticate initDeeplinkForAppPath initDeeplinkForModel3d initDeeplinkForModel3ds initDeeplinkForProduct initDeeplinkForProducts initDeeplinkOnFallbackPage".split(" ");if(!n[t]||!n[t].q){for(var l=0;l<c.length;l++)!function(n){o[n]=function(){o.q.push([n,arguments])}}(c[l]);i=e.createElement("script"),i.async=!0,i.src="//cdn.augment.com/web-sdk/0.2/augment.js",e.documentElement.appendChild(i),n[t]=o}}(window,document);
');
$config->set('augment', [
    'id'  => 'AUGMENT_APP_ID',
    'key' => 'AUGMENT_APP_KEY',
]);

