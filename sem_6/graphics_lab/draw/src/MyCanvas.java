import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

import javax.swing.JPanel;

public class MyCanvas extends JPanel implements MouseListener, MouseMotionListener{
	String currentDrawingTool="line";
	DrawingObject currentDrawingObject = null;
	List<DrawingObject> objects = new Vector<DrawingObject>();
	public MyCanvas() {
		setBackground(Color.WHITE);
		addMouseListener(this);
		addMouseMotionListener(this);
	}
	
	void drawLine(int x1, int y1, int x2, int y2) {
		Graphics g = getGraphics();
		g.fillOval(x1, y1, 10, 10);
		g.fillOval(x2, y2, 10, 10);
	}

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		for(DrawingObject ob : objects) {
			ob.draw(g);
		}
	}
	
	@Override
	public void mouseClicked(MouseEvent e) {
		
	}

	@Override
	public void mousePressed(MouseEvent e) {
		if(currentDrawingObject == null) {
			if(currentDrawingTool.equalsIgnoreCase("line")){
				currentDrawingObject = new Line(e.getX(), e.getY(), e.getX(), e.getY());
			}else {
				currentDrawingObject = new Circle(e.getX(), e.getY(), 1);
			}
			objects.add(currentDrawingObject);
	
		}
		
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		currentDrawingObject=null;
		
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseDragged(MouseEvent e) {
		if(currentDrawingTool.equalsIgnoreCase("line")) {
			Line line = (Line)currentDrawingObject;
			line.x2 = e.getX();
			line.y2 = e.getY();
			System.out.println(line);
		}else {
			Circle circle = (Circle)currentDrawingObject;
			circle.r = Math.sqrt(Math.pow(e.getX()-circle.x,2) + Math.pow(e.getY()-circle.y,2));
		}
		
		
	}

	@Override
	public void mouseMoved(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
}
