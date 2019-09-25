using System;


namespace XMLRPCClient
{
    class Program
    {
        static ServersideObject obj;
        
        static void Main(string[] args) {
            int size;
            size = int.Parse(Console.ReadLine());

            int[,] matrix = new int[size, size];
            
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    matrix[i, j] = int.Parse(Console.ReadLine());
                }
            }
            
            obj = new ServersideObject("http://127.0.0.1:5050");
            
            obj.SendMatrix(size, matrix);
            
            Console.ReadLine();
        }
    }
}
