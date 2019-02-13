#include <iostream>

using namespace std;

// отпечатване на естествено число в двоична бройна система
void printBinary(int number)
{
    if (number > 2)
    printBinary(number / 2);
    cout << number % 2;   //6->0, 3->1, 1->1
}

// нелинейна рекурсия
// да генерираме всички редици с n елемента, всеки от
// които е число от 0 до k-1.

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
    // дъно
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

// модификация: нека n <= k; да се генерират
// само такива редици, в които няма повторения (вариации)
// идея: в тялото на for ще има проверка дали числото i
// все още не е използвано във vector (в позиции от 0 до
// start-1) и само тогава ще се изпълнява сегашното тяло

// 1 (true) - проходима клетка, 0 (false) - стена
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

int endRow, endCol; // координати на крайната клетка

// има ли път от дадена начална клетка до дадена крайна клекта
bool way(int startRow, int startCol)
{
    // ако началната клетка е извън лабиринта
    if (startRow < 0 || startCol < 0 ||
        startRow >= 8 || startCol >= 8)
            return false;

    // ако текущата клетка е непроходима
    if (!labyrinth[startRow][startCol])
        return false;

    // началната и крайната клетка съвпадат - очевидно има път
    if (startRow == endRow && startCol == endCol)
        return true;

    // маркираме текущата клетка като непроходима,
    // за да не зациклим!
    labyrinth[startRow][startCol] = false;

    // ако има път от някоя от съседните клетки до края,
    // то значи и от текущата има (=> true)
    return way(startRow - 1, startCol)
        || way(startRow + 1, startCol)
        || way(startRow, startCol - 1)
        || way(startRow, startCol + 1);
}

// Обръщане на цифрите на число:
// (не е свързано с рекурсията)
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
