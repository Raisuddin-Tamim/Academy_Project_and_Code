#include<bits/stdc++.h>
using namespace std;

void FCFS(vector<int> v, int n, int p)
{
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum+= abs(p-v[i]);
        p=v[i];
    }
    cout<<"\nNumber Of Move: "<<sum;
}

int main()
{
    vector<int> v;
    cout<<"Enter number of request: ";
    int n;cin>>n;

    for(int i=0; i<n; i++)
    {
        int x; cin>>x; v.push_back(x);
    }

    cout<<"Enter head track position: ";
    int p; cin>>p;

    FCFS(v,n,p);
    return 0;

}

