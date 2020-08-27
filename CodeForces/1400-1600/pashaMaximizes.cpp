#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

string s;
ll t;

int main() {
    cin >> s >> t;

    for(ll i = 0; i < s.length(); ++i) {
        if(!t) break;
        ll maxn = -1, maxindex = -1;
        for(ll j = i; j < s.length() && j <= i + t; ++j) {
            if(s[j] - '0' > maxn) {
                maxn = s[j] - '0';
                maxindex = j;
            }
        }

        t -= abs(maxindex - i);
        //cout << t << endl;

        for(ll j = maxindex; j >= i + 1; --j) swap(s[j], s[j - 1]);
    }

    cout << s << endl;
    return 0;
}