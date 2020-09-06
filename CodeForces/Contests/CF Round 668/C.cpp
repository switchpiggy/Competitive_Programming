#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k;
char ans[300007];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        memset(ans, ' ', sizeof(ans));
        cin >> n >> k >> s;

        bool ok = 1;
        
        for(ll i = 0; i < k; ++i) {
            char cur = '?';
            for(ll j = i; j < n; j += k) {
                if(s[j] != '?') {
                    if(cur == '?') {
                        cur = s[j];
                    } else {
                        if(s[j] != cur) {
                            ok = 0;
                            break;
                        }
                    }
                }
            }

            if(!ok) break;
            ans[i] = cur;
        }

        if(!ok) {
            cout << "NO\n";
            continue;
        }

        //for(ll i = 0; i < k; ++i) cout << ans[i] << endl;

        for(ll i = 0; i < k; ++i) {
            for(ll j = i; j < n; j += k) s[j] = ans[i];
        }

        //cout << s << endl;

        ll cnt = 0;
        for(ll i = 0; i < k; ++i) if(s[i] == '1') cnt++;
        for(ll i = 0; i < k; ++i) {
            if(cnt < k/2 && s[i] == '?') cnt++;
        }

        if(cnt == k/2) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}