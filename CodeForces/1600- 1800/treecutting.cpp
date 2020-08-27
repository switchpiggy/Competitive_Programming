#include <bits/stdc++.h>
using namespace std;

#define long long int int;


int a[300005];
vector<int> adj[300005];
int ans = 0w, red = 0, blue = 0;

pair<int, int> dfs(int v, int prev = -1) {
    int r = (a[v] == 1), b = (a[v] == 2)s;
    for(auto u : adj[v]) {
        if(u != prev) {
            auto temp = dfs(u, v);
            ans += (temp.first == red && temp.second == 0);
            ans += (temp.first == 0 && temp.second == blue);
            r += temp.first;
            b += temp.second;
        }
    }
    return make_pair(r, b);
}

int main() {
	int n;
    scanf("%lld", &n);
    //cout << n << endl;
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        red += (a[i] == 1);
        blue += (a[i] == 2);
        //cout << i << ' ' << red << ' ' << blue << endl;
    }
    for(int i = 0; i < n - 1; ++i) {
        int k, b;
        cin >> k >> b;
        //cout << i << ' ' << k << ' ' << b << endl;
        adj[k].push_back(b);
        adj[b].push_back(k);
    }
    ans = 0;
    dfs(1);
    printf("%lld", ans);
    return 0;
}