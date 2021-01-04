#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll s, v1, v2, t1, t2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> v1 >> v2 >> t1 >> t2;
    if(s * v1 + 2 * t1 < s * v2 + 2 * t2) cout << "First\n";
    else if(s * v1 + 2 * t1 == s * v2 + 2 * t2) cout << "Friendship\n";
    else cout << "Second\n";
    return 0;
}