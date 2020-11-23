#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        cin >> a >> b;
        ll l = 0, r = 1000001;
        ll ans = -1;
        while(l < r) {
            ll m = (l + r)/2;
            //cout << l << ' ' << r << '\n';
            if(m * m * m == a * b) {
                ans = m;
                break;
            } else if(m * m * m < a * b) {
                l = m + 1;
            } else r = m;
        }

        if(ans != -1 && a%ans == 0 && b%ans == 0) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}