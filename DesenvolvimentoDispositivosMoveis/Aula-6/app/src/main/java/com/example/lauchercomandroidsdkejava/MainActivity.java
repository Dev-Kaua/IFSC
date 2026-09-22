package com.example.lauchercomandroidsdkejava;

import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.widget.ListView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.List;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        ListView listView = findViewById(R.id.listview_apps);

        PackageManager packageManager = getPackageManager();
        List<ApplicationInfo> packageInfoList = packageManager.getInstalledApplications(PackageManager.GET_META_DATA);

        AppAdapter adapter = new AppAdapter(this, R.layout.item_lista, packageInfoList);

        listView.setAdapter(adapter);

        listView.setOnItemClickListener(new android.widget.AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(android.widget.AdapterView<?> parent, android.view.View view, int position, long id) {

                ApplicationInfo applicationInfo = (ApplicationInfo) parent.getItemAtPosition(position);

                String packageName = applicationInfo.packageName;

                android.content.Intent intent = getPackageManager().getLaunchIntentForPackage(packageName);

                if (intent != null) {
                    startActivity(intent);
                } else {
                    android.widget.Toast.makeText(MainActivity.this, "Não foi possível abrir o aplicativo", android.widget.Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}