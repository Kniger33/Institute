using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MazeDataGenerator
{
    // 1.	placementThreshold будет использоваться алгоритмом генерации данных,
    // чтобы определить, является ли пространство пустым
    public float placementThreshold;    // chance of empty space

    public MazeDataGenerator()
    {
        placementThreshold = .1f;                               // 1
    }

    public int[,] FromDimensions(int sizeRows, int sizeCols)    // 2
    {
        int[,] maze = new int[sizeRows, sizeCols];

        int rMax = maze.GetUpperBound(0);
        int cMax = maze.GetUpperBound(1);

        // Приведённый код получает границы двухмерного 2D-массива, после чего проходит через него:

        for (int i = 0; i <= rMax; i++)
        {
            for (int j = 0; j <= cMax; j++)
            {
                // 1    1.	Для определенной ячейки меша, код сперва проверит, находится ли текущая ячейка снаружи меша
                // (то есть, существует ли какой-либо индекс внутри границ конкретного массива). 
                if (i == 0 || j == 0
                    || i == rMax || j == cMax
                    )
                {
                    maze[i, j] = 1;
                }
                // 2
                else if (i % 2 == 0 && j % 2 == 0)
                {
                    if (Random.value > placementThreshold)
                    {
                        // 3
                        maze[i, j] = 1;

                        int a = Random.value < 0.5f ? 0 : (Random.value < 0.5f ? -1 : 1);

                        int b = a != 0 ? 0 : (Random.value < 0.5f ? -1 : 1);

                        maze[i + a, j + b] = 1;

                    }
                }
            }
        }

        return maze;
    }
}

