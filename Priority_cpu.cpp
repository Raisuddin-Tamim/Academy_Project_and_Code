#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter Number of Process: ";
    int n; cin>>n;
    vector<tuple<string, int, int, int>> pro;
    vector<tuple<string,int, int,int>> ePro;

    for(int i=0; i<n; i++)
    {
        string s; int at,bt,pr;
        cin>>s>>at>>bt>>pr;
        pro.push_back(make_tuple(s,at,bt,pr));
    }

    int complete=0,currentT=0;
    bool done[n]={0};

    while(complete < n)
    {
        int idx =-1;
        int maxPri = INT_MIN;

        for(int i=0; i<n; i++)
        {
            int arrival = get<1>(pro[i]);
            int priority = get<3>(pro[i]);

            if(currentT >= arrival && !done[i] && priority > maxPri)
            {
                maxPri = priority;
                idx = i;
            }
        }

        if(idx == -1){
            currentT++; continue;
        }

        int wt,tat,ct;
        string name;


        name = get<0>(pro[idx]);
        int arrival = get<1>(pro[idx]);
        int brust = get<2>(pro[idx]);

        ct = currentT+brust;
        tat = ct - arrival;
        wt = tat - brust;
        currentT = ct;

        ePro.push_back(make_tuple(name,wt,tat,ct));

        done[idx] = true;
        complete++;
    }

    sort(ePro.begin(),ePro.end(), [](auto &a, auto &b){
         return get<0>(a) < get<0>(b); });

    cout<< "\nAfter Execution : \n\n";
    for(auto p : ePro){
        cout<<get<0>(p)<< " "<<get<1>(p)<<" "<<get<2>(p)<<" "<<get<3>(p)<<endl;
    }

    return 0;
}
