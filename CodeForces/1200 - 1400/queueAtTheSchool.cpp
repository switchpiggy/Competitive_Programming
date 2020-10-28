#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t >> s;
    for(ll i = 0; i < t; ++i) {
        for(ll j = 0; j < n - 1; ) {
            if(s[j + 1] == 'G' && s[j] == 'B') {
                s[j] = 'G';
                s[j + 1] = 'B';
                j += 2;
            } else j++;
        }
    }

    cout << s << '\n';
    return 0;
}