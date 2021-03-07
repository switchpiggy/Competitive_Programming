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
ll n, q, a[200007], ans = 1;
multiset<ll> s[200007];
map<ll, ll> fact[200007];
vector<ll> p;
ll comp[200007];

void sieve() {
    for(ll i = 2; i <= 200000; ++i) {
        if(comp[i]) continue;
        comp[i] = i;
        p.push_back(i);
        for(ll j = i * i; j <= 200000; j += i) {
            if(!comp[j]) comp[j] = i;
        }
    }
}

void mult(ll ind, ll x) {
    while(x != 1) {
        ll cur = comp[x], cnt = 0;
        while(x%cur == 0) {
            cnt++;
            x /= cur;
        }

        ll last = 0;
        if(sz(s[cur]) == n) {
            last = *s[cur].begin();
        }

        if(fact[ind][cur]) {
            s[cur].erase(s[cur].find(fact[ind][cur]));
        }

        fact[ind][cur] += cnt;
        s[cur].insert(fact[ind][cur]);

        if(sz(s[cur]) == n) for(ll i = last; i < *s[cur].begin(); ++i) (ans *= cur) %= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    sieve();

    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        mult(i, a[i]);
    }

    /*for(ll i = 0; i < 3; ++i) {
        for(ll j : s[p[i]]) cout << j << ' ';
        cout <<  '\n';
    }*/

    // cout << ans << '\n';
    while(q--) {
        ll t, x;
        cin >> t >> x;
        t--;
        mult(t, x);

        cout << ans << '\n';
    }

    return 0;
}