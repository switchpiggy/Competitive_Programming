#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string s;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> s;
        for(ll i = 0; i < n; ++i) cout << s[n - 1];
        cout << endl;
    }    

    return 0;
}