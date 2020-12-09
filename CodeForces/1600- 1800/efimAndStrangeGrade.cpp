#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
//hopefully getting a CP girlfriend soon
ll n, t, dp[200007];
string s;

string add(string s) {
    ll i = (ll)s.length() - 1;

    while((s[i] == '9' || s[i] == '.') && i >= 0) {
        if(s[i] == '.') {
            i--;
            continue;
        }
        s[i] = '0';
        i--;
    }

    if(i >= 0) s[i]++;
    else s.insert(s.begin(), '1');
    if(s.back() == '.') s.pop_back();

    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t >> s;
    ll decimal;
    for(ll i = (ll)s.length() - 1; i >= 0; --i) {
        if(s[i] == '.') {
            decimal = i;
            dp[i] = dp[i + 1];
            continue;
        }
        if(s[i] >= '5') dp[i] = 1;
        else if(s[i] < '4') dp[i] = INT_MAX;
        else dp[i] = 1 + dp[i + 1];
    }

    for(ll i = decimal + 1; i < (ll)s.length(); ++i) {
        //cout << dp[i] << ' ';
        if(dp[i] <= t) {
            string cur = s.substr(0, i);
            //cout << cur << '\n';
            cout << add(cur) << '\n';
            return 0;
        }
    }

    cout << s << '\n';
    return 0;
}