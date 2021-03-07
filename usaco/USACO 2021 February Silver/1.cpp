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
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll n, cnt[5007][5007], cur, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool cows[5007][5007], s[5007][5007];

void add_cow(ll, ll);

void fix_cow(ll x, ll y) {
    if(cnt[x][y] != 3) return;
    for(ll i = 0; i < 4; ++i) {
        // if(!is(x + dx[i], y + dy[i])) continue;
        if(!cows[x + dx[i]][y + dy[i]]) {
            cur++;
            s[x + dx[i]][y + dy[i]] = 1;
            add_cow(x + dx[i], y + dy[i]);
            break;
        }
    }

    return;
}

void add_cow(ll x, ll y) {
    //cout << x << ' ' << y << '\n';
    if(!cows[x][y]) {
        for(ll i = 0; i < 4; ++i) cnt[x + dx[i]][y + dy[i]]++;
        cows[x][y] = 1;
        if(cnt[x][y] == 3) fix_cow(x, y);
        for(ll i = 0; i < 4; ++i) if(cnt[x + dx[i]][y + dy[i]] == 3 && cows[x + dx[i]][y + dy[i]]) fix_cow(x + dx[i], y + dy[i]);
        // if(cnt[x][y] == 3) fix_cow(x, y);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        if(s[x + 2500][y + 2500]) cur--, s[x][y] = 0;
        add_cow(x + 2500, y + 2500);
        cout << cur << '\n';
    }

    return 0;
}