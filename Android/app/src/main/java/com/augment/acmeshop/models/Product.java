package com.augment.acmeshop.models;

import android.os.Parcel;
import android.os.Parcelable;

/**
 * Copyright © 2016-present Augment. All rights reserved.
 */

/**
 * This model is part of the Fake data model that we use to populate the app
 * Each Product is a basic object, fields are self explicits
 */
public class Product implements Parcelable {

    private int id;
    private String picture;
    private double price;
    private String details;
    private String ean;
    private String brand;
    private String name;

    Product(int id, String ean, String brand, String name, String picture, double price, String details) {
        this.id = id;
        this.ean = ean;
        this.picture = picture;
        this.price = price;
        this.details = details;
        this.brand = brand;
        this.name = name;
    }

    @Override
    public String toString() {
        return getTitle();
    }

    /**
     * Return the price in a human readable way.
     * It also add the currency symbol
     * @param currencySymbol String currency symbol, default to € if null
     * @return String human readable price
     */
    public String getFormattedPrice(String currencySymbol) {
        if (currencySymbol  == null) {
            currencySymbol = "€";
        }
        return "" + (Math.round(price * 100.0) / 100.0) + currencySymbol;
    }

    /**
     * The identifier is used to query Augment database,
     * here we are using the internal id and convert that to a string
     * @return String product identifier
     */
    public String getIdentifier() {
        return "" + id;
    }

    public String getTitle() {
        return brand + " " + name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getPicture() {
        return picture;
    }

    @SuppressWarnings("unused")
    public void setPicture(String picture) {
        this.picture = picture;
    }

    @SuppressWarnings("unused")
    public double getPrice() {
        return price;
    }

    @SuppressWarnings("unused")
    public void setPrice(double price) {
        this.price = price;
    }

    public String getDetails() {
        return details;
    }

    @SuppressWarnings("unused")
    public void setDetails(String details) {
        this.details = details;
    }

    public String getEan() {
        return ean;
    }

    @SuppressWarnings("unused")
    public void setEan(String ean) {
        this.ean = ean;
    }

    public String getBrand() {
        return brand;
    }

    @SuppressWarnings("unused")
    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    // Parcelable implementation

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeStringArray(new String[]{""+id, ean, brand, name, picture, ""+price, details});
    }

    public static final Creator<Product> CREATOR = new Creator<Product>() {
        @Override
        public Product createFromParcel(Parcel source) {
            String[] data = new String[7];
            source.readStringArray(data);
            return new Product(Integer.parseInt(data[0]), data[1], data[2], data[3], data[4], Float.parseFloat(data[5]), data[6]);
        }

        @Override
        public Product[] newArray(int size) {
            return new Product[size];
        }
    };
}
