#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    ll t = (a - b)/2;
    cout << a - t << ' ' << t << '\n';
    return 0;
}