#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
stack<ll> s, ss;
ll t;
string st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> st;
        while(!s.empty()) s.pop();
        while(!ss.empty()) ss.pop();

        ll ans = 0;
        for(ll i = 0; i < (ll)st.size(); ++i) {
            if(st[i] == '(') s.push(i);
            if(st[i] == '[') ss.push(i);

            if(st[i] == ')') {
                if(!s.empty()) {
                    ans++;
                    s.pop();
                }
            }

            if(st[i] == ']') {
                if(!ss.empty()) {
                    ans++;
                    ss.pop();
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}