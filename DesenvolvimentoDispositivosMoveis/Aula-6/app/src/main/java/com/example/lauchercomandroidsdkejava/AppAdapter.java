package com.example.lauchercomandroidsdkejava;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import java.util.List;

public class AppAdapter extends ArrayAdapter<ApplicationInfo> {

    private PackageManager packageManager;

    public AppAdapter(Context context, int resource, List<ApplicationInfo> objects) {
        super(context, resource, objects);
        packageManager = context.getPackageManager();
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        if (convertView == null) {
            convertView = LayoutInflater.from(getContext()).inflate(R.layout.item_lista, parent, false);
        }

        ImageView appIcon = convertView.findViewById(R.id.app_icon);
        TextView appName = convertView.findViewById(R.id.app_name);

        ApplicationInfo appInfo = getItem(position);

        if (appInfo != null) {
            appName.setText(appInfo.loadLabel(packageManager));
            appIcon.setImageDrawable(appInfo.loadIcon(packageManager));
        }

        return convertView;
    }
}