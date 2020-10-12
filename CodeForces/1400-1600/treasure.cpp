#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    ll a = 0, b = 0, last = (ll)s.length() - 1;

    for(ll i = (ll)s.length() - 1; i >= 0; --i) {
        if(s[i] == '#') {
            last = i;
            break;
        }
    }

    ll totala = 0, totalb = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == ')') totalb++;
        else if(s[i] == '(') totala++;
    }

    ll totalc = totala - totalb;

    ll totalhash = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == '#') totalhash++;
    }

    if(totalc < totalhash) {
        cout << "-1\n";
        return 0;
    }


    vector<ll> ans;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == '(') a++;
        else if(s[i] == ')') b++;
        else {
            if(last == i) {
                b += totalc;
                ans.push_back(totalc);
            } else {
                b++;
                totalc--;
                ans.push_back(1);
            }
        }

        if(b > a) {
            cout << "-1\n";
            return 0;
        }
    }

    for(ll i = 0; i < (ll)ans.size(); ++i) cout << ans[i] << '\n';
    cout << '\n';

    return 0;
}