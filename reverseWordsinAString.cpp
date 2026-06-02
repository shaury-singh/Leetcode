#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string reverseWords(string s) {
    char delimiter = ' ';
    stringstream ss(s);
    string token;
    vector<string> words;
    string ans;
    while (getline(ss, token, delimiter)) {
        words.push_back(token);
    }
    for (int i = words.size() - 1; i >= 0; i--) {
        if (words[i].empty()){
            continue;
        }
        if (!ans.empty()){
            ans += " ";
        }
        ans += words[i];
    }
    return ans;
}

int main(){
    string s = "Hello    World   ";
    cout << reverseWords(s);
    return 0;
}