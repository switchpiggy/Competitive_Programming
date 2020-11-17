#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(ll i = 0; i < (ll)s.length() - 1; ++i) {
       if(s[i + 1] < s[i]) {
           s.erase(s.begin() + i);
           cout << s << '\n';
           return 0;
       }
    }

    cout << s.substr(0, (ll)s.length() - 1) << '\n';
    return 0;
}