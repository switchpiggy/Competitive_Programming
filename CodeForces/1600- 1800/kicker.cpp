#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
pair<ll, ll> a[2], b[2];
bool flag[2];

int main() {
    for(ll i = 0; i < 2; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    for(ll i = 0; i < 2; ++i) {
        cin >> b[i].first >> b[i].second;
    }

    for(ll i = 0; i < 2; ++i) {
        bool ok = 1;
        for(ll j = 0; j < 2; ++j) {
            if(a[i].second <= b[j].first || a[1 - i].first <= b[1 - j].second) {
                ok = 0;
                break;
            }
        }

        if(ok) {
            cout << "Team 1\n";
            return 0;
        }
    }

    for(ll i = 0; i < 2; ++i) {
        for(ll j = 0; j < 2; ++j) {
            if(flag[j]) continue;
            if(b[i].first > a[j].second && b[1 - i].second > a[1 - j].first) {
                flag[j] = 1;
            }
        }
    }


    cout << ((flag[0]&flag[1]) ? "Team 2\n" : "Draw\n");
    return 0;
}