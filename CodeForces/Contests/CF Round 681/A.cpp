#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
bool composite[407];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--) {
        cin >> n;
        ll cnt = n;
        memset(composite, 0, sizeof(composite));
        for(ll i = n; i <= 2 * n; ++i) {
            if(composite[i]) continue;
            cnt--;
            cout << i * 2 << ' ';

            for(ll j = i * 2; j <= 2 * n; j += i) composite[j] = 1;

        }
        cout << '\n';
        //cout << cnt << '\n';
    }
}