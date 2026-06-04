#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Compare{
    public:
        bool operator()(const pair<int,int> a, const pair<int,int> b) const{
            return (a.first + a.second < b.first + b.second);
        }
};

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> max_pq;
    vector<vector<int>> result = {};
    int sizeNums1 = nums1.size();
    int sizeNums2 = nums2.size();
    for (int i=0; i<sizeNums1; i++){
        for (int j=0; j<sizeNums2; j++){
            if (max_pq.size() < k){
                max_pq.push(pair(nums1[i],nums2[j]));
            } else {
                int currSum = nums1[i] + nums2[j];
                int topSum = max_pq.top().first + max_pq.top().second;
                if (currSum < topSum) {
                    max_pq.pop();
                    max_pq.push({nums1[i], nums2[j]});
                }
            }
        }
    }
    while (max_pq.empty() == false){
        result.push_back({max_pq.top().first,max_pq.top().second});
        max_pq.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};
    int k = 3;
    vector<vector<int>> result = kSmallestPairs(nums1,nums2,k);
    for (int i=0; i<result.size(); i++){
        for (int j=0; j<result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}