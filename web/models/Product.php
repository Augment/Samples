<?php

class Product {

    private $id;
    private $title;
    private $picture;
    private $price;
    private $details;
    private $ean;
    private $brand;
    private $name;

    public static function GetProduct($productId) {
        global $data;
        return $data->products[$productId];
    }

    public function __construct($id, $ean, $brand, $name, $picture, $price, $details) {
        $this->id = $id;
        $this->ean = $ean;
        $this->brand = $brand;
        $this->name = $name;
        $this->picture = $picture;
        $this->price = $price;
        $this->details = $details;
        // Calculated
        $this->title = $brand . " " . $name;
    }

    public function getFormatedPrice() {
        return str_replace('.', ',', "" . (round($this->price * 100.0) / 100.0) . " €");
    }

    public function getSlug() {
        return slug($this->title);
    }

    public function getId() {
        return $this->id;
    }

    public function setId($id) {
        $this->id = $id;
    }

    public function getIdentifier() {
        return $this->id;
    }

    public function getName() {
        return $this->name;
    }

    public function setName($name) {
        $this->name = $name;
    }

    public function getBrand() {
        return $this->brand;
    }

    public function setBrand($brand) {
        $this->brand = $brand;
    }

    public function getTitle() {
        return $this->title;
    }

    public function setTitle($title) {
        $this->title = $title;
    }

    public function getPicture() {
        return $this->picture;
    }

    public function setPicture($picture) {
        $this->picture = $picture;
    }

    public function getPrice() {
        return $this->price;
    }

    public function setPrice($price) {
        $this->price = $price;
    }

    public function getDetails() {
        return $this->details;
    }

    public function getDetailsTruncated($length) {
        if (strlen($this->details) <= $length) {
            return $this->details;
        }

        return substr($this->details, 0, $length) . "...";
    }

    public function setDetails($details) {
        $this->details = $details;
    }

    public function getEan() {
        return $this->ean;
    }

    public function setEan($ean) {
        $this->ean = $ean;
    }
}
