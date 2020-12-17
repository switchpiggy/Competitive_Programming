#include <bits/stdc++.h>
using namespace std;

int n, a[107], b[107], g[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> g[i];
    }

    int ans = 0;
    for(int pebble = 1; pebble <= 3; ++pebble) {
        int current_pebble = pebble, res = 0;
        for(int i = 1; i <= n; ++i) {
            if(current_pebble == a[i]) {
                current_pebble = b[i];
            } else if(current_pebble == b[i]) {
                current_pebble = a[i];
            }
    
            if(g[i] == current_pebble) res++;
        }

        ans = max(ans, res);
    }

    cout << ans << '\n';
    return 0;
}