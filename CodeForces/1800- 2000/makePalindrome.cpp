#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll cnt[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for(ll i = 0; i < (ll)s.length(); ++i) cnt[s[i] - 'a']++;

    ll l = 0, r = 25;
    while(cnt[l]%2 == 0 && l < 26) l++;
    while(cnt[r]%2 == 0 && r >= 0) r--;

    while(l < r) {
        cnt[r]--;
        cnt[l]++;
        l++, r--;
        while(l < 26 && cnt[l]%2 == 0) l++;
        while(r >= 0 && cnt[r]%2 == 0) r--;
    }

    char odd = '.';
    string res;
    for(ll i = 0; i < 26; ++i) {
        if(cnt[i]%2 == 1) {
            cnt[i]--;
            odd = i + 'a';
        }

        res += string(cnt[i]/2, i + 'a');
    }

    cout << res;
    if(odd != '.') cout << odd;
    reverse(res.begin(), res.end());
    cout << res << '\n';
    return 0;
}