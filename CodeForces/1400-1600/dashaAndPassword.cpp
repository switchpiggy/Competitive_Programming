#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
string a[57];

bool issymbol(char c) {
    if(c == '#' || c == '*' || c == '&') return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = INT_MAX;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            for(ll k = 0; k < n; ++k) {
                if(i == j || j == k || i == k) continue;
                ll c = INT_MAX, in = INT_MAX, s = INT_MAX;

                for(ll l = 0; l < m; ++l) {
                    char ii = a[i][l], jj = a[j][l], kk = a[k][l];
                    if(isalpha(ii)) {
                        c = min(c, min(l, m - l));
                    }
                    if(isdigit(jj)) {
                        in = min(in, min(l, m - l));
                    }
                    if(issymbol(kk)) {
                        s = min(s, min(l, m - l));
                    }
                }

                if(c != INT_MAX && in != INT_MAX && s != INT_MAX) ans = min(ans, c + in + s);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}