package com.augment.acmeshop.activities;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.GestureDetector;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.augment.acmeshop.ACMEShop;
import com.augment.acmeshop.models.Category;
import com.augment.acmeshop.R;

import java.util.ArrayList;
import java.util.List;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

public class CategoryActivity extends ACMEShopActivity {

    RecyclerView recyclerView;

    RecyclerView.LayoutManager layoutManager;
    GestureDetector gestureDetector;

    CategoryAdapter adapter = new CategoryAdapter();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_category);

        recyclerView = findViewById(R.id.recyclerView);

        layoutManager = new GridLayoutManager(this, 2);
        gestureDetector = new GestureDetector(this, new GestureDetector.SimpleOnGestureListener() {
            @Override public boolean onSingleTapUp(MotionEvent e) {
                return true;
            }
        });

        recyclerView.setLayoutManager(layoutManager);
        recyclerView.setHasFixedSize(true);
        recyclerView.setAdapter(adapter);
        recyclerView.addOnItemTouchListener(onItemTouchListener);

        load();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.menu_category, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.aboutAction:
                LayoutInflater inflater = getLayoutInflater();
                @SuppressLint("InflateParams")
                View view = inflater.inflate(R.layout.dialog_about, null);
                ShowCustomDialog(view, "OK", null);
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    protected void load() {
        adapter.setCategories(Category.getCategories());
        adapter.notifyDataSetChanged();
    }

    protected RecyclerView.OnItemTouchListener onItemTouchListener = new RecyclerView.OnItemTouchListener() {

        @Override
        public boolean onInterceptTouchEvent(RecyclerView rv, MotionEvent e) {
            View child = rv.findChildViewUnder(e.getX(), e.getY());
            if (child != null && gestureDetector.onTouchEvent(e)) {
                int position = rv.getChildAdapterPosition(child);
                final Category category = adapter.getItem(position);
                Bundle bundle = new Bundle();
                bundle.putParcelable(ACMEShop.PARCELABLE_CATEGORY_TAG, category);
                Intent intent = new Intent(CategoryActivity.this, ListingActivity.class);
                intent.putExtras(bundle);
                startActivity(intent);
                return true;
            }

            return false;
        }

        @Override
        public void onTouchEvent(@NonNull RecyclerView rv, @NonNull MotionEvent e) {

        }

        @Override
        public void onRequestDisallowInterceptTouchEvent(boolean disallowIntercept) {

        }
    };

    class CategoryAdapter extends RecyclerView.Adapter<ViewHolder> {

        List<Category> categories = new ArrayList<>();

        void setCategories(List<Category> categories) {
            this.categories = categories;
        }

        Category getItem(int position) {
            return categories.get(position);
        }

        @Override
        public int getItemCount() {
            return categories.size();
        }

        @NonNull
        @Override
        public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            View view = LayoutInflater.from(parent.getContext())
                    .inflate(R.layout.grid_item_category, parent, false);
            ViewHolder holder = new ViewHolder(view);
            holder.categoryImageView     = view.findViewById(R.id.categoryImageView);
            holder.categoryTitleTextView = view.findViewById(R.id.categoryTitleTextView);
            return holder;
        }

        @Override
        public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
            final Category category = categories.get(position);

            int res = getResources().getIdentifier(category.getPicture(), "drawable", getPackageName());
            holder.categoryImageView.setImageResource(res);
            holder.categoryTitleTextView.setText(category.getTitle());
        }
    }

    public static class ViewHolder extends RecyclerView.ViewHolder {
        ImageView categoryImageView;
        TextView categoryTitleTextView;

        ViewHolder(View itemView) {
            super(itemView);
        }
    }
}
