package com.augment.acmeshop.activities;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;

import com.ar.augment.arplayer.sdk.AugmentPlayer;
import com.ar.augment.arplayer.sdk.AugmentPlayerFragment;
import com.ar.augment.arplayer.sdk.AugmentSDK;
import com.ar.augment.arplayer.services.payloads.ProductQuery;
import com.augment.acmeshop.ACMEShop;
import com.augment.acmeshop.R;
import com.augment.acmeshop.models.Product;

import java.io.File;

import androidx.annotation.NonNull;
import androidx.appcompat.app.ActionBar;
import androidx.viewpager.widget.PagerAdapter;
import androidx.viewpager.widget.ViewPager;

import kotlin.Unit;

/**
 * The Augmented Reality Activity
 * In this activity we use all the Augment SDK parts
 */
public class AugmentActivity extends ACMEShopActivity implements View.OnClickListener {

    View loadingContainer;
    TextView loadingTextView;
    AugmentPlayer augmentPlayer;

    // Please see Augment UX recommendations about how to onboard your users
    View tutorialContainer;
    ViewPager viewPager;
    TextView pagerTextView;
    Button iGotItButton;
    ImageButton screenshotButton;

    /**
     * Current product from the previous activity
     */
    Product product;

    /**
     * The Augment Player instance
     */
    AugmentSDK augmentPlayerSDK;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_augment);

        augmentPlayerSDK = AugmentSDK.getInstance();

        loadingContainer = findViewById(R.id.loadingContainer);
        loadingTextView = findViewById(R.id.loadingTextView);
        augmentPlayer = ((AugmentPlayerFragment) getSupportFragmentManager().findFragmentById(R.id.augment_player_fragment)).getAugmentPlayer();
//        tutorialContainer = findViewById(R.id.tutorialContainer);
//        viewPager = findViewById(R.id.viewpager);
//        pagerTextView = findViewById(R.id.pagerTextView);
//        iGotItButton = findViewById(R.id.iGotItButton);
        screenshotButton = findViewById(R.id.screenshotButton);

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

        screenshotButton.setEnabled(false);

        // We are using a basic page adapter to show a multi-page tutorial
//        viewPager.setAdapter(new PagerAdapter() {
//            @Override
//            public Object instantiateItem(ViewGroup container, int position) {
//                LayoutInflater inflater = LayoutInflater.from(AugmentActivity.this);
//                int layoutId = R.layout.tutorial_screen_01;
//                switch (position) {
//                    case 1:
//                        layoutId = R.layout.tutorial_screen_02;
//                        break;
//                    case 2:
//                        layoutId = R.layout.tutorial_screen_03;
//                        break;
//                    case 3:
//                        layoutId = R.layout.tutorial_screen_04;
//                        break;
//                }
//                ViewGroup layout = (ViewGroup) inflater.inflate(layoutId, container, false);
//                container.addView(layout);
//                return layout;
//            }
//
//            @Override
//            public void destroyItem(ViewGroup container, int position, Object object) {
//                container.removeView((View) object);
//            }
//
//            @Override
//            public int getCount() {
//                return 4;
//            }
//
//            @Override
//            public boolean isViewFromObject(View view, Object object) {
//                return view == object;
//            }
//        });
//
//        viewPager.addOnPageChangeListener(new ViewPager.OnPageChangeListener() {
//            @Override
//            public void onPageScrolled(int position, float positionOffset, int positionOffsetPixels) {
//            }
//
//            @Override
//            public void onPageSelected(int position) {
//                iGotItButton.setVisibility(View.GONE);
//                switch (position) {
//                    case 0:
//                        pagerTextView.setText(R.string.step_1_4);
//                        break;
//                    case 1:
//                        pagerTextView.setText(R.string.step_2_4);
//                        break;
//                    case 2:
//                        pagerTextView.setText(R.string.step_3_4);
//                        break;
//                    case 3:
//                        pagerTextView.setText(R.string.step_4_4);
//                        iGotItButton.setVisibility(View.VISIBLE);
//                        break;
//                }
//            }
//
//            @Override
//            public void onPageScrollStateChanged(int state) {
//            }
//        });
        initAugmentPlayer();
    }

    @Override
    protected void onDestroy() {
//        if (augmentPlayerSDK != null) {
//            try {
//                augmentPlayerSDK.getAugmentPlayer().stop();
//            } catch (AugmentPlayerException e) {
//                Log.e(ACMEShop.TAG, "EXCEPTION: " + e.getLocalizedMessage(), e);
//            }
//        }
        super.onDestroy();
    }

    /**
     * Init the Augment Player with our AppKeys and then init the AR view itself
     */
    private void initAugmentPlayer() {
        augmentPlayer.getViews().createLiveViewer(() -> {
            queryAndAddProductToAugmentPlayer();
            return Unit.INSTANCE;
        });

        // Start the AR view and get a callback when the view is ready
//        final AugmentPlayer augmentPlayer = augmentPlayerSDK.getAugmentPlayer();
//        augmentPlayer.initAR(this, augmentPlayer, new InitializationListener() {
//
//            @Override
//            public void onInitARDone(GLSurfaceView glSurfaceView, AugmentPlayerException e) {
//                // Check if there is no error
//                if (e != null) {
//                    Log.e(ACMEShop.TAG, e.getLocalizedMessage(), e);
//                    hideLoading();
//                    ShowAlert("Error: " + e.getLocalizedMessage());
//                    return;
//                }
//
//                // For now it is the responsibility of the developer to load this asynchronously, this will evolve in the future
//                (new AsyncTask<Void, Void, Void>() {
//                    @Override
//                    protected Void doInBackground(Void... voids) {
//                        try {
//                            augmentPlayer.start();
//                            augmentPlayer.resume();
//                        } catch (AugmentPlayerException e) {
//                            Log.e(ACMEShop.TAG, e.getLocalizedMessage(), e);
//                            hideLoading();
//                            ShowAlert("Error: " + e.getLocalizedMessage());
//                        }
//                        return null;
//                    }
//                }).execute();
//
//                // We get the Augment Product and add it to this AR view
//                queryAndAddProductToAugmentPlayer();
//            }
//        });
    }

    void queryAndAddProductToAugmentPlayer() {
        ProductQuery query = new ProductQuery(
                product.getIdentifier(),
                product.getBrand(),
                product.getName(), product.getEan());


        augmentPlayerSDK.getProductsDataController().checkIfModelDoesExistForUserProductQuery(query, (productReceived, error) -> {
            if (error != null) {
                Log.e(ACMEShop.TAG, "Product " + product.toString() + " is not available.", error);
                hideLoading();
                ShowAlert("This product is not available yet");

            } else if (productReceived == null) {
                Log.e(ACMEShop.TAG, "Product " + product.toString() + " is not available.");
                hideLoading();
                ShowAlert("This product is not available yet");
            } else addProductToAugmentedReality(productReceived);
            return Unit.INSTANCE;
        });
    }

    void addProductToAugmentedReality(@NonNull com.ar.augment.arplayer.model.Product product) {
        augmentPlayer.getContent().add(product.getModel3D(), (model3DInstance, error) -> {
            if (error != null) {
                Log.e(ACMEShop.TAG, "Error", error);
                hideLoading();
                ShowAlert("Error: " + error.getLocalizedMessage());
            } else {
                hideLoading();
                screenshotButton.setEnabled(true);
            }
            return Unit.INSTANCE;
        });
//            public void onDownloadProgressUpdate(final Long aLong) {
//                runOnUiThread(new Runnable() {
//                    @Override
//                    public void run() {
//                        loadingTextView.setText("Loading " + Math.min(100, aLong.intValue()) + "%");
//                    }
//                });
//            }
    }


    // Actions

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.helpButton:
                tutorialContainer.setVisibility(View.VISIBLE);
                break;

            case R.id.screenshotButton:
                screenshotButton.setEnabled(false);
                loadingTextView.setText(getString(R.string.screenshot_loading));
                loadingContainer.setVisibility(View.VISIBLE);

                if (augmentPlayerSDK == null) return;

                augmentPlayer.takeScreenshot((b, o) -> {
//                    @Override
//                    public void onScreenshotSaved(final File file) {
//                        runOnUiThread(new Runnable() {
//                            @Override
//                            public void run() {
//                                screenshotButton.setEnabled(true);
//                                hideLoading();
//                                LayoutInflater inflater = getLayoutInflater();
//                                @SuppressLint("InflateParams")
//                                View view = inflater.inflate(R.layout.dialog_preview_share, null);
//                                ImageView imageView = (ImageView) view.findViewById(R.id.previewImageView);
//                                imageView.setImageBitmap(BitmapFactory.decodeFile(file.getAbsolutePath()));
//                                ShowCustomDialog(view, getString(R.string.share_action), new Runnable() {
//                                    @Override
//                                    public void run() {
//                                        shareAction(file);
//                                    }
//                                });
//                            }
//                        });
//                    }
//
//                    @Override
//                    public void onError(final Throwable throwable) {
//                        runOnUiThread(new Runnable() {
//                            @Override
//                            public void run() {
//                                screenshotButton.setEnabled(true);
//                                hideLoading();
//                                ShowAlert(throwable.getLocalizedMessage());
//                            }
//                        });
//                    }
                    return Unit.INSTANCE;
                });

            case R.id.centerAction:
                if (augmentPlayerSDK == null) return;
                augmentPlayer.recenterProducts();
                break;

//            case R.id.iGotItButton:
//                tutorialContainer.setVisibility(View.GONE);
//                viewPager.setCurrentItem(0);
//                break;
        }
    }

    public void shareAction(File image) {
        Intent shareIntent = new Intent();
        shareIntent.setAction(Intent.ACTION_SEND);

        Uri imageUri = Uri.fromFile(image);
        shareIntent.setType("image/*");
        shareIntent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
        shareIntent.putExtra(Intent.EXTRA_STREAM, imageUri);

        startActivity(Intent.createChooser(shareIntent, getString(R.string.screenshot_success)));
    }

    // Helpers

    void hideLoading() {
        runOnUiThread(() -> loadingContainer.setVisibility(View.GONE));
    }
}

