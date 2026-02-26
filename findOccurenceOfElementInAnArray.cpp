#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
    vector<int> result = {};
    unordered_map<int,int> occMap;
    int maxIdxCount = 0;
    for (int i=0; i<nums.size(); i++){
        if (nums[i] == x){
            occMap[++maxIdxCount] = i;
        }
    }
    for (int i=0; i<queries.size(); i++){
        if (queries[i] > maxIdxCount){
            result.push_back(-1);
        } else {
            result.push_back(occMap[queries[i]]);
        }
    }
    return result;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<int> queries = {10};
    int x = 5;
    vector<int> result = occurrencesOfElement(nums,queries,x);
    for (int x : result){
        cout << x << endl;
    }
    return 0;
}