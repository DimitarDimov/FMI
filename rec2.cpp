#include <iostream>

using namespace std;

// ����������� �� ���������� ����� � ������� ������ �������
void printBinary(int number)
{
    if (number > 2)
    printBinary(number / 2);
    cout << number % 2;   //6->0, 3->1, 1->1
}

// ��������� ��������
// �� ���������� ������ ������ � n ��������, ����� ��
// ����� � ����� �� 0 �� k-1.

int vector[100];
int k, n;

void print(int *array, int count)
{
    for (int i = 0; i < count; i++)
        cout << array[i] << ' ';
    cout << endl;
}

void generate(int start)
{
    // ����
    if (start >= n) {
        print(vector, n);
        return;
    }

    for(int i = 0; i < k; i++)
    {
        vector[start] = i;
        generate(start + 1);
    }
}

// �����������: ���� n <= k; �� �� ���������
// ���� ������ ������, � ����� ���� ���������� (��������)
// ����: � ������ �� for �� ��� �������� ���� ������� i
// ��� ��� �� � ���������� ��� vector (� ������� �� 0 ��
// start-1) � ���� ������ �� �� ��������� ��������� ����

// 1 (true) - ��������� ������, 0 (false) - �����
bool labyrinth[8][8]= {
    1, 0, 1, 1, 1, 1, 1, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 1, 1, 0, 1, 1, 0, 1,
    0, 0, 0, 1, 1, 1, 0, 1,
    1, 1, 1, 1, 1, 1, 0, 1,
    1, 1, 1, 1, 1, 0, 0, 1,
    1, 1, 1, 1, 1, 0, 1, 1,
    1, 1, 1, 1, 1, 0, 1, 1
};

int endRow, endCol; // ���������� �� �������� ������

// ��� �� ��� �� ������ ������� ������ �� ������ ������ ������
bool way(int startRow, int startCol)
{
    // ��� ��������� ������ � ����� ���������
    if (startRow < 0 || startCol < 0 ||
        startRow >= 8 || startCol >= 8)
            return false;

    // ��� �������� ������ � �����������
    if (!labyrinth[startRow][startCol])
        return false;

    // ��������� � �������� ������ �������� - �������� ��� ���
    if (startRow == endRow && startCol == endCol)
        return true;

    // ��������� �������� ������ ���� �����������,
    // �� �� �� ��������!
    labyrinth[startRow][startCol] = false;

    // ��� ��� ��� �� ����� �� ��������� ������ �� ����,
    // �� ����� � �� �������� ��� (=> true)
    return way(startRow - 1, startCol)
        || way(startRow + 1, startCol)
        || way(startRow, startCol - 1)
        || way(startRow, startCol + 1);
}

// �������� �� ������� �� �����:
// (�� � �������� � ����������)
int reverseDigits(int number)
{
    int result = 0;

    do {
        result = result * 10 + number % 10;
        number /= 10;
    }
    while (number != 0);

    return result;
}

int main()
{
     printBinary(6);

    //cin >> k >> n;
    //generate(0);

    //endRow = endCol = 7;
    //cout << way(0, 0) << endl;

    //cout << reverseDigits(123) << endl;

    return 0;
}
