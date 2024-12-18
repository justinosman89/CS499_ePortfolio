package com.personal.inventoryapp;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

/**
 * Database helper class for managing SQLite database operations.
 */
public class DatabaseHelper extends SQLiteOpenHelper {

    public static final String DATABASE_NAME = "inventory.db";
    public static final int DATABASE_VERSION = 1;

    public static final String TABLE_INVENTORY = "inventory";
    public static final String COLUMN_ITEM_NAME = "item_name";
    public static final String COLUMN_ITEM_QUANTITY = "item_quantity";

    public DatabaseHelper(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("CREATE TABLE " + TABLE_INVENTORY + " (" +
                COLUMN_ITEM_NAME + " TEXT PRIMARY KEY, " +
                COLUMN_ITEM_QUANTITY + " INTEGER)");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_INVENTORY);
        onCreate(db);
    }
}
