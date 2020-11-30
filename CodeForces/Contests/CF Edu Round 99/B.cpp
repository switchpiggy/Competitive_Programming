#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> x;
        ll sum = 0, cur = 0;
        for(ll i = 1; i <= x; ++i) {
            cur++;
            sum += i;
            if(sum >= x) break;
        }

        for(ll i = cur; i >= 1; --i) {
            if(sum - (i + 1) >= x) {
                sum -= i + 1;
            }
        }

        cout << cur + (sum - x) << '\n';
    }

    return 0;
}