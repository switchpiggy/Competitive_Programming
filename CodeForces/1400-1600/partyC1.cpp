#include <bits/stdc++.h>

using namespace std;

bool adj[2005][2005];

bool visited[2005];

int n, m, k;

vector<pair<int, int>> d;

bool check(vector<int> res) {

    for(auto i = d.begin(); i != d.end(); ++i) {

        if(find(res.begin(), res.end(), i->first) != res.end() && find(res.begin(), res.end(), i->second) != res.end()) return false;

    }

    return true;

}

int dfs(int x) {

    stack<int> s;

    s.push(x);

    int size = 0;

    vector<int> res;
    
    res.push_back(x);

    while(!s.empty()) {

        int t = s.top();
        
        size++;

        s.pop();

        visited[t] = true;

        for(int i = 1; i <= n; ++i) {

            if(adj[t][i] && !visited[i] && find(res.begin(), res.end(), i) == res.end()) {

                s.push(i);

                res.push_back(i);

            }

        }
        

    }
    
    if(!check(res)) return 0;
    
    return size;

}

int main() {
    

    scanf("%d", &n);

    scanf("%d", &k);

    int a, b;

    for(int i = 0; i < k; ++i) {

        scanf("%d %d", &a, &b);

        adj[a][b] = adj[b][a] = 1;

    }

    scanf("%d", &m);

    for(int i = 0; i < m; ++i) {

        scanf("%d %d", &a, &b);

        d.push_back(make_pair(a, b));

        d.push_back(make_pair(b, a));

    }

    int ans = 0;

    for(int i = 1; i <= n; ++i) {

        if(!visited[i]) ans = max(ans, dfs(i));

    }

    printf("%d", ans);



}