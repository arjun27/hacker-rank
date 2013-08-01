// accepted

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int T; cin>>T;
    vector <int> l_from, l_to, s_from, s_to;
    int graph[101][101];
    for (int t = 0; t < T; t++) {
        l_from.resize(0); s_from.resize(0);
        l_to.resize(0); s_to.resize(0);
        int s, l;
        cin>>l; getchar(); cin>>s;
        for (int i = 0; i < l; i++) {
            int now; cin>>now; getchar();
            l_from.push_back(now); 
            cin>>now; l_to.push_back(now);
        }
        for (int i = 0; i < s; i++) {
            int now; cin>>now; getchar();
            s_from.push_back(now); 
            cin>>now; s_to.push_back(now);
        }
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                graph[i][j] = 0;
            }
        }
        for (int i = 1; i < 100; i++) {
            for (int j = i+1; j <= 100 && j <= i+6; j++) {
                graph[i][j] = 1; // edge u->v exists
            }
        }
        for (int i = 0; i < l; i++) {
            int from = l_from[i];
            for (int j = from+1; j <= 100 && j <= from+6; j++) {
                graph[from][j] = 0;
            }
            graph[from][l_to[i]] = 1;
        }
        for (int i = 0; i < s; i++) {
            int from = s_from[i];
            for (int j = from+1; j <= 100 && j <= from+6; j++) {
                graph[from][j] = 0;
            }
            graph[from][s_to[i]] = 1;
        }
        // bfs start
        queue <int> bfs;
        vector <int> score; score.resize(101);
        for (int i = 2; i <= 100; i++) {
            if (graph[1][i] != 0) {
                bfs.push(i);
                score[i] = 1;
            }
        }
        while (!bfs.empty()) {
            int now = bfs.front();
            bfs.pop();
            for (int i = 1; i <= 100; i++) {
                if (score[i] == 0) {
                    if (graph[now][i] != 0) {
                        bfs.push(i);
                        score[i] = score[now]+1;
                        if (i == 100) {
                            cout<<score[100]<<endl;
                            break;
                        }
                    }
                }
            }
        }
        // cout<<score[100]<<endl;
    }
    
    return 0;
}
