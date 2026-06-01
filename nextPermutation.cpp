#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isDecreasing(vector<int> nums){
    for (int i=0; i<nums.size()-1; i++){
        if (nums[i] < nums[i+1]){
            return false;
        }
    }
    return true;
}

int idxNextGreater(vector<int> nums, int curr){
    for (int i=nums.size()-1; i > curr; i--){
        if (nums[i] > nums[curr]){
            return i;
        }
    }
    return -1;
}

void nextPermutation(vector<int>& nums) {
    int swapIdx = 0;
    int left = 0;
    if (isDecreasing(nums) == true){
        sort(nums.begin(), nums.end());
        return;
    }
    for (int i=nums.size()-1; i>0; i--){
        if (nums[i] > nums[i-1]){
            left = i-1;
            swapIdx = idxNextGreater(nums,left);
            int temp = nums[swapIdx];
            nums[swapIdx] = nums[left];
            nums[left] = temp;
            break;
        }
    }
    left++;
    int right = nums.size()-1;
    while (left < right){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}

int main(){
    vector<int> nums = {5, 8, 3, 17, 51, 28, 21, 13};
    vector<int>* num = &nums;
    nextPermutation(*num);
    for (int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}