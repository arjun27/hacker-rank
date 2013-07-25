// subsequence-weighting
// 1 on 10 correct

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int C; cin>>C;
    for (int c = 0; c < C; c++) {
        long int N; cin>>N;
        vector< pair< long int, long int > > sequence;
        vector <long int> a;
        for (int n = 0; n < N; n++) {
            long int now; cin>>now;
            a.push_back(now);
        }
        for (int n = 0; n < N; n++) {
            long int now; cin>>now;
            pair <long int, long int> foo = make_pair(a[n], now);
            sequence.push_back(foo);
        }
        vector <long int> value; value.resize(N);
        value[0] = sequence[0].second;
        //cout<<"value 0 "<<value[0]<<endl;
        for (int i = 1; i < N; i++) {
            long int max = 0;
            for (int j = i-1; j>=0; j--) {
                if (sequence[j].first < sequence[i].first &&
                       max < value[j])
                    max = value[j];
            }
            //cout<<"max "<<max<<endl;
            value[i] = sequence[i].second + max;
            //cout<<"value "<<i<<" "<<value[i]<<endl;
        }
        long int max = 0;
        for (int i = 0; i < N; i++) {
            if (max < value[i]) max = value[i];
        }
        cout<<max<<endl;
    }
    return 0;
}