import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.Timer;

public class MyFrame extends JFrame implements ActionListener {

	MyCanvas canvas = new MyCanvas();
	JButton lineBtn=new JButton("Line"), circleBtn=new JButton("Circle");
	public MyFrame() {
		setExtendedState(MAXIMIZED_BOTH);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		initComponents();
		Timer timer = new Timer(100, this);
		timer.start();
	}
	
	private void initComponents() {
		JPanel topPanel = new JPanel();
		lineBtn.addActionListener(this);
		topPanel.add(lineBtn);
		circleBtn.addActionListener(this);
		topPanel.add(circleBtn);
		add(topPanel,BorderLayout.NORTH);	
		add(canvas);	
	}

	@Override
	public void paintComponents(Graphics g) {
		super.paintComponents(g);
		canvas.repaint();
	}
	
	public static void main(String[] args) {
		MyFrame f = new MyFrame();
		f.setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() instanceof Timer) {
			canvas.repaint();
		}else {
			String cmd = e.getActionCommand();
			if(cmd.equalsIgnoreCase("line")) {
				lineBtn.setBackground(Color.RED);
				circleBtn.setBackground(new Color(238,238,238));
			}else if(cmd.equalsIgnoreCase("circle")){
				circleBtn.setBackground(Color.RED);
				lineBtn.setBackground(new Color(238,238,238));
			}
			
		}

		
	}

}
