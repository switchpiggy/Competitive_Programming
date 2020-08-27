#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q;

int main() {
    cin >> q;
    
    ll prev = 0;
    for(ll i = 2; i <= sqrt(q); ++i) {
        if(q%i == 0 && !prev) {
            q /= i;
            prev = i;
        }

        if(q%i == 0 && q > i) {
            cout << "1\n" << prev * i << endl;
            return 0;
        }
    }

    if(prev) cout << "2\n";
    else cout << "1\n0\n";

    return 0;
}