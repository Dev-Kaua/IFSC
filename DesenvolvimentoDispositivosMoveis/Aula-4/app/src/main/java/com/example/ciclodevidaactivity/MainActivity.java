package com.example.ciclodevidaactivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

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

        Toast.makeText(this, "onCreate", Toast.LENGTH_LONG).show();
        Log.d("cicloDaVida", "onCreate");
    }


    @Override
    protected void onStart(){
        super.onStart();
        android.widget.Toast.makeText(this, "onStart", Toast.LENGTH_LONG).show();

        Log.d("cicloDaVida", "onStart");
    }

    @Override
    protected void onResume(){
        super.onResume();
        android.widget.Toast.makeText(this, "onResume", Toast.LENGTH_LONG).show();

        Log.d("cicloDaVida", "onResume");
    }

    @Override
    protected void onPause(){
        super.onPause();
        android.widget.Toast.makeText(this, "onPause", Toast.LENGTH_LONG).show();

        Log.d("cicloDaVida", "onPause");
    }

    @Override
    protected void onStop(){
        super.onStop();
        android.widget.Toast.makeText(this, "onStop", Toast.LENGTH_LONG).show();

        Log.d("cicloDaVida", "onStop");
    }

    @Override
    protected void onDestroy(){
        super.onDestroy();
        android.widget.Toast.makeText(this, "onDestroy", Toast.LENGTH_LONG).show();

        Log.d("cicloDaVida", "onDestroy");
    }
}