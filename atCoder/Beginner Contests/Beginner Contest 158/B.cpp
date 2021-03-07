#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;
    cout << n/(a + b) * a + min(a, n%(a + b)) << '\n';
}