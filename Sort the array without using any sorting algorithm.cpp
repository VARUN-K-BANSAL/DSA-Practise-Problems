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

void sort012(ll *a, int n)
{
    int c0 = 0, c1 = 0, c2 = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        switch (a[i])
        {
        case 0:
            c0++;
            break;
        case 1:
            c1++;
            break;
        case 2:
            c2++;
            break;
        }
    }
    while (c0--)
    {
        a[k] = 0;
        k++;
    }
    while (c1--)
    {
        a[k] = 1;
        k++;
    }
    while (c2--)
    {
        a[k] = 2;
        k++;
    }
}

int main()
{
    fast;
    srand((unsigned int)time(NULL));
    ll a[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        a[i] = rand() % 3;
    }
    cout << "Array -->\n";
    PrintArray(a);
    sort012(a, MAX_SIZE);
    cout << "Sorted Array -->\n";
    PrintArray(a);

    return 0;
}