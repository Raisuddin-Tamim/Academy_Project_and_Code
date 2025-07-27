#include<bits/stdc++.h>
using namespace std;

int nearlyReq(vector<int> v, int n, int t, int p)
{
    int temp=INT_MAX,index;
    for(int i=0; i<n; i++)
    {
        if(v[i] != -1)
        {
            int dif = abs(p-v[i]);
            if(temp > dif) {temp = dif; index = i;}
        }
    }
    return index;

}

void SSTF(vector<int> v, int n, int t, int p)
{
    int sum=0;
    for(int i=0; i<n; i++)
    {
        int index = nearlyReq(v,n,t,p);

        sum += abs(p-v[index]);
        p=v[index];
        v[index]=-1;

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
    cout<<"Enter Total Track on Disk: ";
    int t; cin>>t;
    cout<<"Enter head track position: ";
    int p; cin>>p;

    SSTF(v,n,t,p);
    return 0;

}

