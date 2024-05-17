package com.example.settings;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class ChangePasswordActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_change_password);
        //获取发送验证码按钮
        Button btn_send_retrieve_password_verify = findViewById(R.id.btn_send_retrieve_password_verify);
        //发送验证码按钮绑定点击事件
        btn_send_retrieve_password_verify.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //获取注册的用户名
                TextView et_user_register_name  = findViewById(R.id.et_user_change_password_word_name);
                String  user_register_name= et_user_register_name.getText().toString();

                //获取注册的密码
                TextView et_user_register_password1  = findViewById(R.id.et_user_new_password1);
                String  user_register_password1= et_user_register_name.getText().toString();

                //获取注册的密码（重复）
                TextView et_user_register_password2  = findViewById(R.id.et_user_new_password2);
                String  user_register_password2= et_user_register_name.getText().toString();

                //获取注册的邮箱号
                TextView et_user_register_email  = findViewById(R.id.et_user_change_password_email);
                String  user_register_email= et_user_register_name.getText().toString();

                //检测输入信息是否合法
                //(1)用户名是否合法
                //(2)两次密码是否相同
                //(3)邮箱格式是否正确

                //if(通过验证)
                //{
                // 跳转到输入邮箱验证码页面
                Intent intent = new Intent();
                intent.setClass(ChangePasswordActivity.this, VerifyChangePasswordActivity.class);
                startActivity(intent);
                //}
                //else(){
                //显示提示信息
                //
                //
                //}
            }
        });
    }
}