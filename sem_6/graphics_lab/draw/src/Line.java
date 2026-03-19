import java.awt.Graphics;

public class Line extends DrawingObject {

	int x1,y1,x2,y2;
	
	
	public Line(int x1, int y1, int x2, int y2) {
		this.x1 = x1;
		this.y1 = y1;
		this.x2 = x2;
		this.y2 = y2;
	}

	@Override
	public String toString() {
		return "Line[("+x1+","+y1+"),("+x2+","+y2+")]";
	}

	@Override
	void draw(Graphics g) {
		// Implement the DDA algorithm
        int dx = x2 - x1;
        int dy = y2 - y1;

        int steps = Math.max(Math.abs(dx), Math.abs(dy));

        float x = x1;
        float y = y1;

        float xincr = (float) dx / steps;
        float yincr = (float) dy / steps;

        for (int k = 0; k <= steps; k++) {
            g.drawRect(Math.round(x), Math.round(y), 1, 1);
            x += xincr;
            y += yincr;
        }
	}

}
