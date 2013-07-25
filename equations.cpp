// equations
// accepted

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long exp_factorial(long long N, long long p) {
    // return exponent of prime number p in N!
    /*
    long long expo = 0;
    for (int i = N; i >= p; i--) {
        int n = i;
        long long e = 0;
        while (n > 0) {
            if (n % p == 0) {
                n = n/p;
                e++;
            } else {
                expo += e; break;
            }
        }
    }
    return expo;
    */
    
    // v2: use legendre's theorem
    long long expo = 0;
    for (long long d = p; d <= N; d = d*p) {
        expo += N / d;
    }
    return expo;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long N; cin>>N;
    vector <int> sieve; sieve.resize(N+1);
    sieve[0] = -1; sieve[1] = -1;
    // 1 means composite, 0 means prime
    for (long long i = 2; i <= N; i++) {
        if (sieve[i] == 1) continue;
        else {
            // start marking 1
            for (long long j = i; j <= N; j = j + i) sieve[j] = 1;
            sieve[i] = 0;
        }
    }
    long long ways = 1;
    for (long long i = N; i >= 2; i--) {
        if (sieve[i] == 1) continue;
        else {
            long long k = exp_factorial(N, i);
            // cout<<"expo for N "<<N<<" and prime "<<i<<" "<<k<<endl;
            ways *= ((2*k) + 1);
            ways = ways % 1000007;
        }
    }
    cout<<ways<<endl;
    return 0;
}