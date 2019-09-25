import java.awt.*;

public class DrawableRect extends Rectangle {
    protected Color outColor;

    public DrawableRect(int _x1, int _y1, int _x2, int _y2, Color color){
        super(_x1,_y1, _x2, _y2);
        outColor = color;
    }

    public void draw(Graphics g){
        g.drawRect(x1, y1, x2 - x1, y2- y1);
        g.setColor(outColor);
    }


}
