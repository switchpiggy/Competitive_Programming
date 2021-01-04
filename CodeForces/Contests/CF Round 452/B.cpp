#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //leap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll n, a[30];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];

    for(ll j = 0; j < 12; ++j) {
        bool used = 0, ok = 1;
        for(ll i = 0; i < n; ++i) {
            if(a[i] != month[(j + i)%12]) {
                if(!used && (j + i)%12 == 1 && a[i] == 29) {
                    used = 1;
                } else {
                    ok = 0;
                    break;
                }
            }
        }

        if(ok) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}