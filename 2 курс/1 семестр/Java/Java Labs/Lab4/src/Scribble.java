import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class Scribble extends Applet{

    private int last_x, last_y;
    private Color color;

    public void init() {
                // Определяет, создает и регистрирует объект MouseListener.
        this.addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {
                last_x = e.getX();
                last_y = e.getY();
                Graphics g = getGraphics();
               /* if(e.getButton() == MouseEvent.BUTTON1){
                    g.setColor(color);
                    g.fillOval(last_x,last_y,50,50);

                }*/

                if(e.getButton() == MouseEvent.BUTTON3){
                    color = new Color((int)(Math.random() * 0x1000000));
                }
            }
        });
                // Определяет, создает и регистрирует объект MouseMotionListener.

        this.addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e) {
                Graphics g = getGraphics();
                int x = e.getX(), y = e.getY();
                if ((e.getModifiersEx()& MouseEvent.BUTTON1_DOWN_MASK)!=0){
                    g.setColor(color);
                    g.fillOval(last_x,last_y,50,50);
                }
                last_x = x; last_y = y;
            }
        });

        Button b = new Button("Clear");             // Создает кнопку Clear.
                    // Определяет, создает и регистрирует объект слушателя
                    // для обработки события, связанного с нажатием кнопки.
        b.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                    // стирание каракулей
                Graphics g = getGraphics();
                g.setColor(getBackground());
                g.fillRect(0, 0, getSize().width, getSize().height);
            }
        });

        this.add(b);        // Добавляет кнопку в апплет.
    }

}
