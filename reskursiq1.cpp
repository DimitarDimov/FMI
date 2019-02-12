#include <iostream>

using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

void test(int n)
{
    cout << "Before: " << n << endl;
    if (n > 0) test(n - 1);
    cout << "After: " << n << endl;
}

double power(double x, int n)
{
    if (n < 0)
        return 1.0 / power(x, -n);
    if (n == 0)
        return 1.0;
    return x * power(x, n - 1);
}

// ����� �� ��������
// 0 1 1 2 3 5 8 ... - ������� ��� �� 0 � 1, � ����� ��������
// � ���� �� ���������� ���
// ����������� �������, ���������� ��������� ��������:
int fib(int n) // ������ n-���� ����� �� ��������
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// �������: ���������� ������� �� ������ � ������

// 1. ���� �� ���������� �� ����� �� double:
double sum(double array[], int size)
{
    if (size <= 0)
        return 0;
    return array[0] + sum(array + 1, size - 1);
}

// 2. �������� �� ������������ �� �������:
bool contains(double array[], int size, double value)
{
    if (size <= 0)
        return false;
    return array[0] == value
        || contains(array + 1, size - 1, value);
    // ��� ������ ���� �� ����������� � �����, �������
    // �� �� �����
}

// 3. �������� �� ��������� ����������:
bool isAscending(double array[], int size)
{
    if (size <= 1)
        return true;
    return array[0] < array[1]
        && isAscending(array + 1, size - 1);
}

// 4. �������� ���� ������ �������� �� ��������:
bool areUnique(double array[], int size)
{
    if (size <= 1)
        return true;
    return !contains(array + 1, size - 1, array[0])
        && areUnique(array + 1, size - 1);
}

int main()
{
    //cout << fact(5) << endl;
    // test(3);
     cout << fib(6) << endl;
    return 0;
}
