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
ll n, m, k;
vector<pair<ll, string>> v;

void pb(ll x, string c) {
    v.push_back({x, c});
}

void out() {
    cout << sz(v) << '\n';
    ll cnt = 0;
    for(pair<ll, string> i : v) cout << i.first << ' ' << i.second << '\n', cnt += i.first * sz(i.second);
    //cout << cnt << '\n';
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    if(k > 4 * n * m - 2 * (n + m)) {
        cout << "NO\n";
        return 0;
    }

    if(n == 1) {
        cout << "YES\n";
        ll cur = min(k, m - 1);
        k -= cur;
        pb(cur, "R");
        if(!k) out();
        cur = min(k, m - 1);
        pb(cur, "L");
        out();
    }

    if(m == 1) {
        cout << "YES\n";
        ll cur = min(k, n - 1);
        k -= cur;
        pb(cur, "D");
        if(!k) out();
        cur = min(k, n - 1);
        pb(cur, "U");
        out();
    }

    if(n == 2) {
        cout << "YES\n";
        if(k >= 2) {
            k -= 2;
            pb(1, "DU");
        }

        ll cur = min(k/5, m - 1);
        for(ll i = 0; i < cur; ++i) {
            k -= 5;
            pb(1, "R");
            pb(1, "DLRU");
        }

        if(k) {
            if(cur == m - 1) pb(1, string("LLLLL").substr(0, k));
            else pb(1, string("RDLRU").substr(0, k));
        }
        out();
    }

    if(m == 2) {
        if(k >= 2) {
            k -= 2;
            pb(1, "RL");
        }
        cout << "YES\n";
        ll cur = min(k/5, n - 1);
        for(ll i = 0; i < cur; ++i) {
            k -= 5;
            pb(1, "D");
            pb(1, "RUDL");
        }

        if(k) {
            if(cur == n - 1) pb(1, string("UUUUU").substr(0, k));
            else pb(1, string("DRUDL").substr(0, k));
        }
        out();
    }

    cout << "YES\n";
    for(ll i = 1; i < m; ++i) {
        if(!k) out();
        k--;
        pb(1, "R");
        if(!k) out();
        ll cur = min(k/3, n - 2), d = cur;
        k -= 3 * cur;
        if(cur) pb(cur, "DLR");
        if(k < 3) {
            if(k) pb(1, string("DLR").substr(0, k));
            out();
        }

        if(i < m - 1) {
            cur = min({d, k, n - 2});
            pb(cur, "U");
            k -= cur;
            if(!k) out();
        }
    }

    if(!k) out();
    k--;
    pb(1, "D");

    for(ll i = 1; i < m - 1; ++i) {
        if(k < 3) {
            if(k) pb(1, string("LUD").substr(0, k));
            out();
        }

        pb(1, "LUD");
        k -= 3;
        if(k < 3) {
            if(k) pb(1, string("LUD").substr(0, k));
            out();
        }
    }

    if(!k) out();
    k--;
    pb(1, "L");
    if(!k) out();

    ll cur = min(k, n - 1);
    k -= cur;
    pb(cur, "U");
    if(!k) out();

    cur = min(k, n - 1);
    k -= cur;
    pb(cur, "D");
    if(!k) out();

    cur = min(k, m - 1);
    k -= cur;
    pb(cur, "R");
    if(!k) out();

    // for(ll i = 1; i < m; ++i) {
        // if(!k) out();
        // pb(1, "R");
        // k--;
    // }

    for(ll i = 1; i < n; ++i) {
        if(!k) out();
        pb(1, "U");
        k--;
    }

    for(ll i = 1; i < m; ++i) {
        if(!k) out();
        pb(1, "L");
        k--;
    }

    out();
    return 0;
}