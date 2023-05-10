#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int board[N][N];
int n;

bool isSafe(int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;
    return true;
}
bool solveNQUtil(int col)
{
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 1;
            if (solveNQUtil(col + 1))
                return true;
            board[i][col] = 0;
        }
    }

    return false;
}
void solveNQ()
{
    if (solveNQUtil(0) == false)
    {
        cout <<"Solution does not exist"<< endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] <<"";
        cout << endl;
    }
}
int main()
{
    cin >> n;
    solveNQ();
    return 0;
}
