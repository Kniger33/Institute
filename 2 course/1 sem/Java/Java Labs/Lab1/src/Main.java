

public class Main {
    public static void main(String[] args) {
        System.out.print("FirstTask:  " + "\n");

        for(int i = 0;i < args.length; i++ ){
            System.out.print(args[i]);
        }
        System.out.print("\n\n" + "SecondTask: " + "\n");

        secondTask();

        System.out.print("\n\n" + "ThirdTask: " + "\n");

        for(int i = args.length - 1; i >= 0; i--){
            for(int j = args[i].length() - 1; j >= 0; j--)
            {
                System.out.print(args[i].charAt(j));
            }
            System.out.print(" ");
        }
    }

    static void secondTask(){
        for(int i = 1; i <= 500; i++){
            if (i % 5 == 0){
                System.out.println("fizz  ");
            }
            else if (i % 7 == 0){
                System.out.println("fizzbuzz  ");
            }
            else {
                System.out.println(i + "  ");
            }
        }
    }

}
