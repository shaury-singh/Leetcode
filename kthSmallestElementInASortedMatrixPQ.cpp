#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int, vector<int>, greater <int>> min_pq;
    for (int i=0; i<matrix.size(); i++){
        for (int j=0; j<matrix.size(); j++){
            min_pq.push(matrix[i][j]);
        }
    }
    for (int i=0; i<k-1; i++){
        min_pq.pop();
    }
    return min_pq.top();
}

int main(){
    vector<vector<int>> matrix = {{3,5,8,8},{4,7,9,10},{6,7,9,12},{8,9,12,13}};
    int k = 5;
    cout << kthSmallest(matrix,k);
    return 0;
}