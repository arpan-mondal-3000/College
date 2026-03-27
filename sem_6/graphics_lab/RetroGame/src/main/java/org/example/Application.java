package org.example;

import javax.swing.*;
import java.awt.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Application extends JFrame {
    public Application(){
        initUI();
    }

    private void initUI(){
        add(new Board());
        setResizable(false);
        pack();

        setTitle("Paranoid game");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
    }

    public static void main(String[] args) {
        EventQueue.invokeLater(()->{
            Application app = new Application();
            app.setVisible(true);
        });
    }
}