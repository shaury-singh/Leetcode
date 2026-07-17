#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

string removeDuplicateLetters(string s) {
    unordered_map<char,int> charMap = {};
    stack<char> charStack = {};
    stack<char> oppStack = {};
    string result = "";
    for (char c : s){
        cout << "current char is: " << c << endl;
        if (charMap[c] == 1){
            cout << "Alerady in CharMap" << endl;
            continue;
        } else {
            cout << "added to charMap" << endl;
            charMap[c] = 1;
        }
        if (charStack.empty()){
            cout << "charStack is Empty, added " << c << " to charStack" << endl;
            charStack.push(c);
        } else {
            if (charStack.top() < c){
                cout << charStack.top() << " is less than " << c << " pushing directly" << endl;
                charStack.push(c);
            } else {
                while (charStack.top() > c){
                    cout << charStack.top() << " is more than " << c << endl; 
                    char popC = charStack.top();
                    charStack.pop();
                    cout << "popped" << endl;
                    oppStack.push(popC);
                    cout << popC << " pushed into oppStack" << endl;
                    if (charStack.empty()) break;
                }
                charStack.push(c);
                cout << c << " pushed into charStack" << endl;
                while (oppStack.empty() == false){
                    char OppC = oppStack.top();
                    oppStack.pop();
                    cout << "Popped from oppStack" << endl;
                    charStack.push(OppC);
                    cout << "Pushed into charStack" << endl;
                }
            }
        }
    }  
    while (charStack.empty() == false){
        result += charStack.top();
        charStack.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    string s = "bcabc";
    cout << removeDuplicateLetters(s);
    return 0;
}