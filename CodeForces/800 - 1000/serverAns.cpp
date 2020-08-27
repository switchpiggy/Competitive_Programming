#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int N, K, M, P[100010], S[100010];

bool check(ll time) {
    vector<ll> proc;
    for (int i = 0; i < N; i++) {
        proc.push_back(max((ll) 0, (time - P[i]) / S[i]));
    }
    sort(proc.begin(), proc.end());
    ll cov = 0;
    for (int i = N - 1; i >= N - K; i--) cov += proc[i];
    return cov >= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);

    int TC; cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> N >> K >> M;
        for (int i = 0; i < N; i++) cin >> P[i] >> S[i];

        ll lo = 0, hi = 1;
        while (!check(hi)) hi *= 2;

        ll ans = hi;
        while (lo <= hi) {
            ll m = (lo + hi) / 2;
            if (check(m)) ans = min(ans, m), hi = m - 1;
            else lo = m + 1;
        }
        
        cout << "Case #" << tc << ": " << ans << "\n";
    }

    return 0;
}
