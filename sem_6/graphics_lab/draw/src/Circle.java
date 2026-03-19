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
	public String toString() {
		return "Circle[("+x+", "+y+")"+", "+r+"]";
	}

	@Override
	void draw(Graphics g) {
		float t = 0;
		while(t < 2*Math.PI) {
			double xPixel = r * Math.cos(t);
			double yPixel = r * Math.sin(t);
			
			int translatedX = x + (int)Math.round(xPixel);
			int translatedY = y + (int)Math.round(yPixel);
			
			g.drawRect(translatedX, translatedY, 1, 1);
			t += 0.002;
		}
	}

}
