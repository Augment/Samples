package com.augment.acmeshop.helpers;

import android.content.Context;
import android.util.AttributeSet;

import androidx.cardview.widget.CardView;

/**
 * This is a extension of the RelativeLayout that will stay squared
 */
public class SquareLayout extends CardView {

    private double mScale = 1.0;

    public SquareLayout(Context context) {
        super(context);
    }

    public SquareLayout(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public SquareLayout(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
    }

    @SuppressWarnings("unused")
    public void setScale(double scale) {
        this.mScale = scale;
    }

    /**
     * This will take the smallest of both size to make the square
     *
     * @param widthMeasureSpec  width
     * @param heightMeasureSpec height
     */
    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {

        int width = MeasureSpec.getSize(widthMeasureSpec);
        int height = MeasureSpec.getSize(heightMeasureSpec);

        if (width > (int) ((mScale * height) + 0.5)) {
            width = (int) ((mScale * height) + 0.5);
        } else {
            height = (int) ((width / mScale) + 0.5);
        }

        super.onMeasure(
                MeasureSpec.makeMeasureSpec(width, MeasureSpec.EXACTLY),
                MeasureSpec.makeMeasureSpec(height, MeasureSpec.EXACTLY)
        );
    }
}
