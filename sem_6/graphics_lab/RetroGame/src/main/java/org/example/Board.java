package org.example;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.ArrayList;
import java.util.Random;

public class Board extends JPanel implements ActionListener, KeyListener {
    private final int BOARD_WIDTH=800;
    private final int BOARD_HEIGHT=600;
    private final int DELAY=16;

    private Timer timer;

    // game logic
    private int score = 0;
    private boolean gameOver = false;

    Random random = new Random();

    // paddle
    Paddle paddle;
    int paddleVelocity = 10;

    // ball
    Ball ball;

    // array of tiles
    ArrayList<Tile> tiles;
    int TILE_PADDING = 5;
    int TILE_ROWS = 3;
    int TILE_COLS = (BOARD_WIDTH - 2*TILE_PADDING) / (Tile.TILE_WIDTH+TILE_PADDING);

    public Board(){
        setBackground(Color.BLACK);
        setPreferredSize(new Dimension(BOARD_WIDTH, BOARD_HEIGHT));
        setFocusable(true);
        addKeyListener(this);
        requestFocusInWindow();

        // initialize the paddle
        paddle = new Paddle(BOARD_WIDTH/2 - Paddle.PADDLE_WIDTH/2, BOARD_HEIGHT - Paddle.PADDLE_HEIGHT);

        // initialize the ball
        ball = new Ball(BOARD_WIDTH/2 - Ball.BALL_DIAMETER/2, BOARD_HEIGHT/2 - Ball.BALL_DIAMETER/2);

        // initialize the tiles array
        tiles = new ArrayList<Tile>();
        setTiles();

        timer = new Timer(DELAY, this);
        timer.start();
    }

    public Color generateRandomColor(){
        final float hue = random.nextFloat();
        final float saturation = 0.9f;
        final float luminance = 1.0f;
        return Color.getHSBColor(hue, saturation, luminance);
    }

    public Boolean detectCollision(Tile tile){
        return tile.x < ball.x + Ball.BALL_DIAMETER &&
                tile.x + Tile.TILE_WIDTH > ball.x &&
                tile.y < ball.y + Ball.BALL_DIAMETER &&
                tile.y + Tile.TILE_WIDTH > ball.y;
    }

    private void setTiles(){
        int tileStart = (BOARD_WIDTH - ((TILE_COLS * (Tile.TILE_WIDTH + TILE_PADDING)) - TILE_PADDING)) / 2;
        int tileX = tileStart, tileY = tileStart;
        for(int i = 0; i < TILE_ROWS; i++){
            for(int j = 0; j < TILE_COLS; j++){
                tiles.add(new Tile(tileX, tileY, generateRandomColor()));
                tileX += Tile.TILE_WIDTH + TILE_PADDING;
            }
            tileX = tileStart;
            tileY += Tile.TILE_WIDTH + TILE_PADDING;
        }
    }

    private void moveBall(){
        // move the ball
        ball.x += ball.dx;
        ball.y += ball.dy;

        // LEFT & RIGHT WALL COLLISION
        if (ball.x <= 0 || ball.x + Ball.BALL_DIAMETER >= BOARD_WIDTH) {
            ball.dx = -ball.dx; // reverse horizontal direction
        }

        // TOP WALL COLLISION
        if (ball.y <= 0) {
            ball.dy = -ball.dy; // reverse vertical direction
        }

        // PADDLE COLLISION
        if (ball.y + Ball.BALL_DIAMETER >= paddle.y &&
                ball.x + Ball.BALL_DIAMETER >= paddle.x &&
                ball.x <= paddle.x + Paddle.PADDLE_WIDTH) {

            ball.dy = -ball.dy; // bounce upward
        }

        // BOTTOM (GAME OVER)
        if (ball.y + Ball.BALL_DIAMETER >= BOARD_HEIGHT) {
            gameOver = true;
        }

        // Collision with tiles
        for(Tile tile: tiles){
            if(!tile.isHit && detectCollision(tile)){
                tile.isHit = true;
                score += 1;
                // change direction of ball
                // calculate previous position
                int prevBallX = ball.x - ball.dx;
                int prevBallY = ball.y - ball.dy;

                // ball edges
                int ballLeft = ball.x;
                int ballRight = ball.x + Ball.BALL_DIAMETER;
                int ballTop = ball.y;
                int ballBottom = ball.y + Ball.BALL_DIAMETER;

                // previous edges
                int prevLeft = prevBallX;
                int prevRight = prevBallX + Ball.BALL_DIAMETER;
                int prevTop = prevBallY;
                int prevBottom = prevBallY + Ball.BALL_DIAMETER;

                // tile edges
                int tileLeft = tile.x;
                int tileRight = tile.x + Tile.TILE_WIDTH;
                int tileTop = tile.y;
                int tileBottom = tile.y + Tile.TILE_WIDTH;

                // determine collision side
                boolean hitFromLeft = prevRight <= tileLeft && ballRight > tileLeft;
                boolean hitFromRight = prevLeft >= tileRight && ballLeft < tileRight;
                boolean hitFromTop = prevBottom <= tileTop && ballBottom > tileTop;
                boolean hitFromBottom = prevTop >= tileBottom && ballTop < tileBottom;

                if (hitFromLeft || hitFromRight) {
                    ball.dx = -ball.dx;
                } else if (hitFromTop || hitFromBottom) {
                    ball.dy = -ball.dy;
                } else {
                    // fallback (corner case)
                    ball.dy = -ball.dy;
                }
            }
        }
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        // draw the paddle
        paddle.draw(g);
        // draw the ball
        ball.draw(g);
        // draw the tiles
        for(Tile tile: tiles){
            if(!tile.isHit){
                tile.draw(g);
            }
        }

        // draw the score
        g.setColor(Color.WHITE);
        g.drawString("Score: "+score, 10, 10);

        // draw the game over screen
        if(gameOver){
            Font font = new Font("Arial", Font.BOLD, 40);
            g.setFont(font);
            g.setColor(Color.RED);

            FontMetrics metrics = g.getFontMetrics(font);

            int x = (BOARD_WIDTH - metrics.stringWidth("Game Over your score is: "+score)) / 2;
            int y = BOARD_HEIGHT / 2;

            g.drawString("Game Over your score is: "+score, x, y);
        }

        Toolkit.getDefaultToolkit().sync();
    }

    public void resetBoard(){
        setTiles();
        ball.x = BOARD_WIDTH/2 - Ball.BALL_DIAMETER/2;
        ball.y = BOARD_HEIGHT/2 - Ball.BALL_DIAMETER/2;
        ball.dx = 2;
        ball.dy = 2;

        paddle.x = BOARD_WIDTH/2 - Paddle.PADDLE_WIDTH/2;
        paddle.y = BOARD_HEIGHT - Paddle.PADDLE_HEIGHT;
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        moveBall();
        repaint();
        // reset tiles if all tiles are hit
        int tilesLeft = 0;
        for(Tile tile: tiles){
            if(!tile.isHit) tilesLeft++;
        }
        if(tilesLeft == 0){
            resetBoard();
        }
        if(gameOver){
            timer.stop();
        }
    }

    @Override
    public void keyTyped(KeyEvent keyEvent) {

    }

    @Override
    public void keyPressed(KeyEvent keyEvent) {
        if(keyEvent.getKeyCode() == KeyEvent.VK_LEFT && paddle.x > 0){
            paddle.x -= paddleVelocity;
        }else if(keyEvent.getKeyCode() == KeyEvent.VK_RIGHT && paddle.x+Paddle.PADDLE_WIDTH < BOARD_WIDTH){
            paddle.x += paddleVelocity;
        }
    }

    @Override
    public void keyReleased(KeyEvent keyEvent) {
    }
}
