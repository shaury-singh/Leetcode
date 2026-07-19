#include <iostream>
#include <vector>

using namespace std;

bool canReach(vector<int>& start, vector<int>& target) {
    return (start[0] + start[1])%2 == (target[0] + target[1])%2;
}

int main(){
    vector<int> start = {4,5};
    vector<int> target = {6,6};
    cout << canReach(start,target);
    return 0;
}