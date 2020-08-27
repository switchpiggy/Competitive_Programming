#include <bits/stdc++.h>

using namespace std;

#define s(n) scanf("%d", &n)

int main() {

    int t, n;

	s(t);
    

    while(t--) {

        int res = 0;

        s(n);

        set<int> a;
        
        for(int i = 0; i < n; ++i) {

            int c;

            s(c);

            a.insert(c);

        }

        while(!a.empty()) {

            int m = *a.rbegin();

            a.erase(m);

            if(m%2 == 0) {

                a.insert(m/2);

                res++;

            }

        }

        printf("%d\n", res);



    }

    return 0;

}