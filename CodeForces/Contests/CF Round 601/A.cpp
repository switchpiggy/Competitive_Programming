#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, mod[5] = {0, 1, 1, 2, 2};
ll t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
    cin >> a >> b;
    cout << abs(a - b)/5 + mod[abs(a - b)%5] << '\n';
    }
    return 0;
}