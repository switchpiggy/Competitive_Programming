#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
vector<ll> a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for(ll i = 0; i < (ll)s.length() - 1; ++i) {
        if(s[i] == 'A' && s[i + 1] == 'B') a.push_back(i);
        if(s[i] == 'B' && s[i + 1] == 'A') b.push_back(i);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(!a.empty() && !b.empty() && (a[0] < b.back() - 1 || b[0] < a.back() - 1)) {
        cout << "YES\n";
    } else cout << "NO\n";

    return 0;
}