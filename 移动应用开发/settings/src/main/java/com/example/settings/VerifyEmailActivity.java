package com.example.settings;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class VerifyEmailActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_verify_email);

        //获取确认注册按钮
        Button btn_confirm_register = findViewById(R.id.btn_confirm_register);
        btn_confirm_register.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //获取用户注册时输入的验证码
                TextView tv_user_register_verify_token = findViewById(R.id.tv_user_register_verify_token);
                String user_register_verify_token = tv_user_register_verify_token.getText().toString();
                //发送给服务器进行验证
//                if(验证码正确){
//                    注册成功，同时完成登录
                Intent intent=new Intent();
                intent.setClass(VerifyEmailActivity.this, SettingsActivity.class);
                startActivity(intent);
//                }else {
//                    验证码登录，弹出错误信息，返回上一级页面
//                }

            }
        });
    }
}