#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m1(x) memset(x, 1, sizeof(x))
#define m0(x) memset(x, 0, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll l, r;
vector<pair<pair<ll, ll>, ll>> ans;

void edge(ll x, ll y, ll z) {
    ans.push_back({{x, y}, z});
    return;
}

ll solve(ll x, ll y) {  
    if(x > 1) {
        ll k = solve(1, y - x + 1);
        edge(k, k + 1, x - 1);

        return k + 1;
    }

    if((y & -y) == y) {
        ll k = __builtin_ctz(y);    
        edge(1, 2, 1);

        for(ll i = 3; i <= k + 2; ++i) {
            edge(1, i, 1);
            for(ll j = 2; j < i; ++j) {
                edge(j, i, (1 << (j - 2)));
            }
        }

        return k + 2;
    }

    ll k = 0;
    while(y - 1 >= (1 << k + 1)) ++k;
    solve(1, 1 << k);
    edge(1, k + 3, 1);

    for(ll i = 0; i <= k; ++i) {
        if((y - 1) & (1 << i)) {
            edge(i + 2, k + 3, 1 + ((y - 1) >> (i + 1) << (i + 1)));
        }
    }
    return k + 3;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> r;
    ll n = solve(l, r);
    cout << "YES\n";
    cout << n << ' ' << sz(ans) << '\n';
    for(pair<pair<ll, ll>, ll> i : ans) cout << i.first.first << ' ' << i.first.second << ' ' << i.second << '\n';

    return 0;
}