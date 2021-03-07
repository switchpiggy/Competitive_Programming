#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    cout << min(string(t, s + '0'), string(s, t + '0')) << '\n';
    return 0;
}