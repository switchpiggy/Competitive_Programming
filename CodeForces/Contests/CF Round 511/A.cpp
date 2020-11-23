#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(n%3 == 0) cout << 1 << ' ' << 1 << ' ' << n - 2 << '\n';
    else if(n%3 == 1) cout << 1 << ' ' << 1 << ' ' << n - 2 << '\n';
    else cout << 1 << ' ' << 2 << ' ' << n - 3 << '\n';

    return 0;
}