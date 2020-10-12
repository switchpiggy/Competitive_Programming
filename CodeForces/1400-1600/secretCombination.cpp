#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(ll i = 0; i < n; ++i) {
        string t = "";
        ll diff = 10 - (s[i] - '0');

        for(ll j = 0; j < n; ++j) {
            ll k = (i + j)%n;
            t += ((s[k] - '0' + diff)%10 + '0'); 
        }

        v.push_back(t);
    }

    sort(v.begin(), v.end());

    cout << v.front() << '\n';
    return 0;
}