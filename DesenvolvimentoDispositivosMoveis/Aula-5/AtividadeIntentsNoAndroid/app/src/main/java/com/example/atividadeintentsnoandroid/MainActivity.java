package com.example.atividadeintentsnoandroid;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button btnExplicita = findViewById(R.id.btnIntentExplicita);
        Button btnImplicita = findViewById(R.id.btnIntentImplicita);

        btnExplicita.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intentExplicita = new Intent(MainActivity.this, SegundaActivity.class);
                startActivity(intentExplicita);
            }
        });

        btnImplicita.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Uri webpage = Uri.parse("https://www.google.com");
                Intent intentImplicita = new Intent(Intent.ACTION_VIEW, webpage);
                startActivity(intentImplicita);
            }
        });
    }
}