#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{
    setlocale(LC_ALL, "Rus");
    int i, j, n, m, item, count = 0;
    printf("���-�� �����:");
    scanf("%d", &n);

    printf("���-�� ��������:");
    scanf("%d", &m);

    int mas[n][m];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("mas[%d][%d] = ", i, j);
            scanf("%d", &mas[i][j]);
        }
    }

    printf("������� ��-�: ");
    scanf("%d", &item);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", mas[i][j]);

        }
        printf("\n");
    }

    for(i = 0; i < n; i++ )
    {
        for(j = 0; j < m; j++)
        {
            if ( mas[i][j]  == item  )
        {
            printf("����� ��-��: ������: %d �������: %d\n", i,j);
            count++;
        }
        }
    }

    if (count == 0)
    {
        printf("-1");
    }
    return 0;
}
