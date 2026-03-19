package org.example;

import java.awt.*;

public class Alien {
    int x, y; // position of the alien
    public static int width = 32, height = 32;
    Color color;
    Boolean alive = true;

    public Alien(int x, int y, Color color){
        this.x = x;
        this.y = y;
        this.color = color;
    }

    public void draw(Graphics g){
        g.setColor(color);
        g.fillRect(x, y, 32, 32);
    }
}
