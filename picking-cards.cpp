// picking-cards
// accepted

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T; cin>>T;
    unsigned int N; vector <unsigned int> c;
    for (int t = 0; t < T; t++) {
        cin>>N;
        for (int n = 0; n < N; n++) {
            unsigned int now; cin>>now;
            c.push_back(N-now);
        }
        sort(c.begin(), c.end());
        long long ways = 1;
        for (int i = 0; i < N; i++) {
            if (c[i] >= i+1) ways = ways * (c[i] - i) % 1000000007;
            else {
                ways = 0;
                break;
            }
        }
        cout<<ways<<endl;
        c.clear();
    }
    return 0;
}
