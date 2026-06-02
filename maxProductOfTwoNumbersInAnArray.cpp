#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxProduct(vector<int>& nums) {
    priority_queue<int> max_pq;
    vector<int> sortedNums = {};
    for (int i=0; i<nums.size(); i++){
        max_pq.push(nums[i]);
    }
    while (max_pq.empty() != true){
        sortedNums.push_back(max_pq.top());
        max_pq.pop();
    }
    return (sortedNums[0]-1)*(sortedNums[1]-1);
}

int main(){
    vector<int> nums = {3,4,5,2};
    cout << maxProduct(nums);
    return 0;
}