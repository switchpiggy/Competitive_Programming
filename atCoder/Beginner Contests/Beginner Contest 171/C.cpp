#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

string getAns(ll x) {
    string ans = "";

    while(x) {
        x--;
        ll cur = x%26;
        ans.push_back('a' + x%26);
        x /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    scanf("%lld", &n);

    cout << getAns(n) << endl;
}