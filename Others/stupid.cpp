#include <bits/stdc++.h>

using namespace std;

    

int adj[10005][10005], graph[10005];

    int n, m;

set<int> edges;

void dfs(int x) {

    stack<int> s;

    s.push(x);

    while(!s.empty()) {

        int t = s.top();

        if(t == graph[x]) return;

        for(int i = 1; i <= n; ++i) {

            if(adj[t][i] != 0) {

            s.push(adj[t][i]);

            edges.insert(adj[t][i]);

            }


        }

    }

}

int main() {

    ifstream fin;

    ofstream fout;
    
    fin.open("wormsort.in");

    fout.open("wormsort.out");

    for(int i = 1; i <= n; ++i) fin >> graph[i];

    for(int i = 1; i <= m; ++i) {

        int c, b, d;

        fin >> c >> b >> d;

        adj[c][b] = d;

        adj[b][c] = d;

    }

    for(int i = 1; i <= n; ++i) dfs(i);

    fout << *edges.begin() << endl;

    fin.close();

    fout.close();


}