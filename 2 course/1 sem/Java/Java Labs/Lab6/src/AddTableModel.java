import javax.swing.*;
import javax.swing.table.AbstractTableModel;

public class AddTableModel extends AbstractTableModel {

    public int getRowCount(){return 10;}

    public int getColumnCount(){return 10;}

    public Object getValueAt(int rowId, int columnId){
        return rowId + columnId;
    }

}
