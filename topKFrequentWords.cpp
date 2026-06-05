#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string> 
#include <algorithm>

using namespace std;

class Compare {
    public:
        bool operator()(pair<string,int> a, pair<string,int> b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    priority_queue<pair<string,int>, vector<pair<string,int>>, Compare> min_pq;
    vector<string> result = {};
    unordered_map<string,int> map = {};
    for (string s : words){
        map[s]++;
    }
    for (auto& s : map){
        if (min_pq.size() < k){
            min_pq.push(pair(s.first,s.second));
        } else {
            if (s.second > min_pq.top().second){
                min_pq.pop();
                min_pq.push(pair(s.first,s.second));
            }
        }
    }
    while (min_pq.empty() == false){
        result.push_back(min_pq.top().first);
        min_pq.pop();
    }
    // sort(result.begin(),result.end());
    return result;
}

int main(){
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;
    vector<string> result = topKFrequent(words,k);
    for (int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}