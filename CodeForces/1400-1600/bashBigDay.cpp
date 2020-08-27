#include <bits/stdc++.h>

using namespace std;

#define s(n) scanf("%d", &n);

int main() {

    int n;

    map<int, int> m;

    s(n)
;
    for(int i = 0; i < n; ++i) {

        int str; 

        s(str);

        for(int factor = 2; factor <= sqrt(str); ++factor) {

            if(str%factor == 0) m[factor]++;

            while(str%factor == 0) str /= factor;

        }

        if(str > 1) m[str]++;


    }

    int ans = 1;

    for(auto itr = m.begin(); itr != m.end(); ++itr) {

        ans = max(ans, (*itr).second);

    }
    
    cout << ans << endl;



    

}