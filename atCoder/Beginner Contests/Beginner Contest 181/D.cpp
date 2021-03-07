#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m1(x) memset(x, 1, sizeof(x))
#define m0(x) memset(x, 0, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define INF 0x3f3f3f3f3f3f3f3f
#define flout cout << fixed << setprecision(12)
string s;
ll cnt[8];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for(char i : s) {
        cnt[(i - '0')%8]++;
    }

    if(sz(s) <= 3) {
        sort(all(s));
        do {
            ll x = stoll(s);
            if(x%8 == 0) {
                cout << "Yes\n";
                return 0;
            }
        } while(next_permutation(all(s)));

        cout << "No\n";
        return 0;
    }

    for(ll i = 0; i < 8; ++i) {
        for(ll j = 0; j < 8; ++j) {
            for(ll k = 0; k < 8; ++k) {
                if(!cnt[i] || !cnt[j] || !cnt[k]) continue;
                if(i == j && cnt[i] < 2) continue;
                if(j == k && cnt[j] < 2) continue;
                if(i == k && cnt[i] < 2) continue;
                if(i == j && j == k && cnt[i] < 3) continue;
                if((100 * i + 10 * j + k)%8 == 0) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";
    return 0;
}