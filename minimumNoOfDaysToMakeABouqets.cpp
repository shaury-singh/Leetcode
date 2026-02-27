#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> findMinAndMax(vector<int> bloomDay){
    if (bloomDay.size() == 0) return {0,0};
    vector<int> result = {bloomDay[0],bloomDay[0]};
    for (int day : bloomDay){
        if (day < result[0]) result[0] = day;
        if (day > result[1]) result[1] = day;
    }
    return result;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    if ((long long) m * k > bloomDay.size()) return -1;
    vector<int> minAndMax = findMinAndMax(bloomDay);
    int left = minAndMax[0];
    int right = minAndMax[1];
    while (left < right){
        int mid = (left + right)/2;
        int bouquets = 0;
        int consecutive = 0;
        for (int day : bloomDay){
            if (mid >= day) {
                consecutive++;
                if (consecutive == k){
                    bouquets++;
                    consecutive = 0;
                }
            } else {
                consecutive = 0;
            }
        }
        if (bouquets >= m){
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3;
    int k = 1;
    cout << minDays(bloomDay,m,k);
    return 0;
}