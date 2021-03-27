#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>

using namespace std;

void print_A0 (bool* A, bool* B, const int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << A[i * n + j];
        }
        cout << ' ' << B[i] << endl;
    }
}

bool is_traingle_matrix (bool* A, const int n)
{
    int i, j;
    bool is_t_m = true;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (A[i * n + j])
            {
                is_t_m = false;
                break;
            }
        }
        if (!is_t_m)
        {
            break;
        }
    }
    return is_t_m;
}

int Gauss_bool (bool* A, bool* B, bool* X, const int n, int& rang)
{
    int i, i_swap, j, k, l;
    bool swapie;
    j = 0;
    while ((!is_traingle_matrix (A, n)) && (j < n))
    {
        i_swap = -1;
        for (i = j; i < n; i++)
        {
            if (A[i * n + j])
            {
                i_swap = i;
                break;
            }
        }
        if (i_swap >= 0)
        {
            for (k = 0; k < n; k++)
            {
                swapie = A[j * n + k];
                A[j * n + k] = A[i_swap * n + k];
                A[i_swap * n + k] = swapie;
            }
            swapie = B[j];
            B[j] = B[i_swap];
            B[i_swap] = swapie;
            for (k = j + 1; k < n; k++)
            {
                if (A[k * n + j])
                {
                    for (l = j; l < n; l++)
                    {
                        A[k * n + l] ^= A[j * n + l];
                    }
                    B[k] ^= B[j];
                }
			}
        }
        cout << "->" << endl;
        print_A0 (A, B, n);
        j++;
    }
    int zero_rows = 0;
    bool inconsistent = false;
    bool have_true;
    for (i = 0; i < n; i++)
    {
         have_true = false;
         for (j = 0; j < n; j++)
         {
             have_true |= A[i * n + j];
             if (have_true)
             {
				 break;
             }
         }
         if (!have_true)
         {
             zero_rows++;
             if (B[i])
             {
                 inconsistent = true;
             }
         }
    }
    rang = n - zero_rows;
    if (inconsistent)
    {
        return 0;
    }
    if (zero_rows > 0)
    {
        return pow (2, zero_rows);
    }
    for (i = n - 1; i >= 0; i--)
    {
        X[i] = B[i];
        for (j = i + 1; j < n; j++)
        {
            X[i] ^= A[i * n + j] && X[j];
        }
    }
    return 1;
}

int main (int argc, char* argv[])
{
    setlocale (LC_ALL, "Russian");
    if (argc != 3) {
        cerr << "Incorrect syntax (correct: \"command filename n\")";
        return 1;
    }
    int n = strtol (argv[2], nullptr, 10);
    bool* A = new bool [n * n];
    bool* B = new bool [n];
    bool* X = new bool [n];
    try
    {
        ifstream input_file (argv[1]);
        int i, j;
        char c;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                input_file >> c;
                A[i * n + j] = (c != '0');
            }
            input_file >> c;
            B[i] = (c != '0');
        }
        input_file.close();
        print_A0 (A, B, n);
        int system_rank;
        int n_solutions = Gauss_bool (A, B, X, n, system_rank);
        cout << "Solutions quantity: " << n_solutions << endl;
        if (n_solutions == 1)
        {
            for (i = 0; i < n; i++)
                cout << (X[i]) << ' ';
            cout << endl;
        }
        cout << "System rank: " << system_rank << endl;
    }
    catch (exception& Ex)
    {
        cerr << Ex.what() << endl;
    }
    delete [] A;
    delete [] B;
    delete [] X;
}
