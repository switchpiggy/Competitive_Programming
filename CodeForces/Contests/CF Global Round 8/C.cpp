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
ll n;
vector<pair<ll, ll>> v;
void solve(ll x, ll y, ll cnt) {
    if(!cnt) return;
    v.push_back({x + 1, y});
    v.push_back({x, y + 1});
    v.push_back({x + 1, y + 1});
    solve(x + 1, y + 1, cnt - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    // vector<pair<ll, ll>> v;
    v.push_back({0, 1});
    v.push_back({1, 0});
    v.push_back({1, 1});
    v.push_back({0, 0});
    solve(1, 1, n);

    cout << sz(v) << '\n';
    for(pair<ll, ll> i : v) cout << i.first << ' ' << i.second << '\n';
    return 0;
}