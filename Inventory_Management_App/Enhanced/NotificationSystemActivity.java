package com.personal.inventoryapp;

import android.os.Bundle;
import android.widget.Button;
import androidx.appcompat.app.AppCompatActivity;

/**
 * Activity for sending notifications related to inventory updates.
 */
public class NotificationSystemActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_notification_system);

        Button sendNotificationButton = findViewById(R.id.send_notification_button);

        // Send a notification when the button is clicked
        sendNotificationButton.setOnClickListener(view ->
                NotificationUtils.sendSmsNotification(this, "Inventory Notification: Check stock!")
        );
    }
}
