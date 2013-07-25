// substring-diff
// 1 on 10 correct

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T; cin>>T;
    for (int t = 0; t < T; t++) {
        int K; cin>>K;
        string p, q;
        cin>>p>>q;
        int misses = 0;
        int len = p.length();
        int max = 0;
        int max_i = 0, max_j = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                //cout<<i<<" "<<j<<endl;
                int x = 0;
                while (x <= len - 1 - i && 
                       x <= len - 1 - j) {
                    if (p[i+x] != q[j+x])
                        misses++;
                    //cout<<"x "<<x<<" misses "<<misses<<endl;
                    if (misses > K) {
                        misses = 0;
                        if (max < x) {
                            max = x;
                            max_i = i; max_j = j;
                        }
                        //cout<<"max "<<max<<endl;
                        break;
                    }
                    x++;
                }
                if (misses <= K) {
                    if (max < x) {
                        max = x;
                            max_i = i; max_j = j;
                    }
                }
            }
        }
        cout<<max<<endl;
        //cout<<max_i<<endl<<max_j<<endl<<max<<endl<<endl;
    }
    return 0;
}