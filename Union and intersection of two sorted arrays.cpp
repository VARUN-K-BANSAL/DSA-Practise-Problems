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

void UnionOfTwoSortedArray(ll *a, ll *b)
{
    int i = 0, j = 0;
    while (i < MAX_SIZE && j < MAX_SIZE)
    {
        if (a[i] > b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else if (a[i] < b[j])
        {
            cout << b[j] << " ";
            j++;
        }
        else if (a[i] == b[j])
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
    while (i < MAX_SIZE)
    {
        cout << a[i] << " ";
        i++;
    }
    while (j < MAX_SIZE)
    {
        cout << b[j] << " ";
        j++;
    }
    cout << endl;
}

void IntersectionOfTwoSortedArray(ll *a, ll *b)
{
    int i = 0, j = 0;
    while (i < MAX_SIZE && j < MAX_SIZE)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else if (a[i] == b[j])
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
    cout << endl;
}

int main()
{
    fast;
    srand((unsigned int)time(NULL));
    ll a[MAX_SIZE], b[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        ll temp = 1 + rand() % 500;
        a[i] = temp;
        // a[i] = pow(-1, temp) * a[i];         // uncomment when negative numbers are also needed
        b[i] = 1 + rand() % 500;
    }
    sort(a, a + MAX_SIZE);
    sort(b, b + MAX_SIZE);
    cout << "Array1 -->\n";
    PrintArray(a);
    cout << "\nArray2 -->\n";
    PrintArray(b);
    cout << "\nUnion of above two arrays -->\n";
    UnionOfTwoSortedArray(a, b);
    cout << "\nIntersection of above two arrays -->\n";
    IntersectionOfTwoSortedArray(a, b);

    return 0;
}