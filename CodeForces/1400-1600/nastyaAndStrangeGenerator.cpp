#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, p[100007], pos[100007];
bool visited[100007];

int main() {
    cin >> t;
    while(t--) {
        memset(visited, 0, sizeof(visited));
        bool ok = 1;
        cin >> n;
        for(ll i = 1; i <= n; ++i) cin >> p[i];
        for(ll i = 1; i <= n; ++i) {
            pos[p[i]] = i;
        }

        for(ll i = 1; i <= n; ++i) {
            if(visited[pos[i]]) continue;
            ll cur = pos[i];
            while(cur <= n) {
                visited[cur] = 1;
                if(cur == n || visited[cur + 1]) break;
                if(p[cur + 1] == p[cur] + 1) {
                    visited[cur] = 1;
                    cur++;
                    continue;
                }

                if(ok) cout << "No" << endl;
                ok = 0;
                break;
            }
        }

        if(ok) cout << "Yes" << endl;
    }

    return 0;
}