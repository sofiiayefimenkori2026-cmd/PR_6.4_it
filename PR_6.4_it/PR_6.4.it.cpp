// PR_6.4.it.cpp
// Варіант 8 (ітераційний спосіб)
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void Input(double* a, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void Print(const double* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(8) << fixed << setprecision(2) << a[i];
    cout << endl;
}

int MinIndex(const double* a, const int size)
{
    int minIdx = 0;
    for (int i = 1; i < size; i++)
    {
        if (a[i] < a[minIdx])
            minIdx = i;
    }
    return minIdx;
}

double SumBetweenNegatives(const double* a, const int size)
{
    int firstIdx = -1;
    int secondIdx = -1;

    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            if (firstIdx == -1)
                firstIdx = i;
            else if (secondIdx == -1)
            {
                secondIdx = i;
                break;
            }
        }
    }

    if (firstIdx == -1 || secondIdx == -1 || secondIdx <= firstIdx + 1)
        return 0.0;

    double sum = 0.0;
    for (int i = firstIdx + 1; i < secondIdx; i++)
        sum += a[i];

    return sum;
}

void Transform(double* a, const int size)
{
    int insertPos = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] >= -1.0 && a[i] <= 1.0)
        {
            for (int j = i; j > insertPos; j--)
            {
                double tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
            insertPos++;
        }
    }
}

#if !defined(_WINDLL)
int main()
{
    int n;
    cout << "Enter array size n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid size!" << endl;
        return 1;
    }

    double* a = new double[n];
    Input(a, n);

    cout << "\nOriginal array:" << endl;
    Print(a, n);

    int minIdx = MinIndex(a, n);
    cout << "\n1.1. Index of minimum element: " << minIdx 
         << " (value = " << a[minIdx] << ")" << endl;

    double sumBetween = SumBetweenNegatives(a, n);
    cout << "1.2. Sum of elements between 1st and 2nd negatives: " 
         << sumBetween << endl;

    Transform(a, n);
    cout << "\n2. Transformed array (|a[i]| <= 1 first):" << endl;
    Print(a, n);

    delete[] a;
    return 0;
}
#endif
