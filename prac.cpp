#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll md(ll a,ll b)
{
  long long m=1000000007;
  ll res=1;
  while(b)
  {
    if(b&1)
    {
      res=(res*a)%m;
    }
    a=(a*a)%m;
    b=b>>1;
  }
return res;
}
ll power(ll a,ll b)
{
  ll res=1;
  while(b)
  {
    if(b&1)
    {
      res=res*a;
    }
    a=a<<1;
    b=b>>1;
  }
return res;
}
int main()

{
  ll n;
  cin>>n;
  ll q=power(6,n);
  ll p=pow(6,(n/2));
  //if odd
  if(n&1)
  {
    p*=6;
  }
  ll ans=md(p,q);
  cout<ans;

}
