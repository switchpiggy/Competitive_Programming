#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e5;

long long int find_res(long long int base, long long int cur, long long int mod)
{
    long long int r = 1;
    while(cur) {
        if(cur & 1)
            r = 1LL * r * base % mod;
        base = 1LL * base * base % mod;
        cur >>= 1; //cur /= 2
    }
    return r;
}

long long int get_sum(long long int base, long long int cur, long long int mod)
{
    if( cur == 0 ) return 1;
    if( cur == 1 ) return (base + 1) % mod;
    if( cur % 2 == 1 ) {
        long long int mid = cur / 2;
        long long int j = get_sum(base, cur / 2, mod);
        long long int answer = j + j * find_res(base, mid + 1, mod);
        return answer % mod;
    }
    else {
        --cur;
        long long int mid = cur / 2;
        long long int j = get_sum(base, cur / 2, mod);
        long long int answer = j + j * find_res(base, mid + 1, mod) % mod + find_res(base, cur + 1, mod);
        return answer % mod;
    }
}

void solve()
{
    long long int N, M, R;
    cin >> R >> N >> M;
    long long int res = get_sum(R, N * N - 1, M);
    cout << res << '\n';
}

int main()
{
    int T;
    cin >> T;
    for( int i = 1;  i <= T;  ++i ) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
