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
ll n, a[1007], b[1007];
bool used[1007];
vector<pair<ll, ll>> ans;

void solve(ll x) {
    if(x == 1) return;
    vector<ll> pos(n + 1);
    for(ll i = 1; i < x; ++i) {
        if(a[i] > a[x]) {
            pos[a[i]] = i;   
            a[i]--;
        }
    }
    
    for(ll i = a[x] + 1; i <= x; ++i) {
        ans.push_back({pos[i], x});
    }

    a[x] = x;
    solve(x - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];

    sort(b + 1, b + n + 1);
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            if(a[j] == b[i] && !used[j]) {
                used[j] = 1;
                a[j] = i;
                break;
            }
        }
    }

    solve(n);

    cout << sz(ans) << '\n';
    for(pair<ll, ll> p : ans) cout << p.first << ' ' << p.second << '\n';
    return 0;
}