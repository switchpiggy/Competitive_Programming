#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define pb(x) push_back(x)
#define m1(x) memset(x, 1, sizeof(x))
#define m0(x) memset(x, 0, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b,a%b); }
void fileIO() {
    freopen("test.txt", "w", stdout);
    freopen("input-antennas-23df.txt", "r", stdin);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // fileIO();
    ll t;
    cin >> t;
    for (ll l = 1; l <= t; l ++) {
        cout << "Case #" << l << ":" << " ";
        ll n, k;
        cin >> n >> k;
        ll a[n], b[n];
        vector<ll> ap, bp, an, bn;
        for (ll i = 0; i < n; i ++) {
            ll a;
            cin >> a;
            if (a >= 0) {
                ap.pb(a);
            }
            else {
                an.pb(a);
            }
        }
        for (int i = 0; i < n; i ++) {
            int b;
            cin >> b;
            if (b >= 0) {
                bp.pb(b);
            }
            else {
                bn.pb(b);
            }
        }
        sort(ap.begin(), ap.end(), greater<ll>());
        sort(an.begin(), an.end());
        sort(bp.begin(), bp.end(), greater<ll>());
        sort(bn.begin(), bn.end());
        ll maxn = 0;
        ll counter = 0;
        ll np = 0;
        ll pp = 0;
        // frick i can't implement
// okay let me just explain
// so basically for max, you taking the minimum negatives and the maximum positives and multiplying them
// and then the rest just pair the minimum positive with the minimum negative
        if (k <= min(ap.size(), bp.size()) + min(an.size(), bn.size())) {
            while (np + pp < k) {
                if (pp < min(ap.size(), bp.size())) {
                    if (np < min(an.size(), bn.size())) {
                        if (ap[pp]*bp[pp] < an[np]*bn[np]) {
                            maxn += an[np]*bn[np];
                            np ++;
                        }
                        else {
                            maxn += ap[pp]*bp[pp];
                            pp ++;
                        }
                    }
                    else {
                        maxn += ap[pp]*bp[pp];
                        pp ++;
                    }
                }
                else {
                    maxn += an[np]*bn[np];
                    np ++;
                }
            }
        }
        else {
            while (np + pp < min(ap.size(), bp.size()) + min(an.size(), bn.size())) {
                if (pp < min(ap.size(), bp.size())) {
                    if (np < min(an.size(), bn.size())) {
                        if (ap[pp]*bp[pp] < an[np]*bn[np]) {
                            maxn += an[np]*bn[np];
                            np ++;
                        }
                        else {
                            maxn += ap[pp]*bp[pp];
                            pp ++;
                        }
                    }
                    else {
                        maxn += ap[pp]*bp[pp];
                        pp ++;
                    }
                }
                else {
                    maxn += an[np]*bn[np];
                    np ++;
                }
            }
            if (pp < bp.size()) {
                for (int i = 0; i < k-min(ap.size(), bp.size()) + min(an.size(), bn.size()); i ++) {
                    maxn += bp[pp + i]*an[np + i];
                }
            }
            else {
                for (int i = 0; i < k-min(ap.size(), bp.size()) + min(an.size(), bn.size()); i ++) {
                    maxn += ap[pp + i]*bn[np + i];
                }
            }
        }
        ll minn = 0;
        ll anbp = 0;
        ll bnap = 0;
        if (k <= min(ap.size(), bn.size()) + min(an.size(), bp.size())) {
            while (anbp + bnap < k) {
                if (anbp < min(an.size(), bp.size())) {
                    if (bnap < min(bn.size(), ap.size())) {
                        if (an[anbp]*bp[anbp] < ap[bnap]*bn[bnap]) {
                            minn += an[anbp]*bp[anbp];
                            anbp ++;
                        }
                        else {
                            minn += ap[bnap]*bn[bnap];
                            bnap ++;
                        }
                    }
                    else {
                        minn += an[anbp]*bp[anbp];
                        anbp ++;
                    }
                }
                else {
                    minn += ap[bnap]*bn[bnap];
                    bnap ++;
                }
            }
        }
        else {
            while (anbp + bnap < min(ap.size(), bn.size()) + min(an.size(), bp.size())) {
                if (anbp < min(an.size(), bp.size())) {
                    if (bnap < min(bn.size(), ap.size())) {
                        if (an[anbp]*bp[anbp] < ap[bnap]*bn[bnap]) {
                            minn += an[anbp]*bp[anbp];
                            anbp ++;
                        }
                        else {
                            minn += ap[bnap]*bn[bnap];
                            bnap ++;
                        }
                    }
                    else {
                        minn += an[anbp]*bp[anbp];
                        anbp ++;
                    }
                }
                else {
                    minn += ap[bnap]*bn[bnap];
                    bnap ++;
                }
            }
            if (anbp < an.size()) {
                ll pl = 0;
                ll pr = 0;
                for (int i = 0; i < k-min(ap.size(), bn.size()) + min(an.size(), bp.size()); i ++) {
                    if (an[anbp + pl]*bn[bn.size() - 1 - pl] < an[an.size() - 1 - pr]*bn[bnap+pr]) {
                        minn += an[anbp + pl]*bn[bn.size() - 1 - pl] ;
                        pl ++;
                    }
                    else {
                        minn += an[an.size() - 1 - pr]*bn[bnap+pr];
                        pr ++;
                    }
                    // minn += an[anbp + i]*bn[bn.size() - 1 - i];
                }
            }
            else {
                ll pl = 0;
                ll pr = 0;
                for (int i = 0; i < k-min(ap.size(), bn.size()) + min(an.size(), bp.size()); i ++) {
                    if (bp[anbp + pl]*ap[ap.size() - 1 - pl] < bp[bp.size() - 1 - pr]*ap[bnap+pr]) {
                        minn += bp[anbp + pl]*ap[ap.size() - 1 - pl] ;
                        pl ++;
                    }
                    else {
                        minn += bp[bp.size() - 1 - pr]*ap[bnap+pr];
                        pr ++;
                    }
                    // minn += an[anbp + i]*bn[bn.size() - 1 - i];
                }
            }
        }
        cout << minn << " " << maxn << endl;
        // cout << fac << endl << endl;
        // for (auto i: x) {
        //     cout << i << endl;
        // }
    }
}