#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define flout cout << fixed << setprecision(12)
ll n, m, a[200007];
map<ll, ll> occ;

void no() {
    cout << "-1\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ll odd = 0, even = 0, lodd = 1, leven = 2;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i]%2) odd++;
        else even++;
        occ[a[i]]++;
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(occ[a[i]] <= 1) continue;
        if(odd > even && a[i]%2 == 1) {
            //if(leven > m) no();
            while(leven <= m && occ[leven]) leven += 2;
            if(leven > m) no();
            occ[a[i]]--;
            occ[leven]++;
            a[i] = leven;
            odd--;
            even++;
            ans++;
        } else if(even > odd && a[i]%2 == 0) {
            //if(lodd > m) no();
            while(lodd <= m && occ[lodd]) lodd += 2;
            if(lodd > m) no();
            occ[a[i]]--;
            occ[lodd]++;
            a[i] = lodd;
            even--;
            odd++;
            ans++;
        }
    }

    for(ll i = 0; i < n; ++i) {
        //if(taken.count(a[i]) <= 1) no();
        if(odd > even && a[i]%2 == 1) {
            //if(leven > m) no();
            while(leven <= m && occ[leven]) leven += 2;
            if(leven > m) no();
            occ[a[i]]--;
            occ[leven]++;
            a[i] = leven;
            odd--;
            even++;
            ans++;
        } else if(even > odd && a[i]%2 == 0) {
            //if(lodd > m) no();
            while(lodd <= m && occ[lodd]) lodd += 2;
            if(lodd > m) no();
            occ[a[i]]--;
            occ[lodd]++;
            a[i] = lodd;
            even--;
            odd++;
            ans++;
        } else if(occ[a[i]] > 1) {
            if(a[i]%2 == 1) {
                while(lodd <= m && occ[lodd]) lodd += 2;
                if(lodd > m) no();
                occ[a[i]]--;
                occ[lodd]++;
                a[i] = lodd;
                ans++;
            } else {
                while(leven <= m && occ[leven]) leven += 2;
                if(leven > m) no();
                occ[a[i]]--;
                occ[leven]++;
                a[i] = leven;
                ans++;
            }
        }
    }

    if(odd != even) {
        cout << "-1\n";
        return 0;
    }

    for(ll i = 0; i < n; ++i) {
        if(occ[a[i]] > 1) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << ans << '\n';
    for(ll i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}