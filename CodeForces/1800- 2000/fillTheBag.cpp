#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m, a[100007], cnt[61];

ll fastlog(ll x) {
    if(x == 1) return 0;
    return 1 + fastlog(x/2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        memset(cnt, 0, sizeof(cnt));
        cin >> n >> m;
        
        ll sum = 0;
        for(ll i = 0; i < m; ++i) {
            cin >> a[i];
            cnt[fastlog(a[i])]++;
            sum += a[i];
        }

        if(sum < n) {
            cout << "-1\n";
            continue;
        }

        ll i = 0, ans = 0;
        while(i < 60) {
            if((n & (1ll << i))) {
                //cout << i << ' ';
                if(cnt[i]) {
                    cnt[i]--;
                } else {
                    while(i < 60 && !cnt[i]) {
                        ans++;
                        i++;
                    }

                    cnt[i]--;
                    continue;
                }
            }

            cnt[i + 1] += cnt[i]/2;
            i++;
        }

        cout << ans << '\n';
    }

    return 0;
}