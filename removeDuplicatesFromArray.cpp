#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    unordered_set<int> hashSet = {};
    priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
    int counter = 0;
    for (int i=0; i<nums.size(); i++){
        if (hashSet.find(nums[i]) == hashSet.end()){
            cout << "did not find: " << nums[i] << endl;
            hashSet.insert(nums[i]);
            counter++;
            cout << "counter is: " << counter << endl;
        } else {
            cout << "found: " << nums[i] << " already in the hashSet" << endl;
        }
    }
    for (auto& num : hashSet){
        cout << "pushed " << num << " into the minHeap" << endl;
        min_pq.push(num);
    }
    for (int i=0; i<counter; i++){
        nums[i] = min_pq.top();
        min_pq.pop();
    }
    // for (int i=0; i<counter; i++){
    //     cout << nums[i] << endl;
    // }
    return counter;
}

int main(){
    vector<int> nums = {1,1,3,5,7,7,7,8,11,11,12};
    cout << "size is: " << removeDuplicates(nums);
    return 0;
}