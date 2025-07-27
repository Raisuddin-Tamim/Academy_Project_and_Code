#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<< "Enter number of Process: ";
    int n; cin>>n;
    cout<< "\nENETR Quantum number: ";
    int q;cin>>q;
    vector<tuple<string,int,int>> pro;
    int TBT=0;
    cout<< "\nEnter process, AT, BT:\n";
    for(int i=0; i<n; i++)
    {
        string s; int at,bt;
        cin>>s>>at>>bt;
        TBT += bt;
        pro.push_back(make_tuple(s,at,bt));
    }

     map<string,int> ct;

    int i=0,currentT=0;
    bool done[n]={0};
    while(TBT > 0)
    {
        int arrival = get<1>(pro[i]);
        string name = get<0>(pro[i]);

        if(currentT >= arrival && !done[i])
        {

            if(get<2>(pro[i]) < q)
            {
                currentT += get<2>(pro[i]);
                get<2>(pro[i])=0;
                TBT -= get<2>(pro[i]);

            }
            else{
                get<2>(pro[i]) -= q;
                currentT += q;
                TBT -= q;
            }

            ct[name] = currentT;
            if(get<2>(pro[i]) == 0) done[i] = true;
        }
        i++;
        if(i==n) i=0;
    }
    cout<<endl;
    for(auto x : ct)
    {
        cout<<x.first<< ": "<<x.second<<endl;
    }
    return 0;
}
