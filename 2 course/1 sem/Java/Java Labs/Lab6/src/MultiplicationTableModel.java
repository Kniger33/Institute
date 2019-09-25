import javax.swing.table.AbstractTableModel;

public class MultiplicationTableModel extends AbstractTableModel {

    public int getRowCount(){return 9;}

    public int getColumnCount(){return 9;}

    public Object getValueAt(int rowId, int columnId){
        return ++rowId * ++columnId;
    }

}

