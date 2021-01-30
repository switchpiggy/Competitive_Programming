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
#define flout cout << fixed << setprecision(12)
ll n, m, p, l[500007], r[500007], pa[500007];
string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p >> s >> t;
    stack<ll> st;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == ')') {
            if(!st.empty()) {
               pa[i] = st.top();
               pa[st.top()] = i;
               st.pop();
            }
        } else st.push(i);
    }

    for(ll i = 0; i < n; ++i) {
        l[i] = i - 1;
        r[i] = i + 1;
    }

    ll cur = p - 1;
    for(ll i = 0; i < m; ++i) {
        //cout << cur << '\n';
        if(t[i] == 'R') cur = r[cur];
        else if(t[i] == 'L') cur = l[cur];
        else {
            ll x = cur, y = pa[cur];
            if(x > y) swap(x, y);
            if(l[x] >= -1) r[l[x]] = r[y];
            if(r[y] < n) l[r[y]] = l[x];

            if(r[y] < n) cur = r[y];
            else cur = l[x];
        }

        //cout << cur << '\n';
    }

    while(l[cur] != -1) cur = l[cur];

    while(cur < n) {
        cout << s[cur];
        cur = r[cur];
    }

    return 0;
}