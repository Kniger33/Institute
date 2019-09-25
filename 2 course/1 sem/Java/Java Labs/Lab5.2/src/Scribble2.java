import java.awt.*;
import java.applet.*;
import java.awt.event.*;
import java.io.*;
import java.io.ObjectOutputStream;
import java.io.FileOutputStream;
import java.util.ArrayList;

public class Scribble2 extends Applet{

    private int pressX;
    private int pressY;
    private boolean isPressed = false;
    private Rectangle movedRect;
    int x, y;

    private Button rectButton;
    private Button coloredRectButton;
    private Button drawableRectButton;
    private Button loadFromFileButton;
    private Button saveToFileButton;
    private ArrayList<Rectangle> rectArray = new ArrayList<Rectangle>();

    private String path = "C:\\Java Labs\\Lab5.2\\src\\task.txt";

    public void init(){

        rectButton = new Button("Rectangle");
        rectButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                rectArray.add(new Rectangle(125,125,250,250));
                rectArray.get(rectArray.size() - 1).draw(getGraphics());
            }
        });

        coloredRectButton = new Button("Colored Rectangle");
        coloredRectButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                rectArray.add(new ColoredRect(275, 275,355,325, Color.black, Color.red));
                rectArray.get(rectArray.size() - 1).draw(getGraphics());

            }
        });

        drawableRectButton = new Button(("Drawable Rectangle"));
        drawableRectButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                rectArray.add((new DrawableRect(375,200,450,300, Color.green)));
                rectArray.get(rectArray.size() - 1).draw(getGraphics());
            }
        });


        saveToFileButton = new Button("Save to file");
        saveToFileButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try{

                    File file = new File("task");
                    if(file.exists()){file.delete();}
                    System.out.println(file.createNewFile());
                    System.out.println(file.getAbsolutePath());

                    ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(file));
                    oos.writeObject(rectArray);

                }
                catch (FileNotFoundException ex){
                    System.out.println("Невозможно произвести запись в файл " + path);
                }
                catch (IOException ex){
                    System.out.println("Ошибка ввода/вывода" + ex.toString());
                    System.out.println(ex.fillInStackTrace());
                }
            }
        });

        loadFromFileButton = new Button("Load from File");
        loadFromFileButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    File file = new File("task");
                    ObjectInputStream ois = new ObjectInputStream(new FileInputStream(file));
                    rectArray = (ArrayList<Rectangle>) ois.readObject();

                    pressX = 0;
                    pressY = 0;
                    x = 0;
                    y = 0;
                    isPressed = false;
                    movedRect = null;

                    repaint();

                }
                catch (FileNotFoundException ex){
                    System.out.println("Невозможно произвести тение из файла " + path);
                }
                catch (IOException ex ){
                    System.out.println("Ошибка ввода/вывода" + ex.toString());
                }
                catch (ClassNotFoundException ignored){}
            }
        });

        this.add(rectButton);
        this.add(coloredRectButton);
        this.add(drawableRectButton);
        this.add(saveToFileButton);
        this.add(loadFromFileButton);

        this.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                 x = e.getX();
                 y = e.getY();

                super.mousePressed(e);
                for(int i = rectArray.size() - 1; i >= 0; i--){
                    Rectangle rect = rectArray.get(i);

                    if(rect.getX1() <= x &&
                       rect.getX2() >= x &&
                       rect.getY1() <= y &&
                       rect.getY2() >= y   ){
                        movedRect = rect;
                        isPressed = true;
                        pressX = x;
                        pressY = y;

                        break;
                    }
                }
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                super.mouseReleased(e);
                isPressed = false;
                movedRect = null;
            }
        });

        this.addMouseMotionListener(new MouseMotionAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                super.mouseMoved(e);
                if(!isPressed && movedRect == null){return;}

                int dx = e.getX() - pressX;
                int dy = e.getY() - pressY;
                movedRect.move(dx,dy);

                pressX = e.getX();
                pressY = e.getY();

                repaint();
            }
        });


    }
    public void paint(Graphics g){
        for(int i = 0; i < rectArray.size() ; i++){
            rectArray.get(i).draw(g);
        }
    }
}
