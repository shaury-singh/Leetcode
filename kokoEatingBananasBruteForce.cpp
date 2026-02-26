#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int min = 1;
    while (true) {
        long long hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += ceil(double(piles[i]) / double(min));
        }
        if (hours <= h) {
            break;
        } else {
            min++;
        }
    }
    return min;
}

int main(){
    vector<int> piles = {332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184};
    int h = 823855818;
    cout << minEatingSpeed(piles,h);
    return 0;
}