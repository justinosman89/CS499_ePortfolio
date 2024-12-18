package com.personal.inventoryapp;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import java.util.HashMap;

/**
 * Repository class to handle all database operations for inventory management.
 */
public class Repository {
    private final DatabaseHelper dbHelper;

    public Repository(Context context) {
        dbHelper = new DatabaseHelper(context);
    }

    public long addItem(String name, int quantity) {
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put(DatabaseHelper.COLUMN_ITEM_NAME, name);
        values.put(DatabaseHelper.COLUMN_ITEM_QUANTITY, quantity);
        return db.insert(DatabaseHelper.TABLE_INVENTORY, null, values);
    }

    public int removeItem(String name) {
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        return db.delete(DatabaseHelper.TABLE_INVENTORY, DatabaseHelper.COLUMN_ITEM_NAME + "=?", new String[]{name});
    }

    public int updateItem(String name, int quantity) {
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put(DatabaseHelper.COLUMN_ITEM_QUANTITY, quantity);
        return db.update(DatabaseHelper.TABLE_INVENTORY, values, DatabaseHelper.COLUMN_ITEM_NAME + "=?", new String[]{name});
    }

    public HashMap<String, Integer> getAllItems() {
        SQLiteDatabase db = dbHelper.getReadableDatabase();
        HashMap<String, Integer> items = new HashMap<>();
        Cursor cursor = db.query(DatabaseHelper.TABLE_INVENTORY, null, null, null, null, null, null);
        while (cursor.moveToNext()) {
            items.put(cursor.getString(cursor.getColumnIndex(DatabaseHelper.COLUMN_ITEM_NAME)),
                    cursor.getInt(cursor.getColumnIndex(DatabaseHelper.COLUMN_ITEM_QUANTITY)));
        }
        cursor.close();
        return items;
    }
}



