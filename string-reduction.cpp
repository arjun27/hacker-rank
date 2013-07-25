// string-reduction
// 1 on 10 correct

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void push_mod(stack <char>& chars, char to_push) {
    if (chars.empty()) {
        chars.push(to_push);
    } else {
        char popped = chars.top();
        chars.pop();
        if (popped == to_push) {
            chars.push(popped); chars.push(to_push);
        } else {
            char possible[3] = {'a', 'b', 'c'};
            for (int k = 0; k < 3; k++ ) {
                if (possible[k] != to_push && possible[k] != popped) {
                    push_mod(chars, possible[k]);
                    break;
                }
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T; cin>>T;
    cin.ignore();
    for (int t = 0; t < T; t++) {
        string s; getline(cin, s);
        stack <char> chars;
        for (int i = 0; i < s.length(); i++) {
            push_mod(chars, s[i]);
        }
        // cout<<chars.size()<<endl;
        reverse(s.begin(), s.end());
        stack <char> rchars;
        for (int i = 0; i < s.length(); i++) {
            push_mod(rchars, s[i]);
        }
        // cout<<rchars.size()<<endl;
        int min_size = ( chars.size() < rchars.size() ) ? chars.size() : rchars.size();
        cout<<min_size<<endl;
    }
    return 0;
}