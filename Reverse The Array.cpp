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

void ReverseTheArray(ll *a)
{
    // by swaping the first and last elements
    for (int i = 0; i < MAX_SIZE / 2; i++)
    {
        ll temp = a[i];
        a[i] = a[MAX_SIZE - i - 1];
        a[MAX_SIZE - i - 1] = temp;
    }
}

void ReverseTheArrayRecursively(ll *a, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    ll temp = a[start];
    a[start] = a[end];
    a[end] = temp;
    ReverseTheArrayRecursively(a, start + 1, end - 1);
}

int main()
{
    fast;
    srand((unsigned int)time(NULL));
    ll a[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        a[i] = 1 + rand() % 500;
    }
    PrintArray(a);
    ReverseTheArray(a);
    PrintArray(a);
    ReverseTheArrayRecursively(a, 0, MAX_SIZE - 1);
    PrintArray(a);

    return 0;
}