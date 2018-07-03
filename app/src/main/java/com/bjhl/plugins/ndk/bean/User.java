package com.bjhl.plugins.ndk.bean;

/**
 * Created by XIAS on 2018/6/28.
 */

public class User {
    private int id;
    private String name;
    private String avatar;

    public User() {
    }

    public User(String name, int id, String avatar) {
        this.name = name;
        this.id = id;
        this.avatar = avatar;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAvatar() {
        return avatar;
    }

    public void setAvatar(String avatar) {
        this.avatar = avatar;
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", avatar='" + avatar + '\'' +
                '}';
    }
}
