#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

bool numInSet(unordered_set<long long>& numSet, int n) {
    if (numSet.find(n) == numSet.end()) {
        return false;
    }
    return true;
}

int nthUglyNumber(int n) {
    priority_queue<long long, vector<long long>, greater<long long>> min_pq;
    unordered_set<long long> numSet = {};
    long long curr = 1;
    min_pq.push(curr);
    vector<long long> uglyVector = {};
    while (uglyVector.size() < n) {
        uglyVector.push_back(min_pq.top());
        numSet.insert(min_pq.top());
        min_pq.pop();
        if (numInSet(numSet, curr * 2) == false) {
            min_pq.push(curr * 2);
            numSet.insert(curr * 2);
        }
        if (numInSet(numSet, curr * 3) == false) {
            min_pq.push(curr * 3);
            numSet.insert(curr * 3);
        }
        if (numInSet(numSet, curr * 5) == false) {
            min_pq.push(curr * 5);
            numSet.insert(curr * 5);
        }
        curr = min_pq.top();
    }
    // for (int i=0; i<uglyVector.size(); i++){
    //     cout << uglyVector[i] << endl;
    // }
    return uglyVector[n - 1];
}

int main(){
    int n = 1690;
    cout << nthUglyNumber(n);
    return 0;
}