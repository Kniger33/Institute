import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class NewFrame extends JFrame {

    public NewFrame(JTable table){

        JRadioButton rbAdd = new JRadioButton("Additional Table");
        JRadioButton rbMult = new JRadioButton("Multiplication Table");

        ButtonGroup buttonGroup = new ButtonGroup();
        buttonGroup.add(rbAdd);
        buttonGroup.add(rbMult);

        JButton okButton = new JButton("OK");
        okButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(rbAdd.isSelected()){
                    table.setModel(new AddTableModel());
                }
                else {
                    table.setModel(new MultiplicationTableModel());
                }

                setVisible(false);
                dispose();
            }
        });

        add(rbAdd);
        add(rbMult);
        add(okButton);

        setLayout(new GridLayout(0,1));

        pack();
        setResizable(false);
        setSize(200,200);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}
