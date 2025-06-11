#include <iostream>
using namespace std;

int n, k;
int x[100];

void tohop(int i, int start) {
    for (int j = start; j <= n - k + i; j++) {
        x[i] = j;
        if (i == k) {
            for (int h = 1; h <= k; h++)
                cout << x[h] << " ";
            cout << endl;
        } else
            tohop(i + 1, j + 1);
    }
}

int main() {
    cout << "Nhap n, k: ";
    cin >> n >> k;
    tohop(1, 1);
    return 0;
}
