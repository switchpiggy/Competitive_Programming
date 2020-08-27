#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, ans = "";
ll cnt = 0;

int main() {
    cin >> s;

    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] == '1') cnt++;
        else ans += s[i];
    }

    ll p = -1;
    while(p + 1 < ans.length() && ans[p + 1] == '0') ++p;
    ans.insert(p + 1, string(cnt, '1'));

    cout << ans << endl;

    return 0;
}