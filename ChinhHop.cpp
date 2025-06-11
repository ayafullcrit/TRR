#include <iostream>
using namespace std;

int n, k;
int x[100];
bool used[100];

void chinhhop(int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            x[i] = j;
            used[j] = true;
            if (i == k) {
                for (int h = 1; h <= k; h++)
                    cout << x[h] << " ";
                cout << endl;
            } else
                chinhhop(i + 1);
            used[j] = false;
        }
    }
}

int main() {
    cout << "Nhap n, k: ";
    cin >> n >> k;
    chinhhop(1);
    return 0;
}
