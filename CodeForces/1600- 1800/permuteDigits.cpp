#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;
    sort(x.begin(), x.end(), greater<char>());
    if((ll)x.length() < (ll)y.length()) {
        cout << x << '\n';
        return 0;
    }

    string cur;
    for(ll i = 0; i < (ll)x.length(); ++i) {
        for(ll j = 0; j < (ll)x.length(); ++j) {
            if(x[j] == '.' || (!i && x[j] == '0')) continue;
            if(x[j] == y[i]) {
                string res;
                for(ll k = 0; k < (ll)x.length(); ++k) if(x[k] != '.' && k != j) res += x[k];
                sort(res.begin(), res.end());

                string c = cur;
                c += x[j];
                c += res;
                //cout << c << '\n';
                if(c <= y) {
                    //cout << c << '\n';
                    cur += x[j];
                    x[j] = '.';
                    break;
                }
            }

            if(x[j] < y[i]) {
                cur += x[j];
                x[j] = '.';
                string ans;
                for(ll k = 0; k < (ll)x.length(); ++k) if(x[k] != '.') ans += x[k];

                sort(ans.begin(), ans.end(), greater<char>());
                cout << cur << ans << '\n';
                return 0;                
            }
        }
    }

    cout << cur << '\n';
    return 0;
}