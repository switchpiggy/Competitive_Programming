    #include <bits/stdc++.h>
    using namespace std;

    typedef long long int ll;
    ll n, k;
    vector<ll> v;

    bool check(ll r) {
        ll mins = 0, cnt = 0;

        while(mins < n) {
            cnt++;
            ll cur = mins + 1;
            
            while(cur < n && v[cur] - v[mins] <= 2 * r) cur++;
            mins = cur;
        }
        
        if(cnt > k) return false;

        return true;
    }

    int main() {
        scanf("%lld %lld", &n, &k);
        for(ll i = 0; i < n; ++i) {
            ll temp;
            scanf("%lld", &temp);
            v.push_back(temp);
        }

        sort(v.begin(), v.end());

        ll l = 0, r = 1000000000;

        while(l != r) {
            ll mid = (l + r)/2;
            if(check(mid)) {
                r = mid;
            } else l = mid + 1;
        }

        printf("%lld\n", l);

        return 0;
    }