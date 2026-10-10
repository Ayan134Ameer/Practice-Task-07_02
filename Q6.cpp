#include <iostream>
using namespace std;

char grid[6][6] =
{
    {'D','S','S','F','D','F'},
    {'S','S','S','F','S','D'},
    {'S','D','S','S','S','F'},
    {'F','S','F','S','S','F'},
    {'S','S','S','D','S','F'},
    {'S','F','S','S','S','H'}
};

int visited[6][6] = {0};
int path[36][2];
int bestPath[36][2];

int pathLength = 0;
int bestLength = 0;

int minD = 1000;

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

void solve(int row, int col, int dCount)
{
    if (row < 0 || row >= 6 || col < 0 || col >= 6)
        return;

    if (grid[row][col] == 'F' || visited[row][col] == 1)
        return;

    visited[row][col] = 1;

    path[pathLength][0] = row;
    path[pathLength][1] = col;
    pathLength++;

    if (grid[row][col] == 'D')
        dCount++;

    if (row == 5 && col == 5)
    {
        if (dCount < minD)
        {
            minD = dCount;
            bestLength = pathLength;

            for (int i = 0; i < pathLength; i++)
            {
                bestPath[i][0] = path[i][0];
                bestPath[i][1] = path[i][1];
            }
        }
    }
    else
    {
        for (int i = 0; i < 4; i++)
            solve(row + dr[i], col + dc[i], dCount);
    }

    pathLength--;
    visited[row][col] = 0;
}

int main()
{
    solve(0, 0, 0);

    cout << "Minimum D cells = " << minD << endl;

    cout << "Path:\n";

    for (int i = 0; i < bestLength; i++)
        cout << "(" << bestPath[i][0] << "," << bestPath[i][1] << ") ";

    cout << "\n\nBlocked cells:\n";

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (grid[i][j] == 'F')
                cout << "(" << i << "," << j << ") ";
        }
    }

    return 0;
}