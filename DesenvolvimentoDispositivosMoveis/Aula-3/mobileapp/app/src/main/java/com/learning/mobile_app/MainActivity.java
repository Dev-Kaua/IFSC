package com.learning.mobile_app;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    int contador = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        Button button = findViewById(R.id.button);
        TextView tv = findViewById(R.id.textView);
        EditText edmin, edmax;
        edmin = findViewById(R.id.editMin);
        edmax = findViewById(R.id.editMax);
        tv.setText("");

        button.setOnClickListener(view -> {
            String smin = edmin.getText().toString();
            String smax = edmax.getText().toString();

            if(smin.isEmpty()){
                edmin.setError("Informe um inteiro");
                return;
            }
            if(smax.isEmpty()){
                edmax.setError("Informe um inteiro");
                return;
            }

            int min = Integer.parseInt(smin);
            int max = Integer.parseInt(smax);

            if(min>max){
                Toast.makeText(this, "Defina Minimo < Máximo", Toast.LENGTH_SHORT).show();
                return;
            }

            Random random = new Random();
            int randomN = random.nextInt(min, max);
            tv.setText(Integer.toString(randomN));
        });

    }
}