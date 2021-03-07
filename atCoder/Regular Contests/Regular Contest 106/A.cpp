#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

ll pow5(ll x) {
    if(x == 1) return -1;
    ll cnt = 0;
    while(x > 1) {
        if(x%5 != 0) return -1;
        x /= 5;
        cnt++;
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll cur = 3, res = 1;
    while(cur <= n) {
        if(pow5(n - cur) != -1) {
            cout << res << ' ' << pow5(n - cur) << '\n';
            return 0;
        }

        cur *= 3;
        res++;
    }

    cout << "-1\n";
    return 0;
}