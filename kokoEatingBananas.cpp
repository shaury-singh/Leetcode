#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxBananas(vector<int> piles){
    int max = 0;
    for (int bananas : piles){
        if (bananas > max) max = bananas;
    }
    return max;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = maxBananas(piles);
    while (left <= right){
        int mid = (left+right)/2;
        long long hours = 0;
        for (int bananas : piles){
            hours += ceil(double(bananas)/double(mid));
        }
        if (hours <= h) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    vector<int> piles = {332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184};
    int h = 823855818;
    cout << minEatingSpeed(piles,h);
    return 0;
}