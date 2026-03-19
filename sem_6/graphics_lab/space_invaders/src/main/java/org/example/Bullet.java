package org.example;

import java.awt.*;

public class Bullet {
    int x, y;
    public static int width = 4, height = 16;
    boolean used = false;

    public Bullet(int x, int y){
        this.x = x;
        this.y = y;
    }

    public void draw(Graphics g){
        g.setColor(Color.RED);
        g.fillRect(x, y, width, height);
    }
}
