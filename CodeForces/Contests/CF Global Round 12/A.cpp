#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> a;
        sort(a.begin(), a.end());
        cout << a << '\n';
    }

    return 0;
}