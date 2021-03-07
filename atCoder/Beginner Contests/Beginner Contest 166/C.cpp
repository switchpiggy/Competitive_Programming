#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, h[100007], a, b;
bool ans[100007];

int main() {
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) cin >> h[i];
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b;
        if(h[a] > h[b]) ans[b] = 1;
        if(h[b] > h[a]) ans[a] = 1;
        if(h[b] == h[a]) ans[a] = ans[b] = 1;
    }

    ll res = 0;
    for(ll i = 1; i <= n; ++i) {
        if(!ans[i]) res++;
    }

    cout << res << endl;
    return 0;
}