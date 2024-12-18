

package com.personal.inventoryapp;

import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

/**
 * Activity for managing inventory items.
 * Allows users to add, update, or remove items from the inventory.
 */
public class ItemManagementActivity extends AppCompatActivity {

    private EditText itemNameEditText; // Input for item name
    private EditText itemQuantityEditText; // Input for item quantity

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_item_management);

        // Initialize UI components
        itemNameEditText = findViewById(R.id.item_name);
        itemQuantityEditText = findViewById(R.id.item_quantity);

        // Set up button listeners
        findViewById(R.id.add_button).setOnClickListener(view -> addItem());
        findViewById(R.id.remove_button).setOnClickListener(view -> removeItem());
        findViewById(R.id.update_button).setOnClickListener(view -> updateItem());
    }

    /**
     * Adds a new item to the inventory.
     */
    private void addItem() {
        String itemName = itemNameEditText.getText().toString();
        String itemQuantity = itemQuantityEditText.getText().toString();

        if (TextUtils.isEmpty(itemName) || TextUtils.isEmpty(itemQuantity)) {
            Toast.makeText(this, "Please fill out all fields", Toast.LENGTH_SHORT).show();
            return;
        }

        Repository repository = new Repository(this);
        long newRowId = repository.addItem(itemName, Integer.parseInt(itemQuantity));
        if (newRowId != -1) {
            Toast.makeText(this, "Item added", Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(this, "Error adding item", Toast.LENGTH_SHORT).show();
        }
    }

    /**
     * Removes an item from the inventory.
     */
    private void removeItem() {
        String itemName = itemNameEditText.getText().toString();

        if (TextUtils.isEmpty(itemName)) {
            Toast.makeText(this, "Please enter the item name", Toast.LENGTH_SHORT).show();
            return;
        }

        Repository repository = new Repository(this);
        int deletedRows = repository.removeItem(itemName);
        if (deletedRows > 0) {
            Toast.makeText(this, "Item removed", Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(this, "Item not found", Toast.LENGTH_SHORT).show();
        }
    }

    /**
     * Updates the quantity of an item in the inventory.
     */
    private void updateItem() {
        String itemName = itemNameEditText.getText().toString();
        String itemQuantity = itemQuantityEditText.getText().toString();

        if (TextUtils.isEmpty(itemName) || TextUtils.isEmpty(itemQuantity)) {
            Toast.makeText(this, "Please fill out all fields", Toast.LENGTH_SHORT).show();
            return;
        }

        Repository repository = new Repository(this);
        int updatedRows = repository.updateItem(itemName, Integer.parseInt(itemQuantity));
        if (updatedRows > 0) {
            Toast.makeText(this, "Item updated", Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(this, "Item not found", Toast.LENGTH_SHORT).show();
        }
    }
}
