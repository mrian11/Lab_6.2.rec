#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int* create(int n, const int Low, const int High, int* a = 0, int i = 0)
{
    if (a == 0) 
    {
        a = new int[n];
    }

    if (i < n) 
    {
        a[i] = Low + rand() % (High - Low + 1);
        create(n, Low, High, a, i + 1);
    }

    return a;
}

int Max(int* a, const int size, int i, int max)
{
    if (a[i] > max)
        max = a[i];
    if (i < size - 1)
        return Max(a, size, i + 1, max);
    else
        return max;
}

int Min(int* a, const int size, int i, int min)
{
    if (a[i] < min)
        min = a[i];
    if (i < size - 1)
        return Min(a, size, i + 1, min);
    else
        return min;
}
void print(int* a, int n, int i = 0) {
    if (i < n) {
        cout << setw(5) << a[i];
        print(a, n, i + 1);
    }
    else {
        cout << endl;
    }
}


int Average(int* a, const int n)
{
    int max = Max(a, n, 1, a[0]);
    int min = Min(a, n, 1, a[0]);

    return (max + min) / 2;

}

int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;

    srand((unsigned)time(NULL));
    int Low = 1;
    int High = 100;

    int* a = create(n, Low, High);
    print(a, n);

    int average = Average(a, n);
    cout << "Average of elements: " << average << endl;
    cout << "max = " << Max(a, n, 1, a[0]) << endl;
    cout << "min = " << Min(a, n, 1, a[0]) << endl;
    delete[] a; // Звільнення пам'яті

    return 0;
}
