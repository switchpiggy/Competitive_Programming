#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m, temp, evenpos, oddpos, evenneg, oddneg; 

int main() {
    cin >> t;
    while(t--) {
        evenpos = 0, oddpos = 0, evenneg = 0, oddneg = 0;
        cin >> n;
        for(ll i = 0; i < n; ++i) {
            cin >> temp;
            if(temp%2 == 0) evenpos++;
            else oddpos++;
        }

        cin >> m;
        for(ll i = 0; i < m; ++i) {
            cin >> temp;
            if(temp%2 == 0) evenneg++;
            else oddneg++;
        }

        cout << evenpos * evenneg + oddpos * oddneg << endl;
    }

    return 0;
}