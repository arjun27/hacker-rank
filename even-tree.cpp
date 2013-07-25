// even-tree
// accepted

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int graph[101][101];
int scores[101];
int N, M;
int is_leaf(int i) {
    for (int j = 1; j <= N; j++) {
        if (graph[i][j] != 0) return 0;
    }
    return 1;
}
void comp_scores() {
    for (int i = N; i >= 1; i-- ) {
        if (is_leaf(i)) scores[i] = 1;
        else {
            scores[i] = 0;
            for (int j = i+1; j <= N; j++) {
                scores[i] += graph[i][j] * scores[j];
            }
            scores[i] += 1;
        }
    }
}
int main() {
    cin>>N; cin>>M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        int u, v; cin>>u; cin>>v;
        graph[v][u] = 1;
    }
    for (int i = 0; i < N+1; i++) {
        scores[i] = -1;
    }
    comp_scores();
    int even = 0;
    for (int i = 2; i <= N; i++) {
        if (scores[i] % 2 == 0) even++;
    }
    cout<<even<<endl;
    return 0;
}