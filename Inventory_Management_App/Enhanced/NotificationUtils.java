package com.personal.inventoryapp;

import android.content.Context;
import android.widget.Toast;

/**
 * Utility class for sending notifications.
 */
public class NotificationUtils {

    /**
     * Simulates sending an SMS notification.
     *
     * @param context Context of the calling activity.
     * @param message Message to be sent.
     */
    public static void sendSmsNotification(Context context, String message) {
        Toast.makeText(context, "Notification: " + message, Toast.LENGTH_SHORT).show();
    }
}
