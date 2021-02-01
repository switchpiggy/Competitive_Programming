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
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793238
#define MOD 1000000007 
#define flout cout << fixed << setprecision(12)
ll n, a[200007], b[200007], in[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i]; 
    for(ll i = 1; i <= n; ++i) {
        cin >> b[i];
        if(b[i] == -1) continue;
        in[b[i]]++;
    }

    benq<ll> ben;
    for(ll i = 1; i <= n; ++i) {
        if(!in[i]) ben.push(i);
    }

    ll ans = 0;
    vector<ll> v, w;
    while(!ben.empty()) {
        ll f = ben.front();
        ben.pop();
        if(a[f] <= 0) {
            if(b[f] != -1) {
                in[b[f]]--;
                if(!in[b[f]]) ben.push(b[f]);
            }
            w.push_back(f);
            ans += a[f];
            continue;
        }

        v.push_back(f);
        ans += a[f];
        
        if(b[f] != -1) {
            in[b[f]]--;
            a[b[f]] += a[f];
            if(!in[b[f]]) ben.push(b[f]);
        }
    }

    reverse(all(w));

    cout << ans << '\n';
    for(ll i : v) cout << i << ' ';
    for(ll i : w) cout << i << ' ';
    cout << '\n';
    return 0;
}