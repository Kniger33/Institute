public class Five {
    public static void main(String[] args) {
        int a = 0, res = 1;
        a = Integer.parseInt(args[0]);
        for (int i = Integer.parseInt(args[0]); i > 0; i--){
            res *= i;
        }
        System.out.print("RES = " + res);
    }
}
