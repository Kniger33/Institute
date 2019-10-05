import java.awt.*;
import java.io.Serializable;

public class Rectangle implements Serializable{

    private int x1, y1;             //Левый верхний угол
    private int x2, y2;             //Правый нижний угол


    public Rectangle(int _x1, int _y1, int _x2, int _y2){
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    }

    public Rectangle(int _width, int _height){
        x2 = _width;
        y2 = _height;
        x1 = 0;
        y1 = 0;
    }

    public Rectangle(){
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;

    }

    public  void rect_print(){
        System.out.println("(x1, y1) = (" + x1 + ", " + y1 + ");\n" +
                           "(x2, y2) = (" + x2 + ", " + y2 + ");\n"
                          );
    }
    public void move(int dx, int dy){
        x1 += dx;
        y1 += dy;
        x2 += dx;
        y2 += dy;
    }

    public Rectangle Union(Rectangle rect ){
        return new Rectangle(
                this.x1 < rect.x1 ? this.x1 : rect.x1,
                this.y1 < rect.y1 ? this.y1 : rect.y1,
                this.x2 < rect.x2 ? this.x2 : rect.x2,
                this.y2 < rect.y2 ? this.y2 : rect.y2
        );
    }

    public void draw(Graphics g){
        g.drawRect(x1, y1, x2 - x1, y2- y1);
    }

    public int getX1(){return x1;}
    public int getY1(){return y1;}
    public int getX2(){return x2;}
    public int getY2(){return y2;}

}