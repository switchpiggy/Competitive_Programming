#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> c;
    if(n < a  && n < b) {
        cout << 0 << '\n';
        return 0;
    } else if(n < b) {
        cout << n/a << '\n';
        return 0;
    }

    
    cout << max(n/a, (n - c)/(b - c) + max(0ll, (n - (((n - c)/(b - c)) * (b - c)))/a)) << '\n';

    return 0;
}