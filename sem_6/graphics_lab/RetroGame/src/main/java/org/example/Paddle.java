package org.example;

import java.awt.*;

public class Paddle {
    int x, y;
    final static public int PADDLE_WIDTH = 150;
    final static public int PADDLE_HEIGHT = 20;

    public Paddle(int x, int y){
        this.x = x;
        this.y = y;
    }

    public void draw(Graphics g){
        g.setColor(Color.WHITE);
        g.fillRect(x, y, PADDLE_WIDTH, PADDLE_HEIGHT);
    }
}
