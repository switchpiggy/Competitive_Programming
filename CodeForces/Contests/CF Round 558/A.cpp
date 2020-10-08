#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    if(k == 0) {
        cout << 1 << '\n';
        return 0;
    }

    cout << min(n - k, k) << '\n';
    return 0;
}