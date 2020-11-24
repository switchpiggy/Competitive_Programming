#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll s, p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> p;
    ll l = 0, r = (s + 1)/2 + 1;
    while(l < r) {
        ll m = (l + r)/2;
        if(m * (s - m) == p) {
            cout << "Yes\n";
            return 0;
        } else if(m * (s - m) > p) r = m;
        else l = m + 1;
    }

    cout << "No\n";
    return 0;
}