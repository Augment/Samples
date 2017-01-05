<?php

require_once 'models/Category.php';
require_once 'models/Product.php';
require_once 'models/Data.php';

function slug($string) {
    return strtolower(
        preg_replace('/[^a-z0-9_-]/i', '',
        preg_replace('/\s+/', '_',
        $string
    )));
}
