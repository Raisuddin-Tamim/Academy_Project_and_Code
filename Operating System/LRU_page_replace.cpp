#include <bits/stdc++.h>
using namespace std;

bool Find(const vector<int>& fra, int key)
{
    return find(fra.begin(), fra.end(), key) != fra.end();
}

int find_index(const vector<int>& v, const vector<int>& fra, int limit)
{
    int oldest_index = -1;
    int oldest_pos = INT_MAX;

    for (int i = 0; i < fra.size(); i++)
    {
        int last_use = -1;
        for (int j = limit - 1; j >= 0; j--)
        {
            if (fra[i] == v[j])
            {
                last_use = j;
                break;
            }
        }
        if (last_use == -1)
        {
            return i;
        }

        if (last_use < oldest_pos)
        {
            oldest_pos = last_use;
            oldest_index = i;
        }
    }

    return oldest_index;
}

void LRU(const vector<int>& v)
{
    cout << "Enter fragment size: ";
    int n; cin >> n;
    vector<int> fra(n, -1);

    int page_fault = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (!Find(fra, v[i]))
        {
            page_fault++;
            auto it = find(fra.begin(), fra.end(), -1);
            if (it != fra.end())
            {
                *it = v[i];
            }
            else
            {
                int index = find_index(v, fra, i);
                fra[index] = v[i];
            }
        }

        for (int x : fra) cout << x << " ";
        cout << endl;
    }

    cout << "Page fault: " << page_fault << endl;
}

int main()
{
    cout << "Enter number of page: ";
    int n; cin >> n;
    cout << "\nEnter pages: ";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    LRU(v);

    cout << "\nDo you play again? 0/1 : ";
    int p; cin >> p;
    while (p)
    {
        LRU(v);
        cout << "\nDo you play again? 0/1 : ";
        cin >> p;
    }

    return 0;
}
//2 3 5 4 0 5 3 2 4 0
