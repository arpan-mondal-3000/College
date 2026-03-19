import java.awt.Graphics;

public class HermiteSpline extends DrawingObject {

    int x0, y0, x1, y1;
    double tx0, ty0;   // tangent at start
    double tx1, ty1;   // tangent at end

    @Override
    void draw(Graphics g) {

        for (double t = 0; t <= 1; t += 0.002) {

            double h00 = 2*t*t*t - 3*t*t + 1;
            double h10 = t*t*t - 2*t*t + t;
            double h01 = -2*t*t*t + 3*t*t;
            double h11 = t*t*t - t*t;

            double x = h00*x0 + h10*tx0 + h01*x1 + h11*tx1;
            double y = h00*y0 + h10*ty0 + h01*y1 + h11*ty1;

            g.drawRect((int)Math.round(x), (int)Math.round(y), 1, 1);
        }
    }
}