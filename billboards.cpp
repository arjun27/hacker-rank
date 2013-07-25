// 9 on 10 submissions

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

#define D 1
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long int N, K;
    vector <long long> a, v;
    cin>>N; cin>>K;
    a.resize(N); v.resize(N);
    for (int i = 0; i < N; i++) cin>>a[i];
    // v[k] is maximum till a[k]
    v[0] = a[0];
    for (int i = 1; i < K; i++) v[i] = a[i] + v[i-1];
    // cout<<v[K-1]<<endl;
    for (int i = K; i < N; i++) {
        long long max = v[i-1];
        // cout<<i<<" "<<max<<endl;
        long long sum = 0;
        for (int k = 1; k <= K; k++) {
            sum += a[i-k+1];
            long long now = 0;
            if (i-k >= 1) now = v[i-1-k] + sum;
            else now = sum;
            if (max < now) max = now;
        }
        // cout<<i<<" "<<max<<endl;
        v[i] = max;
    }
    cout<<v[N-1]<<endl;
    return 0;
}
