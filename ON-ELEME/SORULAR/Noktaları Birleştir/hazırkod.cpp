#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;


int main() {
    long int t,n,ar[50],i;
    long double ans=0;
    cin>>t;
    while(t--)
        {
            cin>>n;
           for(i=0;i<n;i++)
               {
                   cin>>ar[i];
               }
          sort(ar,ar+n);
         ans=(long double)1/(n+1);
         long int tmp=n;
         for(i=1;i<n;i++)
             {
                 if(ar[i]==ar[i-1])
                 {
                     ans+=(long double)1/(tmp+1);
                 }
              else
                  {
                      tmp=n-i;
                    ans+=(long double)1/(tmp+1);
                  }
             }
         cout<<fixed<<setprecision(2)<<(n+1)*ans<<"\n";
        }
}
