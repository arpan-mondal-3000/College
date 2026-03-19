package org.example;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.ArrayList;
import java.util.Random;

public class SpaceInvaders extends JPanel implements ActionListener, KeyListener {
    // board
    int tileSize = 32;
    int rows = 16, columns = 16;
    int boardWidth = tileSize * columns;
    int boardHeight = tileSize * rows;

    boolean gameover = false;

    Random random = new Random();

    // array of aliens
    ArrayList<Alien> aliensArray;

    int alienX = 16, alienY = 16;
    int alienRows = 2;
    int alienColumns = 3;
    int alienCount = 0;
    int alienVelocityX = 1;

    // bullets
    ArrayList<Bullet> bulletsArray;
    int bulletVelocityY = -10;

    // ship
    Ship ship;
    int shipVelocityX = tileSize;

    Timer gameLoop;

    SpaceInvaders(){
        setPreferredSize(new Dimension(boardWidth, boardHeight));
        setBackground(Color.black);
        setFocusable(true);
        addKeyListener(this);

        // create the ship
        ship = new Ship();

        // create the aliens
        aliensArray = new ArrayList<Alien>();
        createAliens();

        // create the bullets
        bulletsArray = new ArrayList<Bullet>();

        // initiate and start the game loop
        gameLoop = new Timer(15, this);
        gameLoop.start();
    }

    public Color generateRandomColor(){
        final float hue = random.nextFloat();
        final float saturation = 0.9f;
        final float luminance = 1.0f;
        return Color.getHSBColor(hue, saturation, luminance);
    }

    public void createAliens(){
        for(int i = 0; i < alienRows; i++){
            for(int j = 0; j < alienColumns; j++){
                Alien alien = new Alien(alienX+j*Alien.width, alienY+i*Alien.height, generateRandomColor());
                aliensArray.add(alien);
            }
        }
        alienCount = aliensArray.size();
    }

    public void move(){
        for(Alien alien: aliensArray){
            if(alien.alive){
                alien.x += alienVelocityX;

                // reverse the direction of aliens if they touch boundary
                if(alien.x+Alien.width >= boardWidth || alien.x <= 0){
                    alienVelocityX *= -1;
                    alien.x += alienVelocityX*2;

                    // move all aliens by one row
                    for(Alien a: aliensArray){
                        a.y += Alien.height;
                    }
                }
                if(alien.y >= ship.y){
                    gameover = true;
                }
            }
        }

        // move bullets and check for collision
        for(Bullet bullet: bulletsArray){
            bullet.y += bulletVelocityY;

            // bullet collision with aliens
            for(Alien alien: aliensArray){
                if(!bullet.used && alien.alive && detectCollision(alien, bullet)){
                    bullet.used = true;
                    alien.alive = false;
                    alienCount--;
                }
            }
        }

        // clear bullets
        while(!bulletsArray.isEmpty() && (bulletsArray.getFirst().used || bulletsArray.getFirst().y < 0)){
            bulletsArray.removeFirst();
        }

        // next level
        if(alienCount == 0){
            alienColumns = Math.min(alienColumns+1, columns/2 - 2);
            alienRows = Math.min(alienRows+1, rows - 6);
            aliensArray.clear();
            bulletsArray.clear();
            createAliens();
        }
    }

    public Boolean detectCollision(Alien alien, Bullet bullet){
        return alien.x < bullet.x + Bullet.width &&
                alien.x + Alien.width > bullet.x &&
                alien.y < bullet.y + Bullet.height &&
                alien.y + Alien.height > bullet.y;
    }

    protected void paintComponent(Graphics g){
        super.paintComponent(g);
        // draw the ship
        ship.draw(g);
        // draw the aliens
        for(Alien alien: aliensArray){
            if(alien.alive){
                alien.draw(g);
            }
        }
        // draw the bullets
        for(Bullet bullet: bulletsArray){
            if(!bullet.used){
                bullet.draw(g);
            }
        }
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        move();
        repaint();
        if(gameover){
            gameLoop.stop();
        }
    }

    @Override
    public void keyTyped(KeyEvent keyEvent) {

    }

    @Override
    public void keyPressed(KeyEvent keyEvent) {

    }

    @Override
    public void keyReleased(KeyEvent keyEvent) {
        if(keyEvent.getKeyCode() == KeyEvent.VK_LEFT && ship.x - shipVelocityX >= 0){
            ship.x -= shipVelocityX; // move left one tile
        }else if(keyEvent.getKeyCode() == KeyEvent.VK_RIGHT && ship.x + tileSize + shipVelocityX <= boardWidth){
            ship.x += shipVelocityX; // move one tile right
        }else if(keyEvent.getKeyCode() == KeyEvent.VK_SPACE){
            Bullet bullet = new Bullet(ship.x + ship.width*15/32, ship.y);
            bulletsArray.add(bullet);
        }
    }
}
