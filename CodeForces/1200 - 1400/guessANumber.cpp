#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, high = 1e9 + 1, low = -1e9 - 1;
char ans;
string type;

string rev(string s) {
    if(s == ">") return "<=";
    else if(s == ">=") return "<";
    else if(s == "<") return ">=";
    else return ">";
}

int main() {
    scanf("%lld", &n);

    for(ll i = 0; i < n; ++i) {
        cin >> type >> q >> ans;
        if(ans == 'N') {
            type = rev(type);
        }

        if(type == "<=") {
            high = min(high, q); 
        } else if(type == "<") {
            high = min(high, q - 1);
        } else if(type == ">") {
            low = max(low, q + 1);
        } else low = max(low, q);
    }

    if(low > high) printf("Impossible\n");
    else printf("%lld\n", high);

    return 0;
}