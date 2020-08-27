#include <bits/stdc++.h>

using namespace std;


int main() {

    int t;

    scanf("%d", &t);

    while(t--) {

        int a, b, r, c;

        scanf("%d %d %d %d", &a, &b, &c, &r);
        
        if(r <= 0) {
        	
        	cout << abs(b - a) << endl;
        	
        	continue;
        	
        }

        int l = max(min(a, b), c - r);
        
        int ri = min(max(a, b), c + r);
        
        if(c + r < min(a, b)) ri = l;
        
        if(c - r > max(a, b)) l = ri;
        

        cout << abs(b - a) - abs(ri - l)  << endl;


    }

}