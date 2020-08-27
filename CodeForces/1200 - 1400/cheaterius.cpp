#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string upper, lower, f;
set<string> piles;

string rotateAmulet(string s) {
    char temp = s[3];
    for(ll i = 0; i < 4; ++i) {
        ll temp2 = s[i];
        s[i] = temp;
        temp = temp2;
    }
    //cout << s << endl;
    return s;
}

int main() {
    scanf("%lld", &n);
    while(n--) {
        cin >> upper >> lower >> f;
        reverse(lower.begin(), lower.end());
        string s = upper + lower;

        bool flag = false;
        for(ll i = 0; i < 4; ++i) {
            s = rotateAmulet(s);
            if(piles.count(s)) {
                flag = 1;
                break;
            } 
        }

        if(!flag) {
        	piles.insert(s);
        	//cout << s << endl;
        }
    }

    printf("%lld\n", (ll)piles.size());
    return 0;
}