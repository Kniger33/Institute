/*
* осуществить запись в файл большого произвольного массива данных, используя бинарные потоки, двумя способами: запись без и
запись с использованием классов-фильтров, позволяющих выполнить буферизацию. Произвести замеры времени выполнения
записи в файл и сравнить полученное ускорение. Указание: для отсчета времени в миллисекундах необходимо использовать
системную функцию следующим образом: long timeStart =System.currentTimeMillis(). То же самое проделать для операции
считывания данных из файла.
*
* */


import java.io.*;
import java.nio.charset.StandardCharsets;

public class Write_Read {

    public static void main(String[] args) {

        String path = "C:\\Java Labs\\Lab5\\test.txt";
        String data = "Pain!You made me a, you made me a beliver, beliver!Pain!You break me down and build me up, beliver" +
                "beliver!Pain!I let the bullets fly, oh let them rain, my love, my luck, my drive, it came from..." +
                "Pain!You made me a, you made me a beliver, beliver!";
        byte[] bytesToWrite = data.getBytes();
        byte[] bytesToRead = new byte[1024];

        long timeStart, timeStart2;
        try {

            timeStart = System.currentTimeMillis();

            FileOutputStream fileOutputStream = new FileOutputStream(path);
            fileOutputStream.write(bytesToWrite);
            fileOutputStream.close();

            System.out.println("To write: " + bytesToWrite.toString());

            FileInputStream fileInputStream = new FileInputStream(path);
            int bytesAvaible = fileInputStream.available();
            int count = fileInputStream.read(bytesToRead, 0, bytesAvaible);
            fileInputStream.close();
            ////
            data = new String(bytesToRead, StandardCharsets.UTF_8);
            ////
            System.out.println("Readed: " + data);
            System.out.println("Time: " + timeStart * 0.001);
        }
        catch (FileNotFoundException e){
            System.out.println("Невозможно произвести запись в файл " + path);
        }
        catch (IOException e){
            System.out.println("Ошибка ввода/вывода" + e.toString());
        }

        FileWriter fw = null;
        BufferedWriter bw = null;
        FileReader fr = null;
        BufferedReader br = null;

        try{

            timeStart2 = System.currentTimeMillis();

            fw = new FileWriter(path);
            bw = new BufferedWriter(fw);

            bw.write(data);
            bw.close();
            System.out.println("BUFFWRITE COMPLETE");

            fr = new FileReader(path);
            br = new BufferedReader(fr);

            String s = null;
            int count = 0;

            s = br.readLine();
            br.close();
            System.out.println("BUFFREAD COMPLETE: \n" + s);

            System.out.println("Time_2: " + timeStart2 * 0.001);
        }
        catch (FileNotFoundException e){
            System.out.println("Невозможно произвести запись в файл " + path);
        }
        catch (IOException e){
            System.out.println("Ошибка ввода/вывода" + e.toString());
        }





    }
}
