package com.bjhl.plugins.ndk.util;

import com.bjhl.plugins.ndk.bean.User;

import java.util.ArrayList;

/**
 * Created by XIAS on 2018/6/28.
 */

public class NativeUtil {

    static {
        System.loadLibrary("native-lib");
    }

    public static native String stringFromJNI();

    //生成一个m x m的二维数组
    public static native int[][] intArrayFromJNI(int m);

    //生成一个User对象
    public static native User getUserFromJNI();

    //修改user对象的值
    public static native void setUserFromJNI(User user);

    //生成一个指定长度的列表
    public static native ArrayList<User> getUsersFromJNI(int len);
}
