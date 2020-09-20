#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, k;
string n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> k >> n;
        bool ok = 0;
        for(ll i = 1; i < k; i += 2) {
            if((n[i] - '0')%2 == 0) {
                ok = 1;
                break;
            }
        }
        
        bool ok2 = 0;
        for(ll i = 0; i < k; i += 2) {
        	if((n[i] - '0')%2 == 1) {
        		ok2 = 1;
        		break;
        	}
        }

        if((k%2 == 0 && !ok) || (k%2 == 1 && ok2)) cout << 1 << '\n';
        else cout << 2 << '\n';
    }

    return 0;
}