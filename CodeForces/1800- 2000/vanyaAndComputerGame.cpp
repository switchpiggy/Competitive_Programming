#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];
long double x, y;
vector<string> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x >> y;
    long double xh = 0, yh = 0;
    while(xh < x && yh < y) {
        if((1 + xh)/x < (1 + yh)/y) {
            ans.push_back("Vanya\n");
            xh++;
        } else if((1 + xh)/x > (1 + yh)/y) {
            ans.push_back("Vova\n");
            yh++;
        } else {
            ans.push_back("Both\n");
            ans.push_back("Both\n");
            yh++, xh++;
        }
    }

    //ll cntx = 0, cnty = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        cout << ans[(a[i] - 1)%(ll)(x + y)];
    }
    return 0;
}