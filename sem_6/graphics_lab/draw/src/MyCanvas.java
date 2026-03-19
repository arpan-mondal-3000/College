import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.List;
import java.util.Vector;

import javax.swing.JPanel;

public class MyCanvas extends JPanel implements MouseListener, MouseMotionListener {
	String currentDrawingTool = "line";
	DrawingObject currentDrawingObject = null;
	List<DrawingObject> objects = new Vector<DrawingObject>();
	private int clickCount = 0;

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
		for (DrawingObject ob : objects) {
			ob.draw(g);
		}
	}

	@Override
	public void mouseClicked(MouseEvent e) {

	}

	@Override
	public void mousePressed(MouseEvent e) {

	    if (!currentDrawingTool.equalsIgnoreCase("hermite spline")) {
	        if (currentDrawingObject == null) {
	            if (currentDrawingTool.equalsIgnoreCase("line")) {
	                currentDrawingObject = new Line(e.getX(), e.getY(), e.getX(), e.getY());
	            } else if (currentDrawingTool.equalsIgnoreCase("circle")) {
	                currentDrawingObject = new Circle(e.getX(), e.getY(), 1);
	            }
	            objects.add(currentDrawingObject);
	        }
	        return;
	    }

	    if (clickCount == 0) {
	        currentDrawingObject = new HermiteSpline();
	        objects.add(currentDrawingObject);

	        HermiteSpline spline = (HermiteSpline) currentDrawingObject;
	        spline.x0 = e.getX();
	        spline.y0 = e.getY();

	        System.out.println("Start Point Set");
	    }

	    else if (clickCount == 1) {
	        HermiteSpline spline = (HermiteSpline) currentDrawingObject;

	        int x = e.getX();
	        int y = e.getY();

	        spline.tx0 = e.getX() - spline.x0;
	        spline.ty0 = e.getY() - spline.y0;

	        System.out.println("Start Slope Set");
	    }

	    else if (clickCount == 2) {
	        HermiteSpline spline = (HermiteSpline) currentDrawingObject;

	        spline.x1 = e.getX();
	        spline.y1 = e.getY();

	        System.out.println("End Point Set");
	    }

	    else if (clickCount == 3) {
	        HermiteSpline spline = (HermiteSpline) currentDrawingObject;

	        int x = e.getX();
	        int y = e.getY();

	        spline.tx1 = e.getX() - spline.x1;
	        spline.ty1 = e.getY() - spline.y1;

	        System.out.println("End Slope Set");

	        // Reset for next spline
	        clickCount = -1;
	        currentDrawingObject = null;
	    }

	    clickCount++;
	    repaint();
	}
	@Override
	public void mouseReleased(MouseEvent e) {
		if(currentDrawingTool.equalsIgnoreCase("hermite spline")) return;
		currentDrawingObject = null;
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
		if (currentDrawingTool.equalsIgnoreCase("line")) {
			Line line = (Line) currentDrawingObject;
			line.x2 = e.getX();
			line.y2 = e.getY();
			System.out.println(line);
		} else if (currentDrawingTool.equalsIgnoreCase("circle")) {
			Circle circle = (Circle) currentDrawingObject;
			circle.r = Math.sqrt(Math.pow(e.getX() - circle.x, 2) + Math.pow(e.getY() - circle.y, 2));
			System.out.println(circle);
		}

	}

	@Override
	public void mouseMoved(MouseEvent e) {
		// TODO Auto-generated method stub

	}
}
