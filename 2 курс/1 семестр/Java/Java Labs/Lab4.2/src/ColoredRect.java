import java.awt.*;

public class ColoredRect extends DrawableRect {
    protected Color inColor;

    public ColoredRect(int _x1, int _y1, int _x2, int _y2, Color out_color, Color in_color){
        super(_x1, _y1, _x2, _y2, out_color);
        inColor = in_color;
    }

    public void draw(Graphics g){
        super.draw(g);
        g.fillRect(super.getX1(), super.getY1(), super.getX2() - super.getX1(), super.getY2()- super.getY1());
        g.setColor(inColor);


    }
}
