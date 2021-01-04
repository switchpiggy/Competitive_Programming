#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll t, w, h, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> w >> h >> n;
        ll cnt = 1;
        while(w%2 == 0) {
            cnt *= 2;
            w /= 2;
        }

        while(h%2 == 0) {
            cnt *= 2;
            h /= 2;
        }

        if(cnt >= n) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}