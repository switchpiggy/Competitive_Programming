#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> k;
    cout << max(a - k, 0ll) << ' ' << max(0ll, b - (k - min(k, a))) << '\n';
    return 0;
}