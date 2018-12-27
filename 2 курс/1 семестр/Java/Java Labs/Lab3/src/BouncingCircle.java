import java.applet.*;
import java.awt.*;


public class BouncingCircle extends Applet implements Runnable{

    int dx1 = 20, dy1 = 15;
    int dx2 = 13, dy2 = 8;
    int dx3 = 9, dy3 = 4;// Движение круга по горизонт и вертик
    Thread animator;                // Нить, которая осуществляет анимацию
    volatile boolean pleaseStop;    // Флаг остановки движения

    Rectangle [] rect = new Rectangle[30];

    public void paint(Graphics g) {
        //setMassive();
        for(int i = 0; i < rect.length; i++){
            rect[i].draw(g);
        }

        /*g.setColor(Color.red);                    //установка цвета для g
        g.fillOval(x - r, y - r, r * 2, r * 2);     //прорисовка круга*/
    }

    public void setMassive(){
        for(int i = 0; i < 10; i++){
            rect[i] = new Rectangle(25,25);
        }
        for (int i = 10; i < 20; i++){
            rect[i] = new DrawableRect(50,50,100,100, new Color((int) (Math.random() *  0x1000000)));
        }
        for (int i = 20; i < 30; i++){
            rect[i] = new ColoredRect(100,100,150,150, new Color((int) (Math.random() *  0x1000000)), new Color((int) (Math.random() *  0x1000000)));
        }
    }

    //Метод двигает круг и "отражает" его при ударе круга о стенку, затем вызывает перерисовку.
    //Данный метод вызывается многократно анимационным потоком
    public void animate() {

        java.awt.Rectangle bounds = getBounds();         //Получение размера окна программы
        for(int i = 0; i < 10; i++){
            if ((rect[i].x1 + dx1 < 0) || (rect[i].x2 + dx1 > bounds.width)) {
                dx1 = -dx1 - i;
            }
            if ((rect[i].y1 + dy1 < 0) || (rect[i].y2 + dy1 > bounds.height)) {
                dy1 = -dy1 - i;
            }

            rect[i].x1 += dx1 + i;
            rect[i].x2 += dx1 + i;
            rect[i].y1 += dy1 + i;
            rect[i].y2 += dy1 + i;
        }
        for(int i = 10; i < 20; i++){
            if ((rect[i].x1 + dx2 < 0) || (rect[i].x2 + dx2 > bounds.width)) {
                dx2 = -dx2 - i;
            }
            if ((rect[i].y1 + dy2 < 0) || (rect[i].y2 + dy2 > bounds.height)) {
                dy2 = -dy2 - i;
            }

            rect[i].x1 += dx2 + i;
            rect[i].x2 += dx2 + i;
            rect[i].y1 += dy2 + i;
            rect[i].y2 += dy2 + i;
        }
        for(int i = 20; i < 30; i++){
            if ((rect[i].x1 + dx3 < 0) || (rect[i].x2 + dx3 > bounds.width)) {
                dx3 = -dx3 - i;
            }
            if ((rect[i].y1 + dy3 < 0) || (rect[i].y2 + dy3 > bounds.height)) {
                dy3 = -dy3 - i;
            }

            rect[i].x1 += dx3 + i;
            rect[i].x2 += dx3 + i;
            rect[i].y1 += dy3 + i;
            rect[i].y2 += dy3 + i;
        }

//"Просим" браузер вызвать метод paint() для отрисовки круга в новой позиции
        repaint();
    }

    /*Это метод из интерфейса Runnable. Это тело потока исполнения,
осуществляющего анимацию. Сам поток создается и запускается методом start()
*/
    public void run() {
        while (!pleaseStop) {       // Цикл до тех пор, пока не будет команды остановиться.
            animate();              // Обновляем положение и перерисовываем
            try {
                Thread.sleep(100);
            } // Ждем 100 миллисекунд
            catch (InterruptedException e) {      }
        }
    }

    //Запускаем анимацию при запуске апплета браузером
    public void start() {
        setMassive();
        animator = new Thread(this);        // Создаем поток исполнения
        pleaseStop = false;                       // Пока не просим его остановиться
        animator.start();                         // Запускаем поток
    }
    //Останавливаем анимацию, когда браузер останавливает апплет
    public void stop() { pleaseStop = true; }
}
