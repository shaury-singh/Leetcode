#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int start = matrix[0][0];
    cout << "start of the search space is: " << start << endl;
    int end = matrix[matrix.size()-1][matrix.size()-1];
    cout << "end of the search space is: " << end << endl;
    if (matrix.size() == 1){
        return matrix[0][0];
    }
    while (start < end){
        cout << "start is less than end" << endl;
        int mid = ceil(double(start+end)/2);
        cout << "mid is: " << mid << endl;
        cout << "searching for an element larger than " << mid << endl; 
        for (int i=matrix.size()-1; i>=0; i--){
            if (mid > matrix[i][0]){
                cout << "Searching in row: " << i << endl;
                int counter = 0;
                cout << "searching in col: " << counter << endl;
                while (++counter < matrix.size() && mid >= matrix[i][counter]);
                cout << "element in row: " << i << " and col: " << counter << " is less than " << mid << endl;
                cout << matrix[i][counter] << " is the " << (matrix.size() - (matrix.size() - i)) * matrix.size() + counter << "th smallest element " << endl;
                if ((matrix.size() - (matrix.size() - i)) * matrix.size() + counter == k){
                    return matrix[i][counter];
                } else if ((matrix.size() - (matrix.size() - i)) * matrix.size() + counter > k){
                    end = mid - 1;
                } else {
                    start = mid;
                }
                break;
            }
        }
    } 
    return 0;
}

int main(){
    vector<vector<int>> matrix = {{3,5,8,8},{4,7,9,10},{6,7,9,12},{8,9,12,13}};
    int k = 5;
    cout << kthSmallest(matrix,k);
    return 0;
}