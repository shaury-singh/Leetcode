#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int p1 = m-1;
    int p2 = n-1;
    int curr = m+n-1;
    while (p1>=0 && p2>=0){
        if (nums2[p2] > nums1[p1]){
            nums1[curr] = nums2[p2];
            p2--;
        } else {
            nums1[curr] = nums1[p1];
            p1--;
        }
        curr--;
    }
    while (p1 >= 0){
        nums1[curr] = nums1[p1];
        p1--;
        curr--;
    }
    while (p2 >= 0){
        nums1[curr] = nums2[p2];
        p2--;
        curr--; 
    }
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    merge(nums1, m, nums2, n);
    for (int i=0; i<nums1.size(); i++){
        cout << nums1[i] << endl;
    }
    return 0;
}