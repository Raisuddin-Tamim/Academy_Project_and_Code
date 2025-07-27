#include<bits/stdc++.h>
using namespace std;

bool Find(vector <int> fra,int key)
{
    return find(fra.begin(),fra.end(),key) != fra.end();
}

void FCFS(vector<int> v)
{
    cout<< "Enter fragment size: ";
    int n; cin>>n;
    vector<int>fra;
    for(int i=0; i<n; i++) fra.push_back(-1);

    int page_fault=0,k=0;
    for(int i=0; i<v.size(); i++)
    {
        if( !Find(fra,v[i]) ){
            page_fault++;
            fra[k++%n] = v[i];
        }
    }

    cout<<page_fault;

}
int main()
{
    cout<< "Enter number of page:";
    int n;cin>>n;
    cout<< "\nEnter pages: ";
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        int x; cin>>x;
        v.push_back(x);
    }

    FCFS(v);
    cout<< "\nDo you play again? 0/1 : ";
    int p;cin>>p;
    while(p)
    {
        FCFS(v);
        cout<< "\nDo you play again? 0/1 : ";
        cin>>p;
    }

    return 0;
}
//2 3 5 4 0 5 3 2 4 0
