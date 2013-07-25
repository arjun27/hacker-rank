// stockmax
// accepted

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int T;
long int N;
vector <long int> prices;
vector <long int> diffs;

vector <long int> diff_seq(vector <long int> prices) {
  vector <long int> diff;
  for (int i = 1; i < prices.size(); i++) {
    diff.push_back(prices[i] - prices[i-1]);
  }
  return diff;
}

int all_neg(vector <long int> diff) {
  for (int i = 0; i < diff.size(); i++)
    if (diff[i] > 0) return 0;
  return 1;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  cin>>T;
  for (int t = 0; t < T; t++) {
    cin>>N;
    for (int i = 0; i < N; i++) {
      long int cur;
      cin>>cur;
      prices.push_back(cur);
    }
    diffs = diff_seq(prices);
    if (all_neg(diffs)) cout<<0<<endl;
    else {
      long long total = 0;
      long long max_starting_from_here = 0;
        for (int i = diffs.size()-1; i >= 0; i--) {
            //cout<<"i: "<<i<<endl;
            //cout<<"diffs[i]: "<<diffs[i]<<endl;
	max_starting_from_here += diffs[i];
            //cout<<"max_starting_from_here: "<<max_starting_from_here<<endl;
	if (max_starting_from_here > 0) total += max_starting_from_here;
	if (max_starting_from_here < 0) max_starting_from_here = 0;
      }
      cout<<total<<endl;
    }
    prices.resize(0);
    diffs.resize(0);
  }
  return 0;
}
