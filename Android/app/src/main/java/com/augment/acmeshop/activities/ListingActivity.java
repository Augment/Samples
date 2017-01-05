package com.augment.acmeshop.activities;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.ActionBar;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.view.GestureDetector;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.augment.acmeshop.ACMEShop;
import com.augment.acmeshop.models.Category;
import com.augment.acmeshop.models.Product;
import com.augment.acmeshop.R;

import java.util.ArrayList;
import java.util.List;

public class ListingActivity extends ACMEShopActivity {

    RecyclerView recyclerView;

    Category currentCategory;

    RecyclerView.LayoutManager layoutManager;
    GestureDetector gestureDetector;

    ProductAdapter adapter = new ProductAdapter();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_listing);

        recyclerView = (RecyclerView) findViewById(R.id.recyclerView);

        Bundle bundle = getIntent().getExtras();
        if (bundle != null) {
            currentCategory = bundle.getParcelable(ACMEShop.PARCELABLE_CATEGORY_TAG);
        }

        if (currentCategory == null) return;

        layoutManager = new LinearLayoutManager(this);
        gestureDetector = new GestureDetector(this, new GestureDetector.SimpleOnGestureListener() {
            @Override public boolean onSingleTapUp(MotionEvent e) {
                return true;
            }
        });

        recyclerView.setLayoutManager(layoutManager);
        recyclerView.setHasFixedSize(true);
        recyclerView.setAdapter(adapter);
        recyclerView.addOnItemTouchListener(onItemTouchListener);

        ActionBar actionBar = getSupportActionBar();
        if (actionBar != null) {
            actionBar.setTitle(currentCategory.getTitle());
        }

        load();
    }

    protected void load() {
        if (currentCategory == null) return;

        adapter.setProducts(Category.getProducts(currentCategory));
        adapter.notifyDataSetChanged();
    }

    protected RecyclerView.OnItemTouchListener onItemTouchListener = new RecyclerView.OnItemTouchListener() {

        @Override
        public boolean onInterceptTouchEvent(RecyclerView rv, MotionEvent e) {
            View child = rv.findChildViewUnder(e.getX(), e.getY());
            if (child != null && gestureDetector.onTouchEvent(e)) {
                int position = rv.getChildAdapterPosition(child);
                final Product product = adapter.getItem(position);
                Bundle bundle = new Bundle();
                bundle.putParcelable(ACMEShop.PARCELABLE_PRODUCT_TAG, product);
                Intent intent = new Intent(ListingActivity.this, ProductActivity.class);
                intent.putExtras(bundle);
                startActivity(intent);
                return true;
            }

            return false;
        }

        @Override
        public void onTouchEvent(RecyclerView rv, MotionEvent e) { }

        @Override
        public void onRequestDisallowInterceptTouchEvent(boolean disallowIntercept) { }
    };

    class ProductAdapter extends RecyclerView.Adapter<ViewHolder> {

        List<Product> products = new ArrayList<>();

        void setProducts(List<Product> products) {
            this.products = products;
        }

        Product getItem(int position) {
            return products.get(position);
        }

        @Override
        public int getItemCount() {
            return products.size();
        }

        @Override
        public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
            View view = LayoutInflater.from(parent.getContext())
                    .inflate(R.layout.grid_item_product, parent, false);
            ViewHolder holder = new ViewHolder(view);
            holder.productImageView     = (ImageView) view.findViewById(R.id.productImageView);
            holder.productTitleTextView = (TextView) view.findViewById(R.id.productTitleTextView);
            holder.productPriceTextView = (TextView) view.findViewById(R.id.productPriceTextView);
            return holder;
        }

        @Override
        public void onBindViewHolder(ViewHolder holder, int position) {
            Product product = products.get(position);

            int res = getResources().getIdentifier(product.getPicture(), "drawable", getPackageName());

            holder.productImageView.setImageResource(res);
            holder.productTitleTextView.setText(product.getTitle());
            holder.productPriceTextView.setText(product.getFormattedPrice(null));
        }
    }

    public static class ViewHolder extends RecyclerView.ViewHolder {

        ImageView productImageView;
        TextView productTitleTextView;
        TextView productPriceTextView;

        ViewHolder(View view) {
            super(view);
        }
    }
}
