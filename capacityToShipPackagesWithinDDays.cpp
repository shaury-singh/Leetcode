#include <iostream>
#include <vector>

using namespace std;

vector<int> sumAndMax(vector<int> weights){
    if (weights.size() == 0) return {0,0};
    vector<int> result = {weights[0],0};
    for (int weight : weights){
        if (weight > result[0]) result[0] = weight;
        result[1] += weight;
    }
    return result;
}

int shipWithinDays(vector<int>& weights, int days) {
    vector<int> sumMax = sumAndMax(weights);
    int left = sumMax[0];
    int right = sumMax[1];
    while (left <= right){
        int mid = (left + right)/2;
        // cout << "mid is: " << mid << endl;
        int d = 1;
        int load = 0;
        for (int weight : weights){
            if (load + weight > mid){
                d++;
                // cout << "load and weight is: " << load + weight << endl;
                load = weight;
            } else {
                load += weight;
                // cout << "load is: " << load << endl;
            }
        }
        if (d <= days){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << shipWithinDays(weights,days);
    return 0;
}