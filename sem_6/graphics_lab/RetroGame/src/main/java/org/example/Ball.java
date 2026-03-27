package org.example;

import java.awt.*;

public class Ball {
    int x, y;
    int dx = 2, dy = 2;
    final static public int BALL_DIAMETER=50;

    public Ball(int x, int y){
        this.x = x;
        this.y = y;
    }

    public void draw(Graphics g){
        g.setColor(Color.RED);
        g.fillOval(x, y, BALL_DIAMETER, BALL_DIAMETER);
    }
}
