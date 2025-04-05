#include <iostream>
using namespace std;

void printRow(char topLeft, char topRight, char horizontal, int width)
{
    cout << topLeft;
    for (int i = 0; i < width - 1; ++i)
    {
        cout << horizontal << horizontal << horizontal << topRight;
    }
    cout << horizontal << horizontal << horizontal << topRight << endl;
}

void printBox(char left, char right, int height, int width)
{
    printRow(left, right, '-', width);
    for (int i = 0; i < height - 1; ++i)
    {
        cout << left << "   ♚.   │      │      " << right << endl;
    }
    printRow(left, right, '-', width);
}

int main()
{
    const int rows = 3;
    // const int cols = 3;

    const int boxWidth = 7; // Width adjusted for the content
    const int boxHeight = 3;

    // Printing the grid
    printRow('+', '+', '-', boxWidth);
    for (int i = 0; i < rows; ++i)
    {
        if (i != 0)
        {
            printBox('|', '|', boxHeight, boxWidth);
        }
        if (i != rows - 1)
        {
            printRow('|', '|', '-', boxWidth);
        }
    }
    printRow('+', '+', '-', boxWidth);

    return 0;
}
