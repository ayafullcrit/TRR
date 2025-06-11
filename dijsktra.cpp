#include <iostream>
#include <math.h>
using namespace std;
double INF = 10000;
int main()
{
    int n = 8;
    double f[n][n] = {
        {0, 12, 18, 0, 0, 0, 0, 0},
        {12, 0, 5, 13, 6, 0, 0, 0},
        {18, 5, 0, 5, 0, 25, 0, 0},
        {0, 13, 5, 0, 5, 15, 0, 0},
        {0, 6, 0, 5, 0, 1, 15, 0},
        {0, 0, 25, 15, 1, 0, 16, 5},
        {0, 0, 0, 0, 15, 16, 0, 10},
        {0, 0, 0, 0, 0, 5, 10, 0},
    };
    int par[n + 1];
    int dist[n + 1];
    bool visited[n + 1];
    int root = 7, target = 0;
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[root] = 0;
    for (int step = 0; step < n - 1; step++)
    {
        int MinDist = INF, MinIndex = -1;
        for (int i = 0; i < n; i++)
            if (dist[i] < MinDist && !visited[i])
            {
                MinDist = dist[i];
                MinIndex = i;
            }
        if (MinIndex == -1)
            break;
        visited[MinIndex] = 1;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] or f[i][MinIndex] == 0)
                continue;
            if (dist[i] > MinDist + f[i][MinIndex])
            {
                dist[i] = MinDist + f[i][MinIndex];
                par[i] = MinIndex;
            }
        }
    }
    cout << "Duong di ngan nhat: " << dist[target] << endl;
    for (int i = 0; i < n; i++)
        cout << par[i] << ' ';
    cout << endl;
    int cnt = 0;
    int path[n + 1];
    while (par[target] != -1)
    {
        path[cnt] = target;
        cnt++;
        target = par[target];
    }
    cout << char(root + 'A') << " -> ";
    for (int i = cnt - 1; i >= 0; i--)
    {
        cout << char('A' + path[i]);
        if (i != 0)
            cout << " -> ";
    }
}