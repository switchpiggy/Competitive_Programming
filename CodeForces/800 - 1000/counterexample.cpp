#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll l, r;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> r;
    if(l%2) l++;
    if(l + 2 > r) {
        cout << "-1\n";
        return 0;
    }

    cout << l << ' ' << l + 1 << ' ' << l + 2 << '\n';
    return 0;
}