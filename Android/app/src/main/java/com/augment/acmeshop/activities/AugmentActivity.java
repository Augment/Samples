package com.augment.acmeshop.activities;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.opengl.GLSurfaceView;
import android.os.AsyncTask;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.os.Bundle;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.support.v7.app.ActionBar;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;

import com.ar.augment.arplayer.AugmentPlayer;
import com.ar.augment.arplayer.AugmentPlayerException;
import com.ar.augment.arplayer.AugmentPlayerSDK;
import com.ar.augment.arplayer.InitializationListener;
import com.ar.augment.arplayer.LoaderCallback;
import com.ar.augment.arplayer.ProductDataController;
import com.ar.augment.arplayer.ProductQuery;
import com.ar.augment.arplayer.ScreenshotTakerCallback;
import com.ar.augment.arplayer.WebserviceException;
import com.augment.acmeshop.ACMEShop;
import com.augment.acmeshop.models.Product;
import com.augment.acmeshop.R;

import java.io.File;

/**
 * The Augmented Reality Activity
 * In this activity we use all the Augment SDK parts
 */
public class AugmentActivity extends ACMEShopActivity implements View.OnClickListener {

    View loadingContainer;
    TextView loadingTextView;
    GLSurfaceView augmentView;

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
    AugmentPlayerSDK augmentPlayerSDK;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_augment);

        loadingContainer  = findViewById(R.id.loadingContainer);
        loadingTextView   = (TextView) findViewById(R.id.loadingTextView);
        tutorialContainer = findViewById(R.id.tutorialContainer);
        augmentView       = (GLSurfaceView) findViewById(R.id.augmentView);
        viewPager         = (ViewPager) findViewById(R.id.viewpager);
        pagerTextView     = (TextView) findViewById(R.id.pagerTextView);
        iGotItButton      = (Button) findViewById(R.id.iGotItButton);
        screenshotButton  = (ImageButton) findViewById(R.id.screenshotButton);

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
        viewPager.setAdapter(new PagerAdapter() {
            @Override
            public Object instantiateItem(ViewGroup container, int position) {
                LayoutInflater inflater = LayoutInflater.from(AugmentActivity.this);
                int layoutId = R.layout.tutorial_screen_01;
                switch (position) {
                    case 1: layoutId = R.layout.tutorial_screen_02; break;
                    case 2: layoutId = R.layout.tutorial_screen_03; break;
                    case 3: layoutId = R.layout.tutorial_screen_04; break;
                }
                ViewGroup layout = (ViewGroup) inflater.inflate(layoutId, container, false);
                container.addView(layout);
                return layout;
            }

            @Override
            public void destroyItem(ViewGroup container, int position, Object object) {
                container.removeView((View) object);
            }

            @Override
            public int getCount() {
                return 4;
            }

            @Override
            public boolean isViewFromObject(View view, Object object) {
                return view == object;
            }
        });

        viewPager.addOnPageChangeListener(new ViewPager.OnPageChangeListener() {
            @Override
            public void onPageScrolled(int position, float positionOffset, int positionOffsetPixels) { }

            @Override
            public void onPageSelected(int position) {
                iGotItButton.setVisibility(View.GONE);
                switch (position) {
                    case 0: pagerTextView.setText(R.string.step_1_4); break;
                    case 1: pagerTextView.setText(R.string.step_2_4); break;
                    case 2: pagerTextView.setText(R.string.step_3_4); break;
                    case 3: pagerTextView.setText(R.string.step_4_4);
                        iGotItButton.setVisibility(View.VISIBLE);
                        break;
                }
            }

            @Override
            public void onPageScrollStateChanged(int state) { }
        });

        initAugmentPlayer();
    }

    // Theses are mandatory overwrites of lifecycle activity method
    // to keep the AR view working nicely

    @Override
    protected void onResume() {
        super.onResume();
        if (augmentPlayerSDK != null) {
            try {
                augmentPlayerSDK.getAugmentPlayer().resume();
            } catch (AugmentPlayerException e) {
                Log.e(ACMEShop.TAG, "EXCEPTION: " + e.getLocalizedMessage(), e);
            }
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        if (augmentPlayerSDK != null) {
            try {
                augmentPlayerSDK.getAugmentPlayer().pause();
            } catch (AugmentPlayerException e) {
                Log.e(ACMEShop.TAG, "EXCEPTION: " + e.getLocalizedMessage(), e);
            }
        }
    }

    @Override
    protected void onDestroy() {
        if (augmentPlayerSDK != null) {
            try {
                augmentPlayerSDK.getAugmentPlayer().stop();
            } catch (AugmentPlayerException e) {
                Log.e(ACMEShop.TAG, "EXCEPTION: " + e.getLocalizedMessage(), e);
            }
        }
        super.onDestroy();
    }

    /**
     * Init the Augment Player with our AppKeys and then init the AR view itself
     */
    private void initAugmentPlayer() {
        // Init the Augment Player
        augmentPlayerSDK = new AugmentPlayerSDK(this.getApplicationContext(), ACMEShop.Augment.AppId, ACMEShop.Augment.AppSecret, ACMEShop.Augment.Vuforia);

        // Start the AR view and get a callback when the view is ready
        final AugmentPlayer augmentPlayer = augmentPlayerSDK.getAugmentPlayer();
        augmentPlayer.initAR(this, augmentView, new InitializationListener() {

            @Override
            public void onInitARDone(GLSurfaceView glSurfaceView, AugmentPlayerException e) {
                // Check if there is no error
                if (e != null) {
                    Log.e(ACMEShop.TAG, e.getLocalizedMessage(), e);
                    hideLoading();
                    ShowAlert("Error: " + e.getLocalizedMessage());
                    return;
                }

                // For now it is the responsibility of the developer to load this asynchronously, this will evolve in the future
                (new AsyncTask<Void, Void, Void>() {
                    @Override
                    protected Void doInBackground(Void... voids) {
                        try {
                            augmentPlayer.start();
                            augmentPlayer.resume();
                        } catch (AugmentPlayerException e) {
                            Log.e(ACMEShop.TAG, e.getLocalizedMessage(), e);
                            hideLoading();
                            ShowAlert("Error: " + e.getLocalizedMessage());
                        }
                        return null;
                    }
                }).execute();

                // We get the Augment Product and add it to this AR view
                queryAndAddProductToAugmentPlayer();
            }
        });
    }

    void queryAndAddProductToAugmentPlayer() {
        ProductQuery query = new ProductQuery.Builder(
                product.getIdentifier(),
                product.getBrand(),
                product.getName()
        ).setEan(product.getEan()).build();

        augmentPlayerSDK.getProductDataController().checkIfModelDoesExistForUserProductQuery(query, new ProductDataController.ProductQueryListener() {
            @Override
            public void onResponse(@Nullable com.ar.augment.arplayer.Product augmentProduct) {
                if (augmentProduct == null) {
                    Log.d(ACMEShop.TAG, "Product " + product.toString() + " is not available.");
                    hideLoading();
                    ShowAlert("This product is not available yet");
                    return;
                }

                addProductToAugmentedReality(augmentProduct);
            }

            @Override
            public void onError(WebserviceException error) {
                Log.e(ACMEShop.TAG, "Product " + product.toString() + " is not available.", error);
                hideLoading();
                ShowAlert("This product is not available yet");
            }
        });
    }

    void addProductToAugmentedReality(@NonNull com.ar.augment.arplayer.Product product) {
        augmentPlayerSDK.addModel3DToAugmentPlayerWithProduct(product, new LoaderCallback() {
            @Override
            public void onSuccess(String modelIdentifier) {
                hideLoading();
                screenshotButton.setEnabled(true);
            }

            @Override
            public void onPreparingModel() {
                // Show loading (already present and shown)
            }

            @Override
            public void onError(WebserviceException error) {
                Log.e(ACMEShop.TAG, "Error", error);
                hideLoading();
                ShowAlert("Error: " + error.getLocalizedMessage());
            }

            @Override
            public void onDownloadProgressUpdate(final Long aLong) {
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        loadingTextView.setText("Loading " + Math.min(100, aLong.intValue()) + "%");
                    }
                });
            }
        });
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
                augmentPlayerSDK.getAugmentPlayer().takeScreenshot(new ScreenshotTakerCallback() {
                    @Override
                    public void onScreenshotSaved(final File file) {
                        runOnUiThread(new Runnable() {
                                @Override
                                public void run() {
                                screenshotButton.setEnabled(true);
                                hideLoading();
                                LayoutInflater inflater = getLayoutInflater();
                                @SuppressLint("InflateParams")
                                View view = inflater.inflate(R.layout.dialog_preview_share, null);
                                ImageView imageView = (ImageView) view.findViewById(R.id.previewImageView);
                                imageView.setImageBitmap(BitmapFactory.decodeFile(file.getAbsolutePath()));
                                ShowCustomDialog(view, getString(R.string.share_action), new Runnable() {
                                    @Override
                                    public void run() {
                                        shareAction(file);
                                    }
                                });
                            }
                        });
                    }

                    @Override
                    public void onError(final Throwable throwable) {
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                screenshotButton.setEnabled(true);
                                hideLoading();
                                ShowAlert(throwable.getLocalizedMessage());
                            }
                        });
                    }
                });

            case R.id.centerAction:
                if (augmentPlayerSDK == null) return;
                // TODO this does not exist for now
                //augmentPlayerSDK.getAugmentPlayer()...
                break;

            case R.id.iGotItButton:
                tutorialContainer.setVisibility(View.GONE);
                viewPager.setCurrentItem(0);
                break;
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
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                loadingContainer.setVisibility(View.GONE);
            }
        });
    }
}
