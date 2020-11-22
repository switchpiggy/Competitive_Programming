#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, q, l, r, cnt[107][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        string s;
        cin >> n >> q >> s;
        memset(cnt, 0, sizeof(cnt[0][0]) * 107 * 2);
        for(ll i = 0; i < n; ++i) {
            if(i)  {
                cnt[i][1] = cnt[i - 1][1];
                cnt[i][0] = cnt[i - 1][0];
            }
            if(s[i] == '0') cnt[i][0]++;
            else cnt[i][1]++;
        }
        for(ll i = 0; i < q; ++i) {
            cin >> l >> r;
            l--;
            r--;

            if(cnt[n - 1][s[r] - '0'] - cnt[r][s[r] - '0']) cout << "YES\n";
            else if(l && cnt[l - 1][s[l] - '0']) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}