#include<bits/stdc++.h>
using namespace std;
const int p=5;
const int r=3;
int allocation [p][r]={
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};
int maxNeed[p][r]={
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};
int available[r]={3, 3, 2};
int need[p][r];
void calculateNeed() {
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }
}
bool isSafeState(int safeSeq[]){
    bool finish[p] = {0};
    int work[r];
    for (int i = 0; i < r; i++) {
        work[i] = available[i];
    }
    int count = 0;
    while (count < p) {
        bool found = false;
        for (int i = 0; i < p; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == r) {
                    for (int k = 0; k < r; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "System is not in a safe state\n";
            return false;
        }
    }
    cout << "System is in a safe state.\nSafe sequence is: ";
    for (int i = 0; i < p ; i++) {
        cout<<"P" << safeSeq[i]<<"->" << " ";
    }
    cout << endl;
    return true;
}
bool requestResources(int processNum, int request[]){
    for (int i = 0; i < r; i++) {
        if (request[i] > need[processNum][i]) {
            cout << "Error: Process has exceeded its maximum claim.\n";
            return false;
        }
        if (request[i] > available[i]) {
            cout << "Process is waiting.\n";
            return false;
        }
    }
    for (int i = 0; i < r; i++) {
        available[i] -= request[i];
        allocation[processNum][i] += request[i];
        need[processNum][i] -= request[i];
    }
    int safeSeq[p];
    if (isSafeState(safeSeq)) {
        cout << "Request granted.\n";
        return true;
    } else {
        cout << "Request cannot be granted.\n";
        for (int i = 0; i < r; i++) {
            available[i] += request[i];
            allocation[processNum][i] -= request[i];
            need[processNum][i] += request[i];
        }
        return false;
    }
}

int main() {
    calculateNeed();
    cout<<"Task 1:\n";
    for(int i=0; i<p; i++){
        for(int j=0; j<r; j++) cout<<need[i][j]<< "  ";
    cout<<"\n";
    }
    cout<<"\nTask 2:\n";
    int safeSeq[p];
    isSafeState(safeSeq);
    cout<<"\nTask 3:\n";
    int processNum = 1;
    int request[r] = {1, 0, 2};
    requestResources(processNum, request);
    cout<<"\nTask 4:\n";
    processNum=4;
    int request1[r] = {3, 3, 0};
    requestResources(processNum, request1);
    return 0;
}
