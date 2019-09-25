public class Four {
    public static void main(String[] args) {
        int a = 1, b = 1, c = a + b;
        for(int i = Integer.parseInt(args[0]); i > 0; i--){
            System.out.print(a + "  ");
            c = a + b;
            a = b;
            b = c;
        }
    }
}
