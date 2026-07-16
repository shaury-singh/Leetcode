#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> sortArray(vector<int>& nums) {
    vector<int> result = {};
    priority_queue<int, vector<int> ,greater<int>> pq = {};
    for (int i=0; i<nums.size(); i++){
        pq.push(nums[i]);
    }
    while (pq.empty() == false){
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}

int main(){
    vector<int> nums = {34,65,75,4,53,43,3,4,345,45,54,54,5,4};
    vector<int>result = sortArray(nums);
    for (int num : result){
        cout << num << endl;
    }
    return 0;
}