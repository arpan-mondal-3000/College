package org.example;

import java.awt.*;

public class Ship {
    int x = 32*8-16, y = 32*14;
    int width = 32, height = 32+10;

    Ship(){
        System.out.println("Ship created");
    }

    public void draw(Graphics g){
        g.setColor(Color.white);
        g.fillRect(x, y, 32, 32);
        g.fillRect(x+11, y-10, 10, 10);
    }
}
