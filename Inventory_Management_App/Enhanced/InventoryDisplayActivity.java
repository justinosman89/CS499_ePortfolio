package com.personal.inventoryapp;

import android.os.Bundle;
import android.widget.GridLayout;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

/**
 * Activity to display all inventory items in a grid layout.
 * This activity fetches data from the repository and updates the UI.
 */
public class InventoryDisplayActivity extends AppCompatActivity {

    private GridLayout inventoryGrid;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_inventory_display);

        // Reference the grid layout where inventory items will be displayed
        inventoryGrid = findViewById(R.id.inventory_grid);

        // Load and display inventory items
        loadInventoryData();
    }

    /**
     * Fetch inventory data from the repository and display it on the screen.
     */
    private void loadInventoryData() {
        Repository repository = new Repository(this);

        // Fetch all inventory items and dynamically add them to the grid
        repository.getAllItems().forEach((itemName, quantity) -> {
            TextView itemView = new TextView(this);
            itemView.setText(itemName + ": " + quantity);
            inventoryGrid.addView(itemView);
        });
    }
}
