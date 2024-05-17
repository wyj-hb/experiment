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

public class RegisterActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        //获取发送验证码按钮
        Button btn_continue = findViewById(R.id.btn_send_register_verify);
        //发送验证码按钮设置为灰色
        btn_continue.setAlpha(0.3f);
        //发我验证码按钮禁止点击
        btn_continue.setEnabled(false);
        //发送验证码按钮绑定点击事件
        btn_continue.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //获取注册的用户名
                TextView et_user_register_name  = findViewById(R.id.et_user_register_name);
                String  user_register_name= et_user_register_name.getText().toString();

                //获取注册的密码
                TextView et_user_register_password1  = findViewById(R.id.et_user_register_password1);
                String  user_register_password1= et_user_register_name.getText().toString();

                //获取注册的密码（重复）
                TextView et_user_register_password2  = findViewById(R.id.et_user_register_password2);
                String  user_register_password2= et_user_register_name.getText().toString();

                //获取注册的邮箱号
                TextView et_user_register_email  = findViewById(R.id.et_user_register_email);
                String  user_register_email= et_user_register_name.getText().toString();

                //检测输入信息是否合法
                //(1)用户名是否合法
                //(2)两次密码是否相同
                //(3)邮箱格式是否正确

                //if(通过验证)
                //{
                // 跳转到输入邮箱验证码页面
                Intent intent = new Intent();
                intent.setClass(RegisterActivity.this, VerifyEmailActivity.class);
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
        CheckBox ck_accept_protocol2 = findViewById(R.id.ck_accept_protocol2);
        ck_accept_protocol2.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean isAccept) {
                btn_continue.setEnabled(isAccept);
                //不同意协议时，按钮设置为灰色
                if(!isAccept){
                    btn_continue.setAlpha(0.3f);
                }
                //同意协议时，按钮设置为蓝色
                else {
                    btn_continue.setAlpha(1f);
                }
            }
        });
    }
}