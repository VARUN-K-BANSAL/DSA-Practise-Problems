#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAX_SIZE 50

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void PrintArray(ll a[])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    fast;
    srand((unsigned int)time(NULL));
    ll a[MAX_SIZE], max = 0, min = 9999;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        a[i] = 1 + rand() % 500;
        max = (a[i] > max) ? a[i] : max;
        min = (a[i] < min) ? a[i] : min;
    }
    PrintArray(a);
    cout << "Maximum Element --> " << max << endl
         << "Minimum Element --> " << min << endl;

    return 0;
}