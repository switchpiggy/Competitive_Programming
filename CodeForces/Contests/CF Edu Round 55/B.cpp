#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, len[100007], p[100007];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    len[0] = 1;
    ll sCnt = 0, gCnt = 0;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == s[i - 1]) {
            len[i] = len[i - 1] + 1;
            //p[i] = p[i - 1];
        }
        else {
            len[i] = 1;
            //p[i] = p[i - 1];
        }

        sCnt += (s[i] == 'S');
        gCnt += (s[i] == 'G');
    }

    if(!sCnt) {
        cout << n << '\n';
        return 0;
    }

    p[n - 1] = n - 1;
    for(ll i = n - 2; i >= 0; --i) {
        if(s[i] == s[i + 1]) p[i] = p[i + 1];
        else p[i] = i;
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(i && i < n - 1 && s[i] == 'S' && s[i + 1] == s[i - 1] && s[i - 1] == 'G') {
            ans = max(ans, len[i - 1] + len[p[i + 1]] + (gCnt > len[i - 1] + len[p[i + 1]]));
        }

        if(s[i] == 'S' && sCnt) {
            if(s[i - 1] == 'G') ans = max(ans, len[i - 1] + (gCnt > len[i - 1]));
            if(s[i + 1] == 'G') ans = max(ans, len[p[i + 1]] + (gCnt > len[p[i + 1]]));
        }
    }

    cout << ans << '\n';
    return 0;
}