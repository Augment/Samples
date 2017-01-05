<?php

class Category {

    private $id;
    private $title;
    private $picture;

    public static function GetCategory($categoryId) {
        global $data;
        return $data->categories[$categoryId];
    }

    public static function GetCategories() {
        global $data;
        $categories = [];
        foreach ($data->categories as $key => $value) {
            $categories[] = $value;
        }
        return $categories;
    }

    public static function GetProducts($categoryId) {
        global $data;
        $products = [];
        foreach ($data->products_categories[$categoryId] as $key => $value) {
            $products[] = $data->products[$value];
        }
        return $products;
    }

    public function __construct($id, $title, $picture) {
        $this->id = $id;
        $this->title = $title;
        $this->picture = $picture;
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
}
