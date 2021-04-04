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
ll n, h[300007], dp[300007];
vector<ll> nxt[300007];
stack<ll> a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        cin >> h[i];
        if(i < n) nxt[i].push_back(i + 1);
    }

    for(ll i = 1; i <= n; ++i) {
        while(!a.empty() && h[a.top()] <= h[i]) nxt[a.top()].push_back(i), a.pop();
        while(!b.empty() && h[b.top()] >= h[i]) nxt[b.top()].push_back(i), b.pop();
        a.push(i);
        b.push(i);
    }

    while(sz(a)) a.pop();
    while(sz(b)) b.pop();

    for(ll i = n; i >= 1; --i) {
        while(!a.empty() && h[a.top()] <= h[i]) nxt[i].push_back(a.top()), a.pop();
        while(!b.empty() && h[b.top()] >= h[i]) nxt[i].push_back(b.top()), b.pop();
        a.push(i);
        b.push(i);
    }

    inf(dp);
    dp[1] = 0;
    for(ll i = 1; i < n; ++i) {
        for(ll j : nxt[i]) {
            dp[j] = min(dp[j], dp[i] + 1);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}