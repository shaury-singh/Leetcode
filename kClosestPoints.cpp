#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Compare {
public:
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        int distA = a[0] * a[0] + a[1] * a[1];
        int distB = b[0] * b[0] + b[1] * b[1];
        return distA < distB;
    }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    vector<vector<int>> result = {};
    for (int i=0; i<points.size(); i++){
        int distance = ((points[i][0])*points[i][0]) + ((points[i][1])*points[i][1]);
        if (pq.size() < k){
            pq.push(points[i]);
        } else {
            if ((pq.top()[0]*pq.top()[0] + pq.top()[1]*pq.top()[1]) > (points[i][0]*points[i][0] + points[i][1]*points[i][1])){
                pq.pop();
                pq.push(points[i]);
            }
        }
    }
    while (pq.empty() != true){
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}

int main(){
    vector<vector<int>> points = {{1,3},{-2,2}};
    int k = 1;
    vector<vector<int>> result = kClosest(points,k);
    for (int i=0; i<result.size(); i++){
        cout << result[i][0] << " " << result[i][1] << endl;
    }
    return 0;
}