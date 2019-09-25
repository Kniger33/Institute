#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Matrix{
protected:
    int row;
    double **mat;
public:
    Matrix(){}

    Matrix(int row1) : row(row1){
        mat = new double*[row];
        for (int i = 0; i < row; i++){
            mat[i] = new double[row];
        }
    }

    void showInfo(){
        for (int i = 0; i < row; i++){
            for (int j = 0; j < row; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    friend istream& operator>>(istream& write, Matrix& mt){
        cout << "Введите массив: " << endl;
        for (int i = 0; i < mt.row; i++){
            for (int j = 0; j < mt.row; j++){
                write >> mt.mat[i][j];
            }
        }
        return write;
    }

    friend ostream& operator<<(ostream& write, Matrix& mt){
        for (int i = 0; i < mt.row; i++){
            for (int j = 0; j < mt.row; j++){
                write << mt.mat[i][j] << " ";
            }
            cout << endl;
        }
        write << endl;
        return write;
    }

    friend ofstream& operator<<(ofstream& write, Matrix& mt){
        for (int i = 0; i < mt.row; i++){
            for (int j = 0; j < mt.row; j++)
                write << mt.mat[i][j] << " ";
            write << endl;
        }

        return write;
    }

    friend ifstream& operator>>(ifstream& write, Matrix& mt){
        for (int i = 0; i < mt.row; i++)
            for (int j = 0; j < mt.row; j++)
                write >> mt.mat[i][j];

        return write;
    }

    Matrix operator=(const Matrix&);

    Matrix operator+(const Matrix&);

    Matrix operator+=(const Matrix&);

    Matrix operator-(const Matrix&);

    Matrix operator-=(const Matrix&);

    Matrix& operator--();//префиксный

    Matrix operator--(int);//постфиксный

    Matrix& operator++();//префиксный

    Matrix operator++(int);//постфиксный

    Matrix operator*(const Matrix&);

};

/*class Double{
private:
    int row;
    double **mt;
public:
    void setArr(const Matrix& mat){
        for (int i = 0; i < mat.row; i++)
            for (int j = 0; j < mat.row; j++)
                mt[i][j] = mat[i][j];
    }
    operator Double(){
        for (int i = 0; i < row; i++)
            for (int j = 0; j < row; j++)
                mt[i][j] *= 1.000;

        return Double(mt);
    }
};*/

Matrix Matrix::operator+(const Matrix& mt){
    Matrix res(*this);
    if (this->row != mt.row){
        cout << "Матрицы разного размера" << endl;
        exit(1);
    }
    for (size_t i = 0; i < mt.row; i++){
        for (size_t j = 0; j < mt.row; j++){
            res.mat[i][j] = mat[i][j] + mt.mat[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator+=(const Matrix& mt){
    if (row != mt.row){
        cout << "Матрицы разного размера!" << endl;
        exit(1);
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < row; j++)
            mat[i][j] += mt.mat[i][j];

    return *this;
}

Matrix Matrix::operator-(const Matrix& mt){
    Matrix res(*this);
    if (this->row != mt.row){
        cout << "Матрицы разного размера" << endl;
        exit(1);
    }
    for (size_t i = 0; i < mt.row; i++){
        for (size_t j = 0; j < mt.row; j++){
            res.mat[i][j] = mat[i][j] - mt.mat[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator-=(const Matrix& mt){
    if (row != mt.row){
        cout << "Матрицы разного размера!" << endl;
        exit(1);
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < row; j++)
            mat[i][j] -= mt.mat[i][j];

    return *this;
}

Matrix& Matrix::operator--(){
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->row; j++)
            this->mat[i][j] -= 0.01;

    return *this;
}

Matrix Matrix::operator--(int){
    Matrix temp = *this;
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->row; j++)
            this->mat[i][j] -= 0.01;
    return temp;
}

Matrix& Matrix::operator++(){
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->row; j++)
            this->mat[i][j] += 0.01;

    return *this;
}

Matrix Matrix::operator++(int){
    Matrix temp = *this;
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->row; j++)
            this->mat[i][j] += 0.01;
    return temp;
}

Matrix Matrix::operator=(const Matrix& mt){
    if (&mt != this){
        if (row != mt.row){
            delete []mat;
            row = mt.row;
            mat = new double*[row];

            for (int i = 0; i < row; i++)
                mat[i] = new double[row];
        }

        for (int i = 0; i < row; i++)
            for (int j = 0; j < row; j++)
                mat[i][j] = mt.mat[i][j];
    }

    return *this;
}

Matrix Matrix::operator*(const Matrix& mt){
    Matrix res(row);
    if (row != this->row){
        cout << "Матрицы не подходят для умножения!" << endl;
        exit(1);
    }
    for (int i = 0; i < res.row; i++)
        for (int j = 0; j < res.row; j++)
            for (int k = 0; k < row; k++)
                res.mat[i][j] += mat[i][k] * mt.mat[k][j];

    return res;
}

int main()
{
    int row;
    ofstream fout("data.txt", ios_base::app);
    ifstream fin("data.txt", ios_base::in);
    cin >> row;
    Matrix a(row), b(row), c(row), d(row);
    fin >> a >> b >> c >> d;
    //b = a;
    /*b = b + a;
    cout << b;
    b += a;
    cout << endl;
    cout << b;*/
    //b--;
    //b = b * a;
    cout << a << b << c << d;
    //fout << b << a;
    fout.close();
    fin.close();
    return 0;
}
