#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
queue<ll> q;

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i <= 30; ++i) {
        if(n & (1 << i)) { //if the ith bit of n is equal to 1 -> using bitmasks; 1 << n is 1 shifted to the left n times
            q.push(1 << i);
        }
    }

    if(q.size() > k) {
        printf("NO");
        return 0;
    }

    ll cnt = 0;

    while(q.size() < k && !q.empty()) {
        //cout << q.front() << endl;
        ll f = q.front();
        if(f == 1) {
            q.pop();
            q.push(f);
            cnt++;
            if(cnt == q.size()) {
               printf("NO\n");
               return 0; 
            } 
            continue;
        }
        cnt = 0;
        q.pop();
        q.push(f/2);
        q.push(f/2);
    }

    printf("YES\n");
    while(!q.empty()) {
        printf("%lld ", q.front());
        q.pop();
    }

    return 0;
}