import com.sun.tools.javac.Main;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainFrame extends JFrame{

    NewFrame newFrame;
    JTable table;

    public MainFrame(){

        table = new JTable();

        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("File");

        JMenuItem menuItemCreate = new JMenuItem("Create");
        menuItemCreate.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                newFrame = new NewFrame(table);
                newFrame.setTitle("New Frame");
                newFrame.setVisible(true);
            }
        });

        fileMenu.add(menuItemCreate);

        menuBar.add(fileMenu);
        setJMenuBar(menuBar);

        add(table);
        setSize(500,500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {

        MainFrame frame = new MainFrame();
        frame.setTitle("My Frame");
        frame.setVisible(true);
    }

}
