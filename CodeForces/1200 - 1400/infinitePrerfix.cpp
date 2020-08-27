#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, n, x;

    string s;
    
    cin >> t;

    while(t--) {

        cin >> n >> x;

        cin >> s;

        int bal = 0;

        int ans = 0;

        bool flag = false;

        int zeros = (int)count(s.begin(), s.end(), '0');

        int total = zeros - (n - zeros);

        for(int i = 0; i < n; ++i){

            if(total == 0) {

                if(bal == x) flag = true;

            } else if(abs(x - bal)%abs(total) == 0) {
            	
            	 if((x - bal)/total >= 0) ans++;
            	
            }

            if(s[i] - '0' == 1) bal--;

            else bal++;
        }

        if(flag) ans = -1;

        printf("%d\n", ans);

    }

}