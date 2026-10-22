#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;
    while (left < right){
        int currArea = min(height[left],height[right])*(right-left);
        if (currArea>maxArea){
            maxArea = currArea;
        }
        if (height[left] < height[right]){
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}

int main(){
    vector<int> height = {11,2,4,2,5,67,21,2,3,1,3,3,3,11};
    cout << maxArea(height);
    return 0;
}