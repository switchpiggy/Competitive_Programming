#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;
string n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        cout << (ll)n.length() << '\n';
    }

    return 0;
}