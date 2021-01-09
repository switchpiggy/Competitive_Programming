#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[300007];
bool hill[300007], valley[300007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll sum = 0;

        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n; ++i) {
            hill[i] = valley[i] = 0;
            //cin >> a[i];
            if(i && i < n - 1) {
                if(a[i] > a[i - 1] && a[i] > a[i + 1]) {
                    sum++;
                    hill[i] = 1;
                }
                if(a[i] < a[i - 1] && a[i] < a[i + 1]) {
                    sum++;
                    valley[i] = 1;
                }
            }
        }

        ll sub = 0;
        for(ll i = 0; i < n; ++i) {
            if(i) {
                ll cnt = 0;
                if(hill[i - 1] || valley[i - 1]) cnt++;
                if(hill[i] || valley[i]) cnt++;
                if(i < n - 1 && hill[i + 1] && a[i - 1] >= a[i + 1]) cnt++;
                if(i < n - 1 && valley[i + 1] && a[i - 1] <= a[i + 1]) cnt++;
                if(i + 2 < n && !hill[i + 1] && a[i - 1] < a[i + 1] && a[i + 2] < a[i + 1]) cnt--;
                if(i + 2 < n && !valley[i + 1] && a[i - 1] > a[i + 1] && a[i + 2] > a[i + 1]) cnt--;
                //if(i == 2) cout << cnt << '\n';
                sub = max(sub, cnt);
            }

            if(i < n - 1) {
                ll cnt = 0;
                if(hill[i + 1] || valley[i + 1]) cnt++;
                if(hill[i] || valley[i]) cnt++;
                if(i && hill[i - 1] && a[i + 1] >= a[i - 1]) cnt++;
                if(i && valley[i - 1] && a[i + 1] <= a[i - 1]) cnt++;
                if(i - 2 >= 0 && !hill[i - 1] && a[i - 1] > a[i + 1] && a[i - 1] > a[i - 2]) cnt--;
                if(i - 2 >= 0 && !valley[i - 1] && a[i - 1] < a[i + 1] && a[i - 1] < a[i - 2]) cnt--;
                sub = max(sub, cnt);
            }
        }

        cout << sum - sub << '\n';
    }

    return 0; 
}