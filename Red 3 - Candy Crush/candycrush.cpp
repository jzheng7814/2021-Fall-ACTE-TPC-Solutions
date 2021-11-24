#include <iostream>
#include <fstream>
using namespace std;
 
int N, K, board[100][10], region[100][10], regsizes[1001];
 
void gravity(void)
{
    for (int j = 0; j < 10; j++)
    {
        int top = N - 1, bottom = N - 1;

        while (top >= 0)
        {
            while (top >= 0 && board[top][j] == 0)
            {
                top--;
            }

            if (top >= 0)
            {
                board[bottom--][j] = board[top--][j];
            }
        }

        while (bottom >= 0)
        {
            board[bottom--][j] = 0;
        }
    }   
}
 
void visit(int i, int j, int r, int c)
{
    if (i < 0 || i >= N || j < 0 || j > 9 || board[i][j] != c || region[i][j] != 0)
    {
        return;
    }

    region[i][j] = r;
    regsizes[r]++;

    visit(i - 1, j, r, c);
    visit(i + 1, j, r, c);
    visit(i, j - 1, r, c);
    visit(i, j + 1, r, c);
}
 
bool iterate(void)
{
    int r = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            region[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (board[i][j] && !region[i][j])
            {
                visit(i, j, r++, board[i][j]);
            }
        }
    }

    bool progress = false;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (board[i][j] && regsizes[region[i][j]] >= K)
            {
                board[i][j] = 0;
                progress = true;
            }
        }
    }
    
    gravity();

    while (r)
    {
        regsizes[r--] = 0;
    }

    return progress;
}
 
int main(void)
{
    cin >> N;
    K = 3;
    string s;

    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < 10; j++)
        {
            board[i][j] = s[j] - '0';
        }
    }
    
    while (iterate());
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}