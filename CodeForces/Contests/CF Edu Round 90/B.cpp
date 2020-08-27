#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;
string s;

int main() {
    cin >> t;
    while(t--) {
        cin >> s;
        ll zero = 0, one = 0;
        for(ll i = 0; i < s.length(); ++i) {
            if(s[i] == '0') zero++;
            else one++;
        }

        if(min(zero, one)%2 == 0) cout << "NET" << endl;
        else cout << "DA" << endl;
    }

    return 0;
}