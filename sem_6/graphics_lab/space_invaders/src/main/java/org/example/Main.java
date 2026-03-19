package org.example;

import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        // Window variables
        int tileSize = 32;
        int rows = 16, columns = 16;
        int boardWidth = tileSize * columns;
        int boardHeight = tileSize * rows;

        JFrame frame = new JFrame("Space invaders");
        frame.setSize(boardWidth, boardHeight);
        frame.setLocationRelativeTo(null); // open the window at center of the screen
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        SpaceInvaders spaceInvaders = new SpaceInvaders();
        spaceInvaders.requestFocusInWindow();
        frame.add(spaceInvaders);
        frame.pack();
        frame.setVisible(true);
    }
}