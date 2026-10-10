#include <iostream>
using namespace std;

char forest[5][5] =
{
    {'S','A','A','T','A'},
    {'A','T','A','A','G'},
    {'T','A','T','A','F'},
    {'A','A','A','T','G'},
    {'A','T','G','T','G'}
};

int visited[5][5] = {0};

int squirrelPath[25][2];
int foxPath[25][2];

int squirrelLength = 0;
int foxLength = 0;

int squirrelItems = 0;
int foxItems = 0;

bool squirrelSolve(int row, int col)
{
    if (row < 0 || row >= 5 || col < 0 || col >= 5)
        return false;

    if (forest[row][col] == 'T' || visited[row][col] == 1)
        return false;

    visited[row][col] = 1;

    squirrelPath[squirrelLength][0] = row;
    squirrelPath[squirrelLength][1] = col;
    squirrelLength++;

    if (forest[row][col] == 'A')
        squirrelItems++;

    if (squirrelItems == 7)
        return true;

    if (squirrelSolve(row + 1, col))
        return true;

    if (squirrelSolve(row, col + 1))
        return true;

    if (squirrelSolve(row - 1, col))
        return true;

    if (squirrelSolve(row, col - 1))
        return true;

    squirrelLength--;

    if (forest[row][col] == 'A')
        squirrelItems--;

    visited[row][col] = 0;

    return false;
}

bool foxSolve(int row, int col)
{
    if (row < 0 || row >= 5 || col < 0 || col >= 5)
        return false;

    if (forest[row][col] == 'T' || visited[row][col] == 1)
        return false;

    visited[row][col] = 1;

    foxPath[foxLength][0] = row;
    foxPath[foxLength][1] = col;
    foxLength++;

    if (forest[row][col] == 'G')
        foxItems++;

    if (foxItems == 4)
        return true;

    if (foxSolve(row + 1, col))
        return true;

    if (foxSolve(row, col + 1))
        return true;

    if (foxSolve(row - 1, col))
        return true;

    if (foxSolve(row, col - 1))
        return true;

    foxLength--;

    if (forest[row][col] == 'G')
        foxItems--;

    visited[row][col] = 0;

    return false;
}

int main()
{
    if (squirrelSolve(0, 0))
    {
        cout << "Squirrel path:\n";

        for (int i = 0; i < squirrelLength; i++)
            cout << "(" << squirrelPath[i][0] << "," << squirrelPath[i][1] << ") ";

        cout << "\n";
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            visited[i][j] = 0;
    }

    if (foxSolve(2, 4))
    {
        cout << "Fox path:\n";

        for (int i = 0; i < foxLength; i++)
            cout << "(" << foxPath[i][0] << "," << foxPath[i][1] << ") ";

        cout << "\n";
    }

    return 0;
}