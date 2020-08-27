#include <iostream>
 
using namespace std;
 
int main()
{
    long long  t, a, b;
 
    cin >> t;
 
    while(t--){
        cin >> a >> b;
 
        long long total = 0;
 
        for(long long x = 10; x - 1 <= b; x *= 10, total += a);
 
        cout << total << endl;
    }
 
 
    return 0;
}