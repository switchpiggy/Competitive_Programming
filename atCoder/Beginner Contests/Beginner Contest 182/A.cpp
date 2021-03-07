#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll b, a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    cout << max(0ll, 2 * a + 100 - b) << '\n';
    return 0;
}