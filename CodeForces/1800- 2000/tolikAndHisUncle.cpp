#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if(n == 2 && m == 3) {
        cout << "1 1\n1 3\n1 2\n2 2\n2 3\n2 1\n";
        return 0;
    }

    for(ll i = 0; i < n/2; ++i) {
        for(ll j = 0; j < m; ++j) {
            cout << i + 1 << ' ' << j + 1 << '\n';
            cout << n - i << ' ' << m - j << '\n';
        }
    }

    if(n%2) {
        deque<ll> q;
        cout << (n + 1)/2 << ' ' << 1 << '\n';
        for(ll i = 2; i <= m; ++i) q.push_back(i);

        while(!q.empty()) {
            cout << (n + 1)/2 << ' ' << q.back() << '\n';
            q.pop_back();
            if(!q.empty()) {
                cout << (n + 1)/2 << ' ' << q.front() << '\n';
                q.pop_front();
            }
        }
    }

    return 0;
}