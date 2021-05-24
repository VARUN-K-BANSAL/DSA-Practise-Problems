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

void AllNegativeElements(ll *a)
{
    int k = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (a[i] < 0)
        {
            if (i != k)
            {
                ll temp = a[k];
                a[k] = a[i];
                a[i] = temp;
            }
            k++;
        }
    }
}

int main()
{
    fast;
    srand((unsigned int)time(NULL));
    ll a[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        ll temp = 1 + rand() % 500;
        a[i] = temp;
        a[i] = pow(-1, temp) * a[i];
    }
    cout << "Array -->\n";
    PrintArray(a);
    AllNegativeElements(a);
    cout << "Required Array -->\n";
    PrintArray(a);

    return 0;
}