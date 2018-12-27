// дин. массив безразмерный
// вывод массива : списком 1: -1 -2 -4 ; 2: 0 3 4 и т.д.
// инициализаци€ люба€
//
 #include <stdio.h>
 #include <stdlib.h>
 #include <locale.h>

 int main()
 {
    setlocale(LC_ALL, "Rus");
    int **ptrInt;
    int i, j, n, *m;

    printf("¬ведите количество строк: ");
    scanf("%d", &n);

    ptrInt = (int**)malloc(n * sizeof(int*));
    m = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("¬ведите количество столбцов строки %d: ", i);
        scanf("%d", &m[i]);

        ptrInt[i] = (int*)malloc(m[i] * sizeof(int));

        for (j = 0; j < m[i]; j++)
        {
            printf("a[%d][%d]= ", i, j);
            scanf("%d", &ptrInt[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m[i]; j++)
        {
            printf("%d ", ptrInt[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        free(ptrInt[i]);
    }
    free(ptrInt);
    free(m);

    return 0;

 }
