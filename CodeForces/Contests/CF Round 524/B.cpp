#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q, l, r;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> q;
    while(q--) {
        cin >> l >> r;
        ll len = (r - l + 1)/2;
        if(l%2 == 0 && r%2 == 0) cout << - 1* len + r << '\n';
        if(l%2 == 1 && r%2 == 1) cout << len - r << '\n';
        if(l%2 == 0 && r%2 == 1) cout << -1 * len << '\n';
        if(l%2 == 1 && r%2 == 0) cout << len << '\n';
    }
}