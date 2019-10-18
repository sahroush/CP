#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 5e5;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int  n , a[maxn];
ll prt1[maxn] ,  prt2[maxn];
int main(){
    migmig
    cin >> n;
    for (int i =0  ; i < n ; i ++){
        cin >> a[i];
    }
    ll maxi=-1000000000;
	//cin>>n;
	ll val[n];
	//for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)val[i]=0;
	for(int i=n-2;i>=0;i--){
		val[i]=abs(a[i]-a[i+1]);
		// val[i]=max(val[i],val[i]-val[i-1]);
		if(i+2<n)
			val[i]=max(val[i],val[i]-abs(a[i+1]-a[i+2])+val[i+2]);
		else
			val[i]=max(val[i],val[i]-val[i-1]);
		// val[i]=max(val[i],0);
		maxi=max(maxi,val[i]);
	}
	cout<<maxi;

    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
