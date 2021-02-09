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
ll n, a[100007], p[100007];
vector<ll> v[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        v[a[i]].push_back(i);
    }

    for(ll i = 0; i <= n; ++i) v[i].push_back(LLONG_MAX);

    ll x = 0, y = 0, ans = 0, ans1 = 0;
    for(ll i = 0; i < n; ++i) {
        p[a[i]]++;
        if(a[i] == x && a[i] == y) {
            continue;
        } else if(a[i] == x) {
            y = a[i];
            ans1++;
        } else if(y == a[i]) {
            x = a[i];
            ans++;
        } else {
            if(v[x][p[x]] < v[y][p[y]]) {
                x = a[i];
                ans++;
            } else {
                y = a[i];
                ans1++;
            }
        }
    }
    
    cout << ans + ans1 << '\n';
    return 0;
}