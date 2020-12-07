#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, in[26];
vector<string> v;
vector<char> adj[26];
ll vis[26];
stack<char> res;

void dfs(char x) {
    if(vis[x - 'a'] == 1) {
        cout << "Impossible\n";
        exit(0);
    }

    if(vis[x - 'a'] == 2) return;
    vis[x - 'a'] = 1;
    for(char a : adj[x - 'a']) dfs(a);
    vis[x - 'a'] = 2;
    res.push(x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    for(ll i = 0; i < n - 1; ++i) {

        for(ll j = 0; j < (ll)v[i].length(); ++j) {
            if(j == (ll)v[i + 1].length()) {
                cout << "Impossible\n";
                return 0;
            }
            
            if(v[i][j] != v[i + 1][j]) {
                adj[v[i][j] - 'a'].push_back(v[i + 1][j]);
                in[v[i + 1][j] - 'a']++;
                break;
            }
        }
    }

    for(char i = 'a'; i <= 'z'; ++i) dfs(i);
    
    while(!res.empty()) {
        cout << res.top();
        res.pop();
    }

    return 0;
}