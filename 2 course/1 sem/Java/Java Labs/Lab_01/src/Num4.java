public class Num4 {
    public static void main(String[] args){
        int cnt = Integer.parseInt(args[0]);
        int mas[] = new int[cnt];
        if(cnt == 1){
            System.out.println("1");
        } else{
            if(cnt == 2){
                System.out.println("1 1");
            } else{
                mas[0] = 1;
                mas[1] = 1;
                System.out.print("1 1 ");
                for(int i = 2; i < cnt; i++){
                    mas[i] = mas[i-1] + mas[i-2];
                    System.out.print(mas[i]);
                    System.out.print(" ");
                }
            }
        }

    }
}
