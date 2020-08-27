#include <cstdio>
int main() {
    int n,i;scanf("%d",&n);
    for (i=n;i;i--)if(!(n%i))printf("%d ",n=i);
}