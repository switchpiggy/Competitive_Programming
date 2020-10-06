#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> q;
    while(q--) {
        cin >> n;
        ll ans = 0;
        while(n%5 == 0) {
            ans += 3;
            n /= 5;
        }

        while(n%3 == 0) {
            ans += 2;
            n /= 3;
        } 

        while(n%2 == 0) {
            ans++;
            n /= 2;
        }

        if(n == 1) cout << ans << '\n';
        else cout << "-1\n";
    }

    return 0;
}