#include <iostream>
#include <vector>

using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),0));
    int maxLength = 0;
    for (int i=0; i<nums1.size(); i++){
        for (int j=0; j<nums2.size(); j++){
            if (nums1[i] == nums2[j]){
                if (i-1 >= 0 && j-1 >= 0){
                    dp[i][j] = dp[i-1][j-1]+1;
                    maxLength = max(maxLength,dp[i][j]);
                } else {
                    dp[i][j] = 1;
                    maxLength = max(maxLength,dp[i][j]);
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return maxLength;
}

int main(){
    vector<int> nums1 = {1,2,3,2,1};
    vector<int> nums2 = {3,2,1,4,7};
    cout << findLength(nums1,nums2);
    return 0;
}