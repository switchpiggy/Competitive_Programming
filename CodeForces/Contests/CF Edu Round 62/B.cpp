#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    
    while(t--) {
    cin >> n >> s;

    ll minPos = -1;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == '>') {
            minPos = i;
            break;
        }
    }

    ll maxPos = -1;
    for(ll i = n - 1; i >= 0; --i) {
        if(s[i] == '<') {
            maxPos = i;
            break;
        }
    }

    if(minPos == -1 || maxPos == -1) {
        cout << 0 << '\n';
        continue;
    }

    //cout << minPos << ' ' << maxPos << '\n';
    cout << min(minPos, n - 1 - maxPos) << '\n';
    }
    return 0;
}