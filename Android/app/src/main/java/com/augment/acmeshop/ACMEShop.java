package com.augment.acmeshop;

import android.app.Application;

import com.augment.acmeshop.models.Data;

/**
 * Copyright © 2016-present Augment. All rights reserved.
 */

/**
 * Main entry point for the App
 * Please change the AppId / AppSecret and Vuforia keys to match yours
 */
public class ACMEShop extends Application {

    public static String TAG = "ACME-Shop";
    public static String PARCELABLE_CATEGORY_TAG = "com.augment.acme-shop.category";
    public static String PARCELABLE_PRODUCT_TAG  = "com.augment.acme-shop.product";

    public static class Augment {
        public static String AppId     = "357fee36746668573ceb2f5957c4869ee1a62a112639bac9b0fae43c7c431692";
        public static String AppSecret = "80ae1420e164e0440d5329067bcdd953e9fa6c63b75c001c06d169a4f11268c5";
        public static String Vuforia   = "ATQqCM7/////AAAAGXLs+GRi0UwXh0X+/qQL49dbZGym8kKo+iRtgC95tbJoCWjXXZihDl5pzxoca2JxLcYxBJ2pIeIE4dNcK0etMeb1746L7lq6vSFen43cS7P1P/HXjwHtUouV5Xus2U0F7WHUTKuO629jKFO13fBQczuY52UJcSEhsu9jHPMaupo5CpqQT3TFTQjlhzHhVXiVMEqq7RI+Edwh8TCSfGAbNRdbIELTfK+8YDYqwEHDbp62mFrs68YnCEQZDrpcLyC8WzFCVZtnUq3Cj3YBUfQ6gNnENYiuLf06gAAF/FcaF65VYveGRBbp3hpkqolX28bxPiUYNVknCSFXICPHciVntxF+rcHW5rrX7Cg/IVFGdNRF";
    }

    @Override
    public void onCreate() {
        super.onCreate();
        Data.init();
    }
}
