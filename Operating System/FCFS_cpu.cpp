#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<< "Enter Total number of process: ";
    int n; cin>>n;
    vector<tuple<string,int,int>> pro;
    cout<< "Enter process,AT,BT Time:\n";
    for(int i=0; i<n; i++)
    {
        string job;
        int AT,BT; cin>>job>>AT>>BT;
        pro.push_back(make_tuple(job,AT,BT));

    }

    sort(pro.begin(),pro.end(), [](auto &a, auto &b){
         return get<1>(a) < get<1>(b); });


         //FCFS start
    int TotalBT=0,TotalWT=0,TotalTAT=0,TAT,wt;
    for(int i=0; i<n; i++)
    {
        int arrival = get<1>(pro[i]);
        int burst = get<2> (pro[i]);

        TotalBT = max(TotalBT,arrival);

        wt = TotalBT - arrival;
        TotalWT+=wt;

        TotalBT += burst;

        TAT = TotalBT - arrival;
        TotalTAT += TAT;


        cout<<"For "<<get<0>(pro[i])<<": " << "**Waiting time-> "<<wt<<"  **TurnAround Time-> "<<TAT<<endl;

    }

    cout<<"\nAverage Waiting Time: "<<(float) TotalWT/n;
    cout<<"\nAverage TurnAround Time: "<<(float) TotalTAT/n;

    return 0;
}
