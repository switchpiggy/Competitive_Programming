#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

bool isPal(string x) {
    for(ll i = 0; i < (ll)x.length()/2; ++i) {
        if(x[i] != x[(ll)x.length() - 1 - i]) return 0;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    if(isPal(s) && isPal(s.substr(0, (ll)s.length()/2)) && isPal(s.substr((ll)s.length()/2 + 1))) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}