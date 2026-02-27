#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> minAndMax(vector<int> nums){
    if (nums.size() == 0) return {0,0};
    vector<int> result = {nums[0],nums[0]};
    for (int num : nums){
        if (num < result[0]) result[0] = num;
        if (num > result[1]) result[1] = num;
    }
    return result;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    vector<int> minMax = minAndMax(nums);
    int left = 1;
    // cout << left << endl;
    int right = minMax[1];
    // cout << right << endl;
    while (left <= right){
        int mid = (left + right)/2;
        int sum = 0;
        for (int num : nums){
            sum += ceil((double)num / mid);
        }
        if (sum <= threshold){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    cout << smallestDivisor(nums,threshold);
    return 0;
}