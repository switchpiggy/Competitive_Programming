#include<cstdio>
#include<bitset>
const int N = 1010;
int n , x , a[N] , st[N] , cnt[N];
std::bitset<N> can;
bool fl[N];
 
int main(){
    scanf( "%d%d" , &n , &x );
    for(int i=1 ; i<=n ; i++) scanf( "%d" , &a[i] );
    for(int i=1 ; i<=n ; i++) fl[ a[i] ] = true;
    int sz=0;
    for(int i=0 ; i<=n ; i++)
        if( !fl[ i ] ){
            int cur = i;
            while( cur ){
                st[cur] = sz;
                cur = a[cur];
                cnt[sz]++;
            }
            sz++;
        }
    int af=0 , x1=x;
    while( x1 ){
        af++;
        x1 = a[x1];
    }
    af;
    can[af] = true;
    for(int i=0 ; i<sz ; i++){
        if( i != st[x] ) can |= can<<cnt[i];
    }
    for(int i=0 ; i<=n ; i++) if( can[i] ) printf("%d\n" , i);
}