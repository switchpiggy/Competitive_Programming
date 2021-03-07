#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    cin >> s;
    ll sum = 0;
    for(ll i = 0; i < s.length(); ++i) {
        sum += s[i] - '0';
    }

    if(sum%9 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
