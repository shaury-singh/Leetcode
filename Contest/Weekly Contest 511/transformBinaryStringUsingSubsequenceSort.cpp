#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> transformStr(string s, vector<string>& strs) {
    string veltromina = s;
    int n = s.size();
    vector<int> pref0S(n);
    int zerosS = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') zerosS++;
        pref0S[i] = zerosS;
    }
    vector<bool> ans;
    for (string &t : strs) {
        int fixed0 = 0, q = 0;
        for (char c : t) {
            if (c == '0') fixed0++;
            else if (c == '?') q++;
        }
        int need = zerosS - fixed0;
        if (need < 0 || need > q) {
            ans.push_back(false);
            continue;
        }
        int pref0 = 0;
        int used = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (t[i] == '0') {
                pref0++;
            } else if (t[i] == '?') {
                if (used < need) {
                    pref0++;
                    used++;
                }
            }
            if (pref0 < pref0S[i]) {
                ok = false;
                break;
            }
        }
        ans.push_back(ok);
    }
    return ans;
}

int main(){
    string s = "1100";
    vector<string> strs = {"0011","11?1","1?1?"};
    vector<bool> result = transformStr(s,strs);
    for (bool b : result){
        cout << b << endl;
    }
}