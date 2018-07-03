package com.bjhl.plugins.ndk;

import android.os.Handler;
import android.os.Messenger;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;

import com.bjhl.plugins.ndk.bean.User;
import com.bjhl.plugins.ndk.util.NativeUtil;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(NativeUtil.stringFromJNI());


        int[][] a = NativeUtil.intArrayFromJNI(6);
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                System.out.print(a[i][j]);
            }
            System.out.println();
        }

        User user = NativeUtil.getUserFromJNI();
        if (user != null)
            tv.setText(user.getId() + "  " + user.getName() + "  " + user.getAvatar());
        else {
            Toast.makeText(this, "NULL", Toast.LENGTH_SHORT).show();

            User user1 = new User("XIAS", 1, "");
            System.out.println("调用前" + user1.getName());
            NativeUtil.setUserFromJNI(user1);
            System.out.println("调用后" + user1.getName());

            ArrayList<User> users = NativeUtil.getUsersFromJNI(6);
            if (users != null)
                for (User u : users) {
                    System.out.println(u.getId() + "  " + u.getName() + "  " + u.getAvatar());
                }

        }
    }
}
