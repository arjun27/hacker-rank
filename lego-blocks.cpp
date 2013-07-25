// lego-blocks
// accepted

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() { 
    int T; cin>>T;
    int N = 1000, M = 1000;
    long long total[1001][1001] = { 0 };
    // verify!
    total[1][1] = 1; total[1][3] = 4;
    total[1][2] = 2; total[1][4] = 8;
    // total[1][m] = total[1][m-1] + total[1][m-2] + 
    //               total[1][m-3] + total[1][m-4]
    // m <= M
    for (int m = 5; m <= M; m++) {
        total[1][m] = total[1][m-1] + total[1][m-2] 
            + total[1][m-3] + total[1][m-4];
        total[1][m] %= 1000000007;
    }
    for (int n = 2; n <= N; n++) {
        for (int m = 1; m <= M; m++) {
            total[n][m] = (total[1][m] % 1000000007) * (total[n-1][m] % 1000000007);
            total[n][m] %= 1000000007;
        }
    }
    for (int t = 0; t < T; t++) {
        cin>>N>>M;
        // N is height, M is width
        long long separable[1001] = { 0 };
        long long non_sep[1001] = { 0 };
        separable[1] = 0;
        non_sep[1] = 1;
        for (int m = 2; m <= M; m++) {
            for (int i = 1; i <= m-1; i++) {
                separable[m] += total[N][i]*non_sep[m-i];
                separable[m] %= 1000000007;
            }
            non_sep[m] = total[N][m] - separable[m];
            non_sep[m] %= 1000000007;
            if (non_sep[m] < 0) non_sep[m] += 1000000007;
        }
        cout<<non_sep[M]<<endl;
    }
    return 0;
}