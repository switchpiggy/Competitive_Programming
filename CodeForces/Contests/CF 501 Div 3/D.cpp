#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> s;
    if(s > (n - 1) * k || s < k) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    ll cur = 1;
    while(k) {
        ll d = min(n - 1, s - (k - 1));
        if(cur - d >= 1) {
            cout << cur - d << ' ';
            cur -= d;
        } else {
            cout << cur + d << ' ';
            cur += d;
        }

        k--;
        s -= d;
    }

    return 0;
}