package com.personal.inventoryapp;

import android.os.Build;
import android.os.Bundle;
import android.view.View;
import androidx.activity.ComponentActivity;
import androidx.activity.compose.setContent;
import androidx.annotation.RequiresApi;
import androidx.compose.foundation.layout.fillMaxSize;
import androidx.compose.material3.MaterialTheme;
import androidx.compose.material3.Surface;
import androidx.compose.material3.Text;
import androidx.compose.runtime.Composable;
import androidx.compose.ui.Modifier;
import androidx.compose.ui.tooling.preview.Preview;

public class MainActivity extends ComponentActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // Set the content using Compose
        setContent(() -> {
            InventoryAppTheme(() -> {
                Surface(
                        modifier = Modifier.fillMaxSize(),
                        color = MaterialTheme.colorScheme.background
                ) {
                    Greeting("Inventory Management");
                }
            });
        });
    }
}

@Composable
void Greeting(String name) {
    Text(text = "Hello " + name + "!");
}

@Preview(showBackground = true)
@Composable
void GreetingPreview() {
    Greeting("Inventory Management");
}
