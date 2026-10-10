#include <iostream>
using namespace std;

int board[16][16] = {0};

bool safe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < 16; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solve(int row)
{
    if (row == 16)
        return true;

    for (int col = 0; col < 16; col++)
    {
        if (safe(row, col))
        {
            board[row][col] = 1;

            if (solve(row + 1))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    if (solve(0))
    {
        cout << "Maximum flags = 16\n\n";

        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
                cout << board[i][j] << " ";

            cout << endl;
        }
    }

    return 0;
}