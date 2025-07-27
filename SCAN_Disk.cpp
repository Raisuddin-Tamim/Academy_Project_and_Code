#include<bits/stdc++.h>
using namespace std;

void SCAN(vector<int> v, int n, int p)
{
    sort(v.begin(),v.end());
    int index = find(v.begin(),v.end(),p) - v.begin();
    int k=index,sum = 0;

    while(k < n-1)
    {
        sum+= abs(v[k]-v[++k]);
        cout<<sum<<" ";
    }

    while(index > 0)
    {
        sum+=abs(v[k]-v[--index]);
        k = index;
        cout<<sum<<" ";
    }

    cout<<"\nNumber Of Move: "<<sum;
}

int main()
{
    vector<int> v={12,34,52,14,25,68,39};
   /* cout<<"Enter number of request: ";
    int n;cin>>n;

    for(int i=0; i<n; i++)
    {
        int x; cin>>x; v.push_back(x);
    } */

    cout<<"Total number of track: ";
    int t; cin>>t;
    v.push_back(t);

    cout<<"Enter head track position: ";
    int p; cin>>p;
    v.push_back(p);

    SCAN(v,v.size(),p);
    return 0;

}

