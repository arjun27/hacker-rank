#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    string decoded;
    cin>>decoded;
    int length = decoded.length();
    int rows = 1, columns = 1;
    for (int i = 1; i <= 9; i++) {
        if (i*i == length) {
            rows = columns = i;
            break;
        } else if (i*i > length) {
            rows = i-1; columns = i;
            break;
        }
    }
    for (int i = 0; i < columns; i = i++) {
        for (int j = i; j < length; j = j + columns) {
            cout<<decoded[j];
        }
        cout<<" ";
    }
    return 0;
}
