#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "myFunctions.h"

struct data
{
    int number;
    char second_name[100];
    char first_name[100];
    char patronym[100];
    char sex[20];
    double ball_1;
    double ball_2;
    double ball_3;
    char day[10];
    char month[10];
    int year;
    char tel_num[20];
};

//�������� ���������
int add_student()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int fl = 1;
    struct data stud;
    struct data stud1;

    FILE *fp = fopen("studS.txt", "a+");
    if (fp == NULL)
    {
        fclose(fp);
        return 2;
    }

    printf("��������� ����������: \n���: ");
    scanf("%d", &stud.number);
    int num = -1;

    while(num != stud1.number)
    {
        num = stud1.number;
        fscanf(fp, " %d %s %s %s %s %lf %lf %lf %s %s %d %s \n", &stud1.number, &stud1.second_name, &stud1.first_name, &stud1.patronym, &stud1.sex, &stud1.ball_1, &stud1.ball_2, &stud1.ball_3, &stud1.day, &stud1.month, &stud1.year, &stud1.tel_num);

        if (stud1.number == stud.number)         //���� ����� �������� ����, �� �����
        {
            fclose(fp);
            fl = 0;
            return 1;
        }
    }

    printf("�������: ");
    scanf("%s", stud.second_name);
    printf("���: ");
    scanf("%s", stud.first_name);
    printf("��������: ");
    scanf("%s", stud.patronym);
    printf("���: ");
    scanf("%s", stud.sex);

    printf("���� 1: ");
    scanf("%lf", &stud.ball_1);
    printf("���� 2: ");
    scanf("%lf", &stud.ball_2);
    printf("���� 3: ");
    scanf("%lf", &stud.ball_3);

    printf("���� ��������:\n����: ");
    scanf("%s", &stud.day);
    printf("�����: ");
    scanf("%s", &stud.month);
    printf("���: ");
    scanf("%d", &stud.year);

    printf("����� ��������: ");
    scanf("%s", &stud.tel_num);

    fprintf(fp, " %d %s %s %s %s %lf %lf %lf %s %s %d %s \n", stud.number, stud.second_name, stud.first_name, stud.patronym, stud.sex, stud.ball_1, stud.ball_2, stud.ball_3, stud.day, stud.month, stud.year, stud.tel_num);
    fclose(fp);
    return 0;
}

//������� ���������
int delete_student()
{
    int n, res = 1;
    printf("������� ��� ���������, �������� ���������� �������: ");
    scanf("%d", &n);
    int i = 0, count = 0;
    struct data *student;
    struct data stud1;
 //   struct data stud1;
    student = (struct data*)malloc(count * sizeof(struct data));

    FILE *fp;
    fp = fopen("studS.txt", "rb");
    int num = -1;

    while(num != stud1.number)
    {
        num = stud1.number;
        fscanf(fp, "%d%s%s%s%s%lf%lf%lf%s%s%d%s", &stud1.number, &stud1.second_name, &stud1.first_name, &stud1.patronym, &stud1.sex, &stud1.ball_1, &stud1.ball_2, &stud1.ball_3, &stud1.day, &stud1.month, &stud1.year, &stud1.tel_num);
        if (num == stud1.number)        //���� ����������� �������� ������, ���� ������
        {
            break;
        }
        count++;
    }
    fclose(fp);
    fp = fopen("studS.txt", "rb");

    if (fp == NULL)
    {
        fclose(fp);
        return 2;
    }

    student = (struct data*)realloc(student, count * sizeof(struct data));

    for (i = 0; i < count; i++)
    {
        fscanf(fp, "%d%s%s%s%s%lf%lf%lf%s%s%d%s", &stud1.number, &stud1.second_name, &stud1.first_name, &stud1.patronym, &stud1.sex, &stud1.ball_1, &stud1.ball_2, &stud1.ball_3, &stud1.day, &stud1.month, &stud1.year, &stud1.tel_num);
        student[i] = stud1;
    }
    fclose(fp);
    fp = fopen("studS.txt", "wb");
    for (i = 0; i < count; i++)
    {
        if (student[i].number != n)
        {
        fprintf(fp, " %d %s %s %s %s %lf %lf %lf %s %s %d %s \n", stud1.number, stud1.second_name, stud1.first_name, stud1.patronym, stud1.sex, stud1.ball_1, stud1.ball_2, stud1.ball_3, stud1.day, stud1.month, stud1.year, stud1.tel_num);
        }
        else
        {
            res = 0;
        }
    }
    fclose(fp);
    free(student);
    return res;
}

//����� ���������� �� ����������(���, ���, ���, �����, ����� ������)
int print_students()
{
    printf("��� ��������: \n");
    struct data stud1;
    FILE *fp = fopen("studS.txt", "r");
    if (fp == NULL)
    {
        fclose(fp);
        return 2;
    }

    int num = -1;

    while(num != stud1.number)
    {
        num = stud1.number;
        fscanf(fp, "%d%s%s%s%s%lf%lf%lf%s%s%d%s", &stud1.number, &stud1.second_name, &stud1.first_name, &stud1.patronym, &stud1.sex, &stud1.ball_1, &stud1.ball_2, &stud1.ball_3, &stud1.day, &stud1.month, &stud1.year, &stud1.tel_num);
        double total_ball = stud1.ball_1 + stud1.ball_2 + stud1.ball_3;
        if (num == stud1.number) { break; }
        printf("���: %d\n���: %s %s %s\n���: %s\n���� 1: %0.2lf\n���� 2: %0.2lf\n���� 3: %0.2lf\n����� ����: %0.2lf\n\n", stud1.number, stud1.second_name, stud1.first_name, stud1.patronym, stud1.sex, stud1.ball_1, stud1.ball_2, stud1.ball_3, total_ball);
    }

    fclose(fp);
    return 0;
}

//����� � ���� �������
int print_table()
{
    printf("������� ����������: \n");
    struct data stud1;
    FILE *fp = fopen("studS.txt", "r");
    if (fp == NULL)
    {
        fclose(fp);
        return 2;
    }
    int num = -1;
    while (num != stud1.number)
    {
        printf("_______________________________________\n");
        num = stud1.number;
        fscanf(fp, "%d%s%s%s%s%lf%lf%lf%s%s%d%s", &stud1.number, &stud1.second_name, &stud1.first_name, &stud1.patronym, &stud1.sex, &stud1.ball_1, &stud1.ball_2, &stud1.ball_3, &stud1.day, &stud1.month, &stud1.year, &stud1.tel_num);
        double total_ball = stud1.ball_1 + stud1.ball_2 + stud1.ball_3;
        printf("���:            |%d\n", stud1.number);
        printf("���:            |%s %s %s \n", stud1.second_name, stud1.first_name, stud1.patronym);
        printf("���:            |%s \n", stud1.sex);
        printf("���� 1:         |%0.2lf \n", stud1.ball_1);
        printf("���� 2:         |%0.2lf \n", stud1.ball_2);
        printf("���� 3:         |%0.2lf \n", stud1.ball_3);
        printf("����� ����:     |%0.2lf \n", total_ball);
        printf("���� ��������:  |%s-%s-%d\n", stud1.day, stud1.month, stud1.year);
        printf("����� ��������: |%s\n", stud1.tel_num);
        printf("---------------------------------------\n");
    }
    fclose(fp);
}

//����� ����������, �������� 1-3 �����
void search_students()
{
    struct data stud1;
    FILE *fp;

    int num = -1;
    int max_1_num = 0, max_2_num = 0, max_3_num = 0;
    double max_1_ball = 0, max_2_ball = 0, max_3_ball = 0;
    int i = 0;
    for(i; i < 3; i++)
    {
        fp = fopen("studS.txt", "r");

        if (fp == NULL)
        {
            fclose(fp);
            printf("ERROR");
        }

        while (num != stud1.number)
        {
            num = stud1.number;
            fscanf(fp, "%d%s%s%s%s%lf%lf%lf%s%s%d%s", &stud1.number, &stud1.second_name, &stud1.first_name, &stud1.patronym, &stud1.sex, &stud1.ball_1, &stud1.ball_2, &stud1.ball_3, &stud1.day, &stud1.month, &stud1.year, &stud1.tel_num);

            double total_ball = stud1.ball_1 + stud1.ball_2 + stud1.ball_3;

            if (
                total_ball > max_1_ball
                //&& total_ball <= max_2_ball
                //&& total_ball >= max_3_ball
                )
            {
                max_3_num = max_2_num;
                max_3_ball = max_2_ball;
                max_2_num = max_1_num;
                max_2_ball = max_1_ball;
                max_1_num = stud1.number;
                max_1_ball = total_ball;
                //max_3_num = stud1.number;
                //max_3_ball = total_ball;
                /*max_2 = max_1;
                max_1 = total_ball;*/

            }
            else if (
                     total_ball < max_1_ball
                     && total_ball > max_2_ball
                     //&& total_ball > max_3_ball
                    )
            {
                //max_3 = max_2;
                max_3_num = max_2_num;
                max_3_ball = max_2_ball;
                max_2_num = stud1.number;
                max_2_ball = total_ball;
            }
            else if (
                     //total_ball > max_1_ball
                     total_ball < max_2_ball
                     && total_ball > max_3_ball
                     )
            {
                max_3_num = stud1.number;
                max_3_ball = total_ball;
            }
        }
        fclose(fp);
    }




    for (i = 0; i < 3; i++)
    {
        fp = fopen("studS.txt", "r");

        if (fp == NULL)
        {
            fclose(fp);
            printf("ERROR");
        }

        num = -1;

        while(num != stud1.number)
        {
            num = stud1.number;
            fscanf(fp, "%d%s%s%s%s%lf%lf%lf%s%s%d%s", &stud1.number, &stud1.second_name, &stud1.first_name, &stud1.patronym, &stud1.sex, &stud1.ball_1, &stud1.ball_2, &stud1.ball_3, &stud1.day, &stud1.month, &stud1.year, &stud1.tel_num);
            //printf("I = %d %d %d\n", i, num, stud1.number);
            if (i == 0
                && stud1.number == max_1_num
               )
            {
                printf("\n����� ������ �����: \n");
                printf("���:            |%d\n", stud1.number);
                printf("���:            |%s %s %s \n", stud1.second_name, stud1.first_name, stud1.patronym);
                printf("���:            |%s \n", stud1.sex);
                printf("���� 1:         |%0.2lf \n", stud1.ball_1);
                printf("���� 2:         |%0.2lf \n", stud1.ball_2);
                printf("���� 3:         |%0.2lf \n", stud1.ball_3);
                printf("����� ����:     |%0.2lf \n", max_1_ball);
                printf("���� ��������:  |%s-%s-%d\n", stud1.day, stud1.month, stud1.year);
                printf("����� ��������: |%s\n", stud1.tel_num);
                printf("---------------------------------------\n");
                break;
            }
            if  (i == 1 &&
                      stud1.number == max_2_num
                     )
                {
                    printf("\n����� ������ �����: \n");
                    printf("���:            |%d\n", stud1.number);
                    printf("���:            |%s %s %s \n", stud1.second_name, stud1.first_name, stud1.patronym);
                    printf("���:            |%s \n", stud1.sex);
                    printf("���� 1:         |%0.2lf \n", stud1.ball_1);
                    printf("���� 2:         |%0.2lf \n", stud1.ball_2);
                    printf("���� 3:         |%0.2lf \n", stud1.ball_3);
                    printf("����� ����:     |%0.2lf \n", max_2_ball);
                    printf("���� ��������:  |%s-%s-%d\n", stud1.day, stud1.month, stud1.year);
                    printf("����� ��������: |%s\n", stud1.tel_num);
                    printf("---------------------------------------\n");
                    break;
                }
           if  (i == 2 &&
                      stud1.number == max_3_num
                    )
                {
                    printf("\n����� ������ �����: \n");
                    printf("���:            |%d\n", stud1.number);
                    printf("���:            |%s %s %s \n", stud1.second_name, stud1.first_name, stud1.patronym);
                    printf("���:            |%s \n", stud1.sex);
                    printf("���� 1:         |%0.2lf \n", stud1.ball_1);
                    printf("���� 2:         |%0.2lf \n", stud1.ball_2);
                    printf("���� 3:         |%0.2lf \n", stud1.ball_3);
                    printf("����� ����:     |%0.2lf \n", max_3_ball);
                    printf("���� ��������:  |%s-%s-%d\n", stud1.day, stud1.month, stud1.year);
                    printf("����� ��������: |%s\n", stud1.tel_num);
                    printf("---------------------------------------\n");
                    break;
                }
        }
        fclose(fp);
    }
    /*printf("����� ������ ����� � ������ %0.2lf ������: %d\n", max_1_ball, max_1_num);
    printf("����� ������ ����� � ������ %0.2lf ������: %d\n", max_2_ball, max_2_num);
    printf("����� ������ ����� � ������ %0.2lf ������: \n", max_3_ball);*/

}

//������� ������� ���������� ���������
double average_age()
{
    struct data stud1;
    FILE *fp = fopen("studS.txt", "r");
    if (fp == NULL)
    {
        printf("\n���������� ������� ����\n");
        fclose(fp);
    }

    int num = -1, count = 0;
    double sum = 0;
    while (num != stud1.number)
    {
        num = stud1.number;
        count++;
        fscanf(fp, "%d%s%s%s%s%lf%lf%lf%s%s%d%s", &stud1.number, &stud1.second_name, &stud1.first_name, &stud1.patronym, &stud1.sex, &stud1.ball_1, &stud1.ball_2, &stud1.ball_3, &stud1.day, &stud1.month, &stud1.year, &stud1.tel_num);
        sum += 2018.0 - stud1.year;
    }

    return sum / count;
}

//���������� ���������� �������� ����, ���������� � 2003�.
int male_func()
{
    struct data stud1;
    FILE *fp = fopen("studS.txt", "r");
    if (fp == NULL)
    {
        printf("\n���������� ������� ����\n");
        fclose(fp);
    }

    int male_counter = 0;
    int num = -1;

    while (num != stud1.number)
    {
        num = stud1.number;
        fscanf(fp, "%d%s%s%s%s%lf%lf%lf%s%s%d%s", &stud1.number, &stud1.second_name, &stud1.first_name, &stud1.patronym, &stud1.sex, &stud1.ball_1, &stud1.ball_2, &stud1.ball_3, &stud1.day, &stud1.month, &stud1.year, &stud1.tel_num);
        if  (
            strcmp(stud1.sex, "�������") == 0
            &&  stud1.year == 2003
            )
        {
            male_counter++;
        }

    }

    return male_counter;
}

