#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, k;

int main() {
    cin >> k >> a >> b;
    for(ll i = a; i <= b; ++i) {
        if(i%k == 0) {
            cout << "OK" << endl;
            return 0;
        }
    }

    cout << "NG" << endl;
    return 0;
}