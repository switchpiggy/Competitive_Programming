#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string s;

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        cin >> s;

        bool flag = false, flag1 = false;

        for(ll i = 0; i < n - 1; ++i) {
            if(s[i] == '1' && s[i + 1] == '0') flag = 1;
            if(s[i] == '0' && s[i + 1] == '1') flag1 = 1;
        }

        if(!flag) {
            cout << s << endl;
            continue;
        } else if(!flag1) {
        	printf("0\n");
        	continue;
        }

        ll i = n - 1, j = 0;
        for(i = n - 1; i >= 0; --i) {
            if(s[i] != '1') break; 
        }
        
        for(j = 0; j < n; ++j) {
            if(s[j] != '0') break;
        }

        i = n - 1 - i;
        j++;
        
        while(j--) printf("0");
        while(i--) printf("1");
        printf("\n");
    }

    return 0;
}