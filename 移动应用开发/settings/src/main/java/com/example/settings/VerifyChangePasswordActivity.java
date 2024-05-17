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

public class VerifyChangePasswordActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_verify_change_password);

        Button btn_confirm_change_password = findViewById(R.id.btn_confirm_change_password);
        btn_confirm_change_password.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //获取用户更改密码时输入的邮箱验证码
                TextView  tv_user_change_password_verify_token= findViewById(R.id.tv_user_change_password_verify_token);
                String user_change_password_verify_token = tv_user_change_password_verify_token.getText().toString();
                //发送给服务器进行验证
//                if(验证码正确){
//                    修改密码成功,跳转到登录界面
                Intent intent = new Intent();
                intent.setClass(VerifyChangePasswordActivity.this, MainActivity.class);
                startActivity(intent);
//                }else {
//                    验证码登录，弹出错误信息，返回上一级页面
//                }
            }
        });
    }
}