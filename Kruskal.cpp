#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;
int parent[MAX];

struct Edge {
    int u, v, w;
};

// Tìm gốc của tập chứa đỉnh x
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]); // nén đường
    return parent[x];
}

// Gộp 2 tập chứa u và v
bool unionSets(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv)
        return false; // đã cùng tập => tạo chu trình
    parent[pu] = pv;
    return true;
}

// Sắp xếp tăng dần theo trọng số
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    // Các đỉnh được đánh số: A=0, B=1, ..., G=6
    Edge edges[] = {
        {2, 3, 2}, // CD
        {1, 2, 3}, // BC
        {0, 2, 5}, // AC
        {3, 4, 5}, // DE
        {1, 4, 6}, // BE
        {4, 6, 7}, // EG
        {0, 1, 12}, // AB
        {1, 3, 13}, // BD
        {4, 5, 14}, // EF
        {3, 5, 15}, // DF
        {5, 6, 16}, // FG
        {2, 4, 25}  // CE
    };
    int n = 7; // số đỉnh
    int m = sizeof(edges) / sizeof(edges[0]); // số cạnh

    // Khởi tạo tập cha
    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(edges, edges + m, cmp); // Sắp xếp các cạnh theo trọng số

    int totalWeight = 0;
    cout << "Cac canh trong cay khung nho nhat:\n";
    for (int i = 0; i < m; i++) {
        if (unionSets(edges[i].u, edges[i].v)) {
            totalWeight += edges[i].w;
            cout << char('A' + edges[i].u) << " - " << char('A' + edges[i].v)
                 << " = " << edges[i].w << endl;
        }
    }
    cout << "Tong trong so: " << totalWeight << endl;

    return 0;
}
