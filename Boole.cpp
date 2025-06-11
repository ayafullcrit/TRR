#include <iostream>
using namespace std;

int n, k;
bool x[100];
bool Value()
{
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
    return x[0] * x[1] * (!x[2]) + (!x[0]) * x[1] * x[2] + (!x[0]) * x[1] * (!x[2]) + (!x[0]) * (!x[1]) * x[2];
}
void tohop(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n - 1)
        {
            cout << Value() << endl;
        }
        else
            tohop(i + 1);
    }
}
int main()
{
    n = 3;
    tohop(0);
}
