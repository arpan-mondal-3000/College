import java.awt.Graphics;

public class Circle extends DrawingObject {
	int x,y;
	double r;
	
	public Circle(int x, int y, double r) {
		this.x = x;
		this.y = y;
		this.r = r;
	}


	@Override
	void draw(Graphics g) {
		g.drawOval(x, y, (int)r, (int)r);

	}

}
