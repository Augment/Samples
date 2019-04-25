package com.augment.acmeshop.activities;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.ar.augment.arplayer.sdk.AugmentSDK;
import com.ar.augment.arplayer.services.payloads.ProductQuery;
import com.augment.acmeshop.ACMEShop;
import com.augment.acmeshop.R;
import com.augment.acmeshop.models.Product;

import java.util.HashMap;
import java.util.Map;

import androidx.annotation.NonNull;
import androidx.appcompat.app.ActionBar;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import kotlin.Unit;

/**
 * The Product Activity
 * In this activity we show a detailed view of a product
 */
public class ProductActivity extends ACMEShopActivity implements View.OnClickListener {

    ImageView productImageView;
    TextView productTitleTextView;
    TextView productDetailTextView;
    TextView productPriceTextView;
    Button seeButton;

    // Current product from the previous activity
    Product product;

    AugmentSDK augmentPlayerSDK;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_product);

        productImageView = findViewById(R.id.productImageView);
        productTitleTextView = findViewById(R.id.productTitleTextView);
        productDetailTextView = findViewById(R.id.productDetailTextView);
        productPriceTextView = findViewById(R.id.productPriceTextView);
        seeButton = findViewById(R.id.seeButton);

        // Get the current product from the previous activity
        Bundle bundle = getIntent().getExtras();
        if (bundle != null) {
            product = bundle.getParcelable(ACMEShop.PARCELABLE_PRODUCT_TAG);
        }

        if (product == null) return;

        ActionBar actionBar = getSupportActionBar();
        if (actionBar != null) {
            actionBar.setTitle(product.getTitle());
        }

        augmentPlayerSDK = AugmentSDK.getInstance();

        seeButton.setEnabled(false);

        int res = getResources().getIdentifier(product.getPicture(), "drawable", getPackageName());
        productImageView.setImageResource(res);
        productTitleTextView.setText(product.getTitle());
        productDetailTextView.setText(product.getDetails());
        productPriceTextView.setText(product.getFormattedPrice(null));

        load();
    }

    /**
     * Load will get the product from Augment (or from the cache if available)
     */
    void load() {
        // Check if the product exists in Augment Product database
        ProductQuery query = new ProductQuery(
                product.getIdentifier(),
                product.getBrand(),
                product.getName(),
                product.getEan());

        augmentPlayerSDK.getProductsDataController().checkIfModelDoesExistForUserProductQuery(query, (product1, error) -> {
            if (error != null) {
                Log.e(ACMEShop.TAG, "Product " + product.toString() + " is not available.", error);
            } else if (product1 == null) {
                Log.d(ACMEShop.TAG, "Product " + product.toString() + " is not available.");
            } else seeButton.setEnabled(true);

            return Unit.INSTANCE;
        });
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.buyButton:
                ShowAlert("This is a demo app :)");
                break;

            case R.id.seeButton:
                checkForPermissionAndRun();
                break;
        }
    }

    /**
     * Augment Player need to access the Camera and file system before starting
     */
    private void checkForPermissionAndRun() {

        // Permission list we want to check for
        Map<String, String> permissions = new HashMap<>();
        permissions.put(Manifest.permission.READ_EXTERNAL_STORAGE, getString(R.string.permissions_READ_EXTERNAL_STORAGE));
        permissions.put(Manifest.permission.WRITE_EXTERNAL_STORAGE, getString(R.string.permissions_WRITE_EXTERNAL_STORAGE));
        permissions.put(Manifest.permission.CAMERA, getString(R.string.permissions_CAMERA));

        // We ask for permission one at a time, if it is granted we go to the next one
        // If it is not granted we ask for it and return, the callback will call `checkForPermissionAndRun` again right after
        // @see onRequestPermissionsResult
        for (final Map.Entry<String, String> entry : permissions.entrySet()) {
            if (ContextCompat.checkSelfPermission(this, entry.getKey()) != PackageManager.PERMISSION_GRANTED) {
                // Should we show an explanation?
                if (ActivityCompat.shouldShowRequestPermissionRationale(this, entry.getKey())) {
                    ShowAlert(entry.getValue(), () -> {
                        // Ask the user for that permission and return
                        // `checkForPermissionAndRun` will be called again in the permission delegate method
                        // @see onRequestPermissionsResult
                        ActivityCompat.requestPermissions(ProductActivity.this, new String[]{entry.getKey()}, 1);
                    });
                    return;
                }

                // Ask the user for that permission and return
                // `checkForPermissionAndRun` will be called again in the permission delegate method
                // @see onRequestPermissionsResult
                ActivityCompat.requestPermissions(this, new String[]{entry.getKey()}, 1);
                return;
            }
        }

        seeProduct();
    }

    /**
     * This is an implementation of the delegate from ActivityCompat.requestPermissions
     * we do not use the request code as we are treating all our permissions the same way
     * This method will call @see checkForPermissionAndRun if the permission is granted (recursion)
     *
     * @param requestCode  int not used in our case
     * @param permissions  String[] permissions list, one at a time in our implementation
     * @param grantResults int[] permissions result, one at a time in our implementation
     */
    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String permissions[], @NonNull int[] grantResults) {
        // If request is cancelled, the result arrays are empty.
        if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
            // If the permission is granted check for the other permissions (and so on)
            checkForPermissionAndRun();
        } else {
            ShowAlert("Augment needs that permission to show you Augmented reality");
        }
    }

    private void seeProduct() {
        Bundle bundle = new Bundle();
        bundle.putParcelable(ACMEShop.PARCELABLE_PRODUCT_TAG, product);
        Intent intent = new Intent(ProductActivity.this, AugmentActivity.class);
        intent.putExtras(bundle);
        startActivity(intent);
    }
}
