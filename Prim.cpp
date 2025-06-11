#include <iostream>
using namespace std;

const int INF = 1e9; // Giá trị vô cực (lớn)

int main()
{
    int n = 8; // Số đỉnh: A,B,C,D,E,F,G (đánh số từ 0)
    int cost[8][8] = {
        {0, 12, 18, 0, 0, 0, 0, 0},
        {12, 0, 5, 13, 6, 0, 0, 0},
        {18, 5, 0, 5, 0, 25, 0, 0},
        {0, 13, 5, 0, 5, 15, 0, 0},
        {0, 6, 0, 5, 0, 1, 15, 0},
        {0, 0, 25, 15, 1, 0, 16, 5},
        {0, 0, 0, 0, 15, 16, 0, 10},
        {0, 0, 0, 0, 0, 5, 10, 0},
    };

    int dist[n];     
    bool visited[n]; 
    int parent[n];   

   
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[0] = 3; 

    for (int count = 0; count < n - 1; count++)
    {
  
        int u = -1, minDist = INF;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (cost[u][v] == 0 or visited[v])
                continue;
            if (cost[u][v] < dist[v])
            {
                dist[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;
    cout << "Cac canh trong cay khung nho nhat:\n";
    for (int i = 1; i < n; i++)
    {
        cout << char('A' + parent[i]) << " - " << char('A' + i)
             << " = " << cost[i][parent[i]] << endl;
        totalCost += cost[i][parent[i]];
    }
    cout << "Tong trong so: " << totalCost << endl;

    return 0;
}
