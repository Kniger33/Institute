#include <cstdlib>
#include <iostream>
#include <locale>
#include <ctime>

struct unsigned_short_2
{
    unsigned short a, b;
};

unsigned length_true(signed char *a, unsigned short l)
{
    unsigned res = 0;
    for (int i = 0; i < l; i++)
    {
        if (a[i])
        {
            res++;
        }
    }
    return res;
}

int minimize_weight(signed char *a, unsigned short l)
{
    int i, j, k;
    while (true)
    {
        i = 0;
        while ((i < l - 1) && ((a[i] == 0) || (a[i + 1] == 0)))
        {
            i++;
        }
        if (i == l - 1)
        {
            break;
        }
        if (a[i] != a[i + 1])
        {
            a[i] = a[i + 1];
            a[i] = 0;
        }
        else
        {
            bool ind;
            j = i + 1;
            while (true)
            {
                ind = true;
                for (k = i; k < j - 1; k++)
                {
                    if (a[k] != a[k + 1])
                    {
                        ind = false;
                    }
                }
                if ((a[j] != a[i]) && ind)
                {
                    break;
                }
                j++;
            }
            if (a[j] == 0)
            {
                a[j] = a[i];
            }
            else
            {
                a[j] = 0;
            }
            a[i] *= -1;
            for (k = i + 1; k < j; k++)
            {
                a[k] = 0;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    if (argc != 3)
    {
        std::cerr << "Incorrect syntax (correct: \"Lab10 l n\")";
        return 1;
    }
    unsigned short l = strtol(argv[1], NULL, 10);
    unsigned short n = strtol(argv[2], NULL, 10);
    signed char *buf = new signed char[l];
    unsigned_short_2 *res = new unsigned_short_2[n];
    float avg_a = 0;
    float avg_b = 0;
    int i, j;
    char *str;
    srand(time(NULL));
    try
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < l; j++)
            {
                buf[j] = rand() % 2;
            }
            res[i].a = length_true(buf, l);
            avg_a += res[i].a;
            minimize_weight(buf, l);
            res[i].b = length_true(buf, l);
            avg_b += res[i].b;
            std::cout << res[i].a << " -> " << res[i].b << std::endl;
        }
        avg_a /= n;
        avg_b /= n;
        std::cout << "---" << std::endl;
        std::cout << avg_a << " -> " << avg_b << std::endl;
    }
    catch (std::exception &Ex)
    {
        std::cerr << Ex.what() << std::endl;
    }
    delete[] buf;
    delete[] res;
}
