// 6 on 9 submissions correct

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long factorial_mod[1000003] = { 0 };
// factorial_mod[j] = 0 for j >= 1000003

void compute_factorial_mod() {
    factorial_mod[0] = 1;
    for (int i = 1; i <= 1000002; i++) {
        factorial_mod[i] = factorial_mod[i-1] * i;
        factorial_mod[i] %= 1000003;
    }
}

/*
long long factorial_mod (long long k) {
    long long answer = 1;
    for (int i = k; i >= 1; i--) {
        answer *= i;
        answer %= 1000003;
    }
    return answer;
}
*/

long long power_mod (int d, int p) {
    long long answer = 1;
    for (int i = 0; i < p; i++) {
        answer *= d;
        answer %= 1000003;
    }
    return answer;
}

long long power_mod_2 (int d, int p) {
    if (p == 0) {
        return 1;
    } else if (p == 1) {
        return d;
    } else if (p == 2) {
        long long answer = d * d;
        answer %= 1000003;
        return answer;
    } else {
        long long part = power_mod_2(d, p/2);
        long long answer;
        if (p % 2 == 0) {
            answer = part * part;
        } else {
            answer = part * part * d;
        }
        answer %= 1000003;
        return answer;
    }
}

int main() {
    long int N; cin>>N;
    vector <int> a, d, p;
    a.resize(N); d.resize(N); p.resize(N);
    vector <long long> power_d(N, 0);
    for (long int n = 0; n < N; n++) {
        cin>>a[n]; cin>>d[n]; cin>>p[n];
        power_d[n] = power_mod_2(d[n], p[n]);
    }
    compute_factorial_mod();
    long int Q; cin>>Q;
    for (int q = 0; q < Q; q++) {
        int type, value;
        long int i, j;
        cin>>type>>i>>j;
        if (type == 1) {
            cin>>value;
            long int start = i-1;
            while (start <= j-1) {
                p[start] += value;
                if (power_d[start] != 0) {
                    power_d[start] *= power_mod_2(d[start], value);
                    power_d[start] %= 1000003;
                }
                start++;
            }
        } else {
            long long k = 0, value = 1;
            long int start = i-1;
            while (start <= j-1) {
                k += p[start];
                if (power_d[start] != 0) {
                    value *= power_d[start];
                } else {
                    power_d[start] = power_mod_2(d[start], p[start]);
                    value *= power_d[start];
                }
                value %= 1000003;
                start++;
            }
            if (k < 1000003) value *= factorial_mod[k];
            else value = 0;
            value %= 1000003;
            cout<<k<<" "<<value<<endl;
        }
    }
    return 0;
}