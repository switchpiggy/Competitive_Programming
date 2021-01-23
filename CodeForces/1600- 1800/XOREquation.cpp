#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define benq queue
#define pbenq priority_queue
#define all(x) (x.begin(), x.end())
ll s, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> x;
    ll c = s - x;
    if(c < 0) {
        cout << "0\n";
        return 0;
    }

    ll cur = 1;
    //bool ok = 0;
    for(ll i = 0; i < 40; ++i) {
        if(x & (1ll << i)) {
            cur *= 2;
            //lasto = i;
        }
    }

    for(ll i = 39; i >= 0; --i) {
        if(!(x & (1ll << i)) && c >= (1ll << (i + 1))) {
            c -= 1ll << (i + 1);
        }
    }

    if(c == 0) cout << cur - 2 * ((s^0) == x) << '\n';
    else cout << "0\n";

    return 0;
}