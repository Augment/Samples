package com.augment.acmeshop.models;

import android.os.Parcel;
import android.os.Parcelable;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * Copyright © 2016-present Augment. All rights reserved.
 */

/**
 * This model is part of the Fake data model that we use to populate the app
 * Each Category has an unique id, a title and a picture, nothing special
 */
public class Category implements Parcelable {

    private int id;
    private String title;
    private String picture;

    Category(int id, String title, String picture) {
        this.id = id;
        this.title = title;
        this.picture = picture;
    }

    /**
     * This will give the full Category list,
     * in a real app it could be an asynchronous query over the network.
     * We are keeping thing simple in this example.
     *
     * @return List of Category
     */
    public static List<Category> getCategories() {
        ArrayList<Category> categories = new ArrayList<>();
        for (Map.Entry<Integer, Category> entry : Data.categories.entrySet()) {
            categories.add(entry.getValue());
        }
        return categories;
    }

    /**
     * This will give the Product list for a given Category
     * in a real app it could be an asynchronous query over the network.
     * We are keeping thing simple in this example.
     *
     * @param category the category you want the product of
     * @return List of Product for that Category
     */
    public static List<Product> getProducts(Category category) {
        ArrayList<Product> products = new ArrayList<>();
        for (Integer p : Data.products_categories.get(category.getId())) {
            products.add(Data.products.get(p));
        }
        return products;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    @SuppressWarnings("unused")
    public void setTitle(String title) {
        this.title = title;
    }

    public String getPicture() {
        return picture;
    }

    @SuppressWarnings("unused")
    public void setPicture(String picture) {
        this.picture = picture;
    }

    // Parcelable implementation

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeStringArray(new String[]{""+id, title, picture});
    }

    public static final Creator<Category> CREATOR = new Creator<Category>() {
        @Override
        public Category createFromParcel(Parcel source) {
            String[] data = new String[3];
            source.readStringArray(data);
            return new Category(Integer.parseInt(data[0]), data[1], data[2]);
        }

        @Override
        public Category[] newArray(int size) {
            return new Category[size];
        }
    };
}
