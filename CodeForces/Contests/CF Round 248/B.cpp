#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m0(x) memset(x, 0, sizeof(x))
#define m1(x) memset(x, 1, sizeof(x))
#define mn1(x) memset(x, -1, sizeof(x))
#define flout cout << fixed << setprecision(12)
ll n, m, v[100007], s[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        cin >> v[i];
        s[i] = v[i];
    }

    sort(s + 1, s + n + 1);
    for(ll i = 1; i <= n; ++i) {
        v[i] += v[i - 1];
        s[i] += s[i - 1];
    }

    cin >> m;
    while(m--) {
        ll type, l, r;
        cin >> type;
        if(type == 1) {
            cin >> l >> r;
            cout << v[r] - v[l - 1] << '\n';
        } else {
            cin >> l >> r;
            cout << s[r] - s[l - 1] << '\n';
        }
    }

    return 0;
}