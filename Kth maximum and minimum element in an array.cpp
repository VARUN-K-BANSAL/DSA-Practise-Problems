#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAX_SIZE 20

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
    ll a[MAX_SIZE];
    int k = 1 + rand() % MAX_SIZE;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        a[i] = 1 + rand() % 500;
    }
    cout << "Array is --> \n";
    PrintArray(a);
    sort(a, a + MAX_SIZE);
    PrintArray(a);
    cout << "The value of K --> " << k << endl;
    cout << "Kth Minimum Element --> " << a[k - 1] << endl;
    cout << "Kth Maximum Element --> " << a[MAX_SIZE - k] << endl;

    return 0;
}