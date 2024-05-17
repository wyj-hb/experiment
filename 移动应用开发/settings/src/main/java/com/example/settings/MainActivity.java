package com.example.settings;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //获取登录按钮
        Button btn_login = findViewById(R.id.btn_login);
        //开始时设置登录按钮为灰色
        btn_login.setAlpha(0.7f);
        //登录按钮禁止点击
        btn_login.setEnabled(false);
        //登录按钮绑定点击事件
        btn_login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //获取用户登录账号
                TextView user_name_view = findViewById(R.id.user_name);
                String user_name = user_name_view.getText().toString();

                //获取用户登录密码
                TextView user_password_view= findViewById(R.id.user_password);
                String user_password = user_password_view.getText().toString();

                //发送用户名和密码到服务器，进行登录验证
               // if(用户名密码均正确){
//                    完成登录
//                }else {
//                    弹出错误信息
//                }

                //跳转到"我的界面"
                Intent intent=new Intent();
                intent.setClass(MainActivity.this, SettingsActivity.class);
                startActivity(intent);
            }
        });

        //获取注册按钮
        Button btn_register= findViewById(R.id.btn_register);
        //注册按钮设置为灰色
        btn_register.setAlpha(0.7f);
        //注册按钮禁止点击
        btn_login.setEnabled(false);
        //注册按钮绑定点击事件
        btn_register.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //跳转到注册
                Intent intent=new Intent();
                intent.setClass(MainActivity.this, RegisterActivity.class);
                startActivity(intent);
            }
        });

        //获取同意协议按钮
        CheckBox cb_accept_protocol1  = findViewById(R.id.cb_accept_protocol1);
        //同意协议按钮绑定点击事件
        cb_accept_protocol1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean isAccept) {
                //注册和登录按钮设置是否禁止
                btn_login.setEnabled(isAccept);
                btn_register.setEnabled(isAccept);
                //不同意协议时，按钮设置为灰色
                if(!isAccept){
                    btn_login.setAlpha(0.7f);
                    btn_register.setAlpha(0.7f);
                }
                //同意协议时，按钮设置为蓝色
                else {
                    btn_login.setAlpha(1f);
                    btn_register.setAlpha(1f);
                }
            }
        });

        //获取忘记按钮
        Button btn_find_password = findViewById(R.id.btn_find_password);
        btn_find_password.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //跳转到找回密码界面
                Intent intent=new Intent();
                intent.setClass(MainActivity.this, ChangePasswordActivity.class);
                startActivity(intent);
            }
        });

        //获取其他登录方式按钮,跳转到GitHub登录
        Button btn_other_login_way = findViewById(R.id.btn_other_login_way);
        btn_other_login_way.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //跳转到使用GitHub登录界面
                Intent intent=new Intent();
                intent.setClass(MainActivity.this, GitHubLoginActivity.class);
                startActivity(intent);
            }
        });
    }
}