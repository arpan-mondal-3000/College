package org.example;

import java.awt.*;

public class Tile {
    int x, y;
    final static public int TILE_WIDTH = 50;
    Color tileColor;
    public boolean isHit = false;

    public Tile(int x, int y, Color tileColor){
        this.x = x;
        this.y = y;
        this.tileColor = tileColor;
    }

    public void draw(Graphics g){
        g.setColor(tileColor);
        g.fillRect(x, y, TILE_WIDTH, TILE_WIDTH);
    }
}
