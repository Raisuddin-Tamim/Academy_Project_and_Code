#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<< "Enter number of process: ";
    int n; cin>>n;

    vector<tuple<string,int,int>> v;

    cout<< "Enter process, AT, BT:\n\n";

    for(int i=0; i<n; i++)
    {
        string s; int at, bt;
        cin>>s>>at>>bt;
        v.push_back(make_tuple(s,at,bt));
    }

    int complete=0,currentT=0;
    bool done[n]={0};
    vector<tuple<string,int,int,int>> ePro;

    while(complete < n)
    {
        int idx = -1, minJob=INT_MAX;

        for(int i=0; i<n; i++)
        {
            int arrival = get<1>(v[i]);
            int burst = get<2>(v[i]);
            if(arrival <= currentT && !done[i] && burst<minJob )
            {
                minJob=burst;
                idx = i;
            }
        }

        if(idx == -1){
            currentT++; continue;
        }

        int ct,tat,wt;

        int arrival = get<1>(v[idx]);
        int burst = get<2>(v[idx]);
        wt = currentT - arrival;
        tat = wt + burst;
        ct = currentT + burst;
        currentT = ct;

        ePro.push_back(make_tuple(get<0>(v[idx]),wt,tat,ct));

        done[idx] = true;
        complete++;

    }

    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<get<0>(ePro[i])<< " "<<get<1>(ePro[i])<< " "<<get<2>(ePro[i])<<endl;
    }

    return 0;
}
