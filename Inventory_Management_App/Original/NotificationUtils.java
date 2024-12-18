
package com.personal.inventoryapp;

import android.Manifest;
import android.content.Context;
import android.content.pm.PackageManager;
import android.widget.Toast;
import androidx.core.content.ContextCompat;

/**
 * Utility class for sending SMS notifications.
 */
public class NotificationUtils {

    /**
     * Checks if the app has permission to send SMS.
     *
     * @param context The application context.
     * @return True if SMS permission is granted, false otherwise.
     */
    public static boolean hasSmsPermission(Context context) {
        return ContextCompat.checkSelfPermission(context, Manifest.permission.SEND_SMS)
                == PackageManager.PERMISSION_GRANTED;
    }

    /**
     * Sends an SMS notification if permission is granted.
     *
     * @param context The application context.
     * @param message The message to be sent as a notification.
     */
    public static void sendSmsNotification(Context context, String message) {
        if (hasSmsPermission(context)) {
            // Logic to send SMS (stubbed for now)
            Toast.makeText(context, "Notification sent: " + message, Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(context, "SMS Permission not granted", Toast.LENGTH_SHORT).show();
        }
    }
}
