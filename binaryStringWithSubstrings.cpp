#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

bool queryString(string s, int n) {
    unordered_map<int,bool> boolMap = {};
    int windowSize = ceil(min<double>(log2(n+1),s.size()));
    int left = 0;
    int right = 0;
    int num = 0;
    while (left < s.size() && right < s.size()){
        if (right - left < windowSize){
            if (s[right] == '1'){
                num = num * 2 + 1;
            }
            if (s[right] == '0'){
                num = num * 2;    
            }
            if (num <= n){
                boolMap[num] = true;
            }
            right++;
        } else {
            if (s[left] == '1'){
                num = num - pow(2,right-left-1);
            }
            if (num <= n){
                boolMap[num] = true;
            }
            left++;
        }
    }
    for (int i=1; i<=n; i++){
        if (boolMap.find(i) == boolMap.end()){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "1";
    int n = 1;
    cout << queryString(s,n);
    return 0;
}