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

public class GitHubLoginActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_git_hub_login);


        //获取发送验证码按钮
        Button btn_git_hub_login = findViewById(R.id.btn_git_hub_login);
        //发送验证码按钮设置为灰色
        btn_git_hub_login.setAlpha(0.3f);
        //发我验证码按钮禁止点击
        btn_git_hub_login.setEnabled(false);
        //发送验证码按钮绑定点击事件
        btn_git_hub_login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //获取注册的用户名
                TextView ev_user_git_hub_name  = findViewById(R.id.et_user_git_hub_name);
                String  user_git_hub_name= ev_user_git_hub_name.getText().toString();

                //获取注册的密码
                TextView ev_user_git_hub_password  = findViewById(R.id.et_user_git_hub_password);
                String  user_git_hub_password= ev_user_git_hub_password.getText().toString();

                //检测输入用户名是否合法

                //if(通过验证)
                //{跳转到登录界面
                Intent intent=new Intent();
                intent.setClass(GitHubLoginActivity.this, SettingsActivity.class);
                startActivity(intent);
                //}
                //else(){
                //显示提示信息
                //
                //
                //}
            }
        });

        //获取同意协议按钮
        CheckBox ck_git_hub_accept_protocol = findViewById(R.id.ck_git_hub_accept_protocol);
        ck_git_hub_accept_protocol.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean isAccept) {
                btn_git_hub_login.setEnabled(isAccept);
                //不同意协议时，按钮设置为灰色
                if(!isAccept){
                    btn_git_hub_login.setAlpha(0.3f);
                }
                //同意协议时，按钮设置为蓝色
                else {
                    btn_git_hub_login.setAlpha(1f);
                }
            }
        });
    }
}