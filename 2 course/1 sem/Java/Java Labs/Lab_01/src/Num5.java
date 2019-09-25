public class Num5 {
    public static void main(String[] args){
        int num = Integer.parseInt(args[0]);
        for(int i = num - 1; i >= 1; i--){
            num *= i;
        }
        System.out.println(num);
    }
}
