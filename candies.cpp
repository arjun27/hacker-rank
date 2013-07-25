// candies
// accepted

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

long int n, res = 0;
vector <long int> ratings;
vector <long int> candies_l;
vector <long int> candies_r;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin>>n;
    for (int i = 0; i < n; i++) {
        long int cur;
        cin>>cur;
        ratings.push_back(cur);
    }
    candies_l.resize(n, 1);
    candies_r.resize(n, 1);
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i-1])
            candies_l[i] = candies_l[i-1] + 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1])
            candies_r[i] = candies_r[i+1] + 1;
    }
    for (int i = 0; i < n; i++) {
        res += max(candies_r[i], candies_l[i]); 
    }
    cout<<res;
    return 0;
}