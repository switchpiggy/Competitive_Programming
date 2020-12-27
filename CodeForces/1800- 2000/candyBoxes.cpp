    #include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<ll> a;

void output(ll x, ll y, ll z, ll zz) {
    for(ll i = 0; i < (ll)a.size(); ++i) {
        if(a[i] == x) x = -1;
        else if(a[i] == y) y = -1;
        else if(a[i] == z) z = -1;
        else if(a[i] == zz) zz = -1;
    }

    if(x != -1) cout << x << '\n';
    if(y != -1) cout << y << '\n';
    if(z != -1) cout << z << '\n';
    if(zz != -1) cout << zz << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a.push_back(x);
    }

    if(!n) {
        cout << "YES\n1\n2\n2\n3\n";
        return 0;
    }

    sort(a.begin(), a.end());
    //bool ok = 0;
    for(ll i = 1; i <= a.back(); ++i) {
        vector<ll> b(a);
        ll x4 = i * 3;
        ll cnt = 0;
        for(ll j = 0; j < (ll)b.size(); ++j) if(x4 == b[j]) {
            b[j] = -1;
            cnt++;
        }

        for(ll j = 0; j < (ll)b.size(); ++j) {
            if(b[j] != -1 && b[j] == i) {
                b[j] = -1;
                cnt++;
                break;
            }
        }

        if(cnt == (ll)b.size()) {
            cout << "YES\n";
            output(i, x4, (i + x4)/2, (i + x4)/2);
            //cout << i << '\n' << x4 << '\n' << (i + x4)/2 << '\n' << (i + x4)/2 << '\n';
            return 0;
        } else if(cnt == (ll)b.size() - 1) {
            for(ll j = 0; j < (ll)b.size(); ++j) {
                if(b[j] == -1) continue;
                ll d = (i + x4) - b[j];
                if(i <= b[j] && b[j] <= x4 && i <= d && d <= x4) {
                    cout << "YES\n";
                    output(i, x4, b[j], d);
                    //cout << i << '\n' << x4 << '\n' << b[j] << '\n' << d << '\n';
                    return 0;
                }
            }
        } else if(cnt == (ll)b.size() - 2) {
            ll y = -1, z = -1;
            for(ll j = 0; j < (ll)b.size(); ++j) {
                if(b[j] == -1) continue;
                if(y != -1) z = b[j];
                else y = b[j];
            }

            if(y + z == i + x4 && y >= i && y <= x4 && z >= i && z <= x4) {
                cout << "YES\n";
                output(i, y, z, x4);
                //cout << i << '\n' << y << '\n' << z << '\n' << x4 << '\n';
                return 0;
            }
        }
    }

    cout << "NO\n";
    return 0;
}