#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b, c;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        ll cur = a, cur1 = c, cur2 = a * b, cur3 = c;
        if(cur >= cur1) cout << "-1" << ' ';
        else cout << 1 << ' ';
        if(cur2 <= cur3) cout << "-1" << endl;
        else cout << b << endl;
    }

    return 0;
}