public class Test {
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle();
        Rectangle r2 = new Rectangle(1,1,2,2);
        Rectangle r3 = new Rectangle(5,5);

        r1.rect_print();
        r2.rect_print();
        r3.rect_print();
        r1.move(1,10);
        r2.move(5,7);
        r3.move(3,3);
        r1.rect_print();
        r2.rect_print();
        r3.rect_print();
        r2.Union(r1).rect_print();
        r2.rect_print();
    }



}
