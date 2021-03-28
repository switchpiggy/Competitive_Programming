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

struct matrix {
    ll maxn = 51;
    ll r, c;
    vector<vector<ll>> v;

    matrix operator *(matrix b) {
        matrix res(maxn, maxn);
        for(ll i = 0; i < maxn; ++i) {
            for(ll j = 0; j < maxn; ++j) {
                for(ll k = 0; k < maxn; ++k) {
                    (res.v[i][k] += v[i][j] * b.v[j][k]) %= MOD;
                }
            }
        }

        return res;
    }

    matrix(ll x, ll y) {
        r = x, c = y;
        v.assign(r, vector<ll>(c, 0));
    }

    matrix(vector<vector<ll>> x) {
        r = sz(x);
        c = sz(x[0]);
        v = x;
    }

    static matrix id(ll x, ll y) {
        matrix res = matrix(x, y);
        for(ll i = 0; i < x; ++i) {
            for(ll j = 0; j < y; ++j) {
                if(i == j) res.v[i][j] = 1;
            }
        }

        return res;
    }
};

matrix pow(matrix b, ll y) {
    if(!y) return matrix::id(b.r, b.c);
    matrix rec = pow(b, y/2), res = rec * rec;
    if(y%2) res = res * b;

    return res;
}

ll n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    matrix trans(51, 51);
    matrix base(51, 51);

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            ll x;
            cin >> x;
            trans.v[i][j] = x;
            if(!j) base.v[i][j] = 1;
        }
    }

    matrix res = pow(trans, k) * base;

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        (ans += res.v[i][0]) %= MOD;
    }

    cout << ans << '\n';
    return 0;
}