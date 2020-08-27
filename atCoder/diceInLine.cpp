#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
double p;
vector<double> v;

int main() {
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        cin >> p;
        double j = (p + 1)/2;
        v.push_back(j);
    }

    double res = 0, cnt = 0;
    for(ll i = 0; i < k; ++i) {
        res += v[i];
        cnt += v[i];
    }

    for(ll i = 1; i < n - k + 1; ++i) {
        cnt -= v[i - 1];
        cnt += v[i + k - 1];
        res = max(res, cnt);
    }

    printf("%.12llf\n", res);
    return 0;
}