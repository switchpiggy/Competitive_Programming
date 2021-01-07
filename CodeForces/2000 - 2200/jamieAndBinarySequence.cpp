#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define pbenqueue priority_queue
ll n, k;
multiset<ll> st;
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i <= 60; ++i) {
        if(n & (1ll << i)) {
            st.insert(i);
            occ[i]++;
        }
    }

    bool smal = 0;
    while((ll)st.size() < k) {
        if(smal) {
            ll t = *st.begin();
            st.erase(st.find(t));
            occ[t]--;
            occ[t - 1] += 2;
            st.insert(t - 1);
            st.insert(t - 1);
        } else {
            ll t = *st.rbegin();
            if(occ[t] + (ll)st.size() > k) {
                smal = 1;
                continue;
            } else {
                st.erase(t);
                while(occ[t]--) {
                    st.insert(t - 1);
                    st.insert(t - 1);
                    occ[t - 1] += 2;
                }
            }
        }
    }

    if((ll)st.size() != k) cout << "No\n";
    else {
        cout << "Yes\n";
        for(auto i = st.rbegin(); i != st.rend(); ++i) cout << *i << ' ';
    }

    return 0;
}