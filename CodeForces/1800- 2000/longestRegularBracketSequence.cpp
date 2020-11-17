#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
stack<ll> st;
ll pre[1000007], cor[1000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for(ll i = 0; i < (ll)s.length(); ++i) pre[i] = cor[i] = -1;

    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == '(') st.push(i);
        else {
            if(st.empty()) continue;
            ll t = st.top();
            st.pop();
            cor[i] = t;
            if(t && pre[t - 1] != -1) pre[i] = pre[t - 1];
            else pre[i] = t;
        }
    }

    ll cnt = 1, maxn = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(pre[i] == -1) continue;
        if(i - pre[i] + 1 > maxn) {
            maxn = i - pre[i] + 1;
            cnt = 1;
        } else if(i - pre[i] + 1 == maxn) {
            cnt++;
        }
    }

    cout << maxn << ' ' << cnt << '\n';
    return 0;
}