#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map <char,int> charMap = {};
    int maxLen = 0;
    int left = 0;
    int right = 0;
    while (right < s.length()){
        if (charMap.find(s[right]) == charMap.end() || charMap[s[right]] == 0){
            charMap[s[right]]++;
        } else {
            charMap[s[left]]--;
            left++;
            continue;
        }
        int currLen = right - left + 1;
        maxLen = max(currLen,maxLen);
        right++;
    }
    return maxLen;
}

int main(){
    cout << lengthOfLongestSubstring("pwwkew");
    return 0;
}