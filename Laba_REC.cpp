// Lab_7_3.cpp
// Нюл Василь
// Лабораторна робота No 7.3.
// Опрацювання динамічних багатовимірних масивів. Рекурсивний спосіб.
// Варіант 7

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    a[i][j] = Low + rand() % (High-Low+1);
    if (j<colCount-1)
        Create(a, rowCount, colCount, Low, High, i, j+1);
        if (i<rowCount-1)
           Create(a, rowCount, colCount, Low, High, i+1, 0);
}
void PrintRow(int** a, const int i, const int colCount, int j)
{
    cout << setw(4) << a[i][j];
    if ( j < colCount-1 )
        PrintRow(a, i, colCount, j+1);
    else
        cout << endl;
}
void PrintArr(int** a, const int rowCount, const int colCount, int i)
{
    PrintRow(a, i, colCount, 0);
    if ( i < rowCount-1 )
        PrintArr(a, rowCount, colCount, i+1);
    else
        cout << endl;
}

void VidemRow(int** a, const int colCount, bool& result, int j, int i, int& k_videm)
{
    if ( a[i][j] < 0 )
        {
            result = true;
            k_videm++;
        }
    else
        if ( j < colCount-1 )
            VidemRow(a, colCount, result, j+1, i, k_videm);
}
void SumInRows(int** a, const int colCount, int& S, int j, int i)
{
        S += a[i][j];
    if ( j < colCount-1 )
        SumInRows(a, colCount, S, j+1, i);
}
void SumRows(int** a, const int rowCount, const int colCount, int& S, bool& result, int i)
{
    int k_videm = 0;
    VidemRow(a, colCount, result, 0, i, k_videm);
    if (  k_videm > 0 )
    {
        k_videm = 0;
        SumInRows(a, colCount, S, 0, i);
    }
    if ( i < rowCount-1 )
        SumRows(a, rowCount, colCount, S, result, i+1);
}
int main()
{
    srand((unsigned) time(NULL));
    int Low  = -3;
    int High = 10;
    int n;
    cout << "n = "; cin >> n;
    const int rowCount = n;
    const int colCount = n;
    
    int **a = new int*[rowCount];
    for (int i=0; i<rowCount; i++)
        a[i] = new int[colCount];
    
    Create(a, rowCount, colCount, Low, High, 0, 0);
    PrintArr(a, rowCount, colCount, 0);
    
    int S = 0;
    bool result = false;
    SumRows(a, rowCount, colCount, S, result, 0);
    if( result )
        cout << "S = " << S << endl;
    else
        cout << "Тут не має від^ємних елементів" << endl;
        cout << endl;
    
    
    for (int i=0; i<rowCount; i++)
            delete [] a[i];
        delete [] a;
    return 0;

}
