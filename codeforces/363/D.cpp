#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll maxn = 1e5+100;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;
const ll INF = 1000100000;
 
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
 
ll n,m,a, ans  = 0 , ans1 = 0 , b[maxn] , p[maxn];
 
bool cmp(ll a, ll b){
	return a>b;
}
 
int main(){
    cin >> n >> m >> a;
 
    for(int i = 0 ; i <  n; i ++) cin >> b[i];
    for(int i = 0 ;i < m ; i ++ ) cin >> p[i];
    sort(b,b+n,cmp);
    sort(p,p+m);
    int l = 0,r= min(n,m);
    while(l<=r){
        int mid = (l+r)/2;
        ll mr = 0 , sum = 0 ;
        int boz = mid-1;
        for(int i = 0 ; i<mid ; i++){
            if(b[i]<p[boz]) mr+=p[boz]-b[i];
            sum+=p[i];
            boz--;
        }
        if(mr<=a){
            l = mid+1;
            ans = mid;
            ans1 = max(ZERO,sum-a);
        }
		else r = mid-1;
    }
    cout<< ans << '\t' << ans1 ;
    
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
