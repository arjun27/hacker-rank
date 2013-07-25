// binomial-coefficients
// 1 on 20 correct

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int is_zero (char* s) {
    int i = 0;
    while (s[i]) {
        if (s[i++] != '0') return 0;
    }
    return 1;
}

long int division(char* dividend, long int divisor, long int power) {
    char quotient[501];
    long int temp = 0;
    int i = 0, j = 0;
    while (dividend[i]) {
        temp = temp*10 + (dividend[i] - '0');
        if (temp < divisor)
            quotient[j++] = '0';
        else {
            quotient[j++] = '0' + (temp / divisor);
            temp = temp % divisor;
        }
        i++;
    }
    quotient[j] = '\0';
    //printf("quotient %s\n", quotient);
    if (!quotient[0] || is_zero(quotient)) {
        //printf("zero %s\n", quotient);
        return 0;
    }
    long int ways = divisor - 1 - temp;
    // calculate ways from remainder (= temp)
    
    return ways + division(quotient, divisor, power+1);
}

int main () {
    int T; cin>>T;
    for (int t = 0; t < T; t++) {
        char n_string[501] = { 0 };
        int res = scanf("%s", n_string);
        long int p; cin>>p;
        
        long int ans = 0;
        cout<<division(n_string, p, 1)<<endl;
    }
    return 0;
}