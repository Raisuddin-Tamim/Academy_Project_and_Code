#include<bits/stdc++.h>
using namespace std;

bool Find(vector <int> fra,int key)
{
    return find(fra.begin(),fra.end(),key) != fra.end();
}

int find_index(vector<int>v, vector<int> fra, int limit)
{
    int check=INT_MAX;
    for(int i=0; i<fra.size(); i++)
    {
        for(int j=0; j<limit; j++)
        {
            if(v[j] == fra[i] && check < j ) check =j;
        }
    }
    return check;
}

FCFS_lru(vector<int> v)
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
            int index = find_index(v,fra,i);
            fra[index]=v[i];

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

    FCFS_lru(v);
    cout<< "\nDo you play again? 0/1";
    int p;cin>>p;
    while(p)
    {
        FCFS_lru(v);
        cout<< "\nDo you play again? 0/1 : ";
        cin>>p;
    }

    return 0;
}

