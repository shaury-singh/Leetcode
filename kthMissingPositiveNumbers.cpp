#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    unordered_set<int> numSet = {};
    for (int element : arr){
        numSet.insert(element);
    }
    int seqNo = 0;
    int element = 1;
    for (int i=1; i<2000; i++){
        if (numSet.find(i) == numSet.end()){
            seqNo++;
        }
        if (seqNo == k){
            element = i;
            return i;
        }
    }
    return element;
}

int main(){
    vector<int> arr = {1,2,3,4};
    int k = 2;
    cout << findKthPositive(arr,k);
    return 0;
}