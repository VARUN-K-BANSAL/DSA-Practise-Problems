/*
 Link --> https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
*/


#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}

vector<int> find(int arr[], int n , int x )
{
    vector<int> result(2);
    int min = -1 , max = -1 , flag = 0;
    for (int i=0; i<n; i++){
        if(arr[i] == x && min == -1 && flag == 0){
            min = i;
            max = min;
            flag = 1;
        }
        else if(arr[i] == x){
            max++;
        }
    }
    result[0] = min;
    result[1] = max;
    return result;
}