#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll n , m  , a[maxn];
ll sum = 0 ;

bool chk(int x){
    ll cnt = 0 , p =0 , q = 0;
    for (int i = 0 ; i < n ; i  ++){
        cnt+=max(ZERO,a[i]-p);
        q++;
        if(q==x) p++,q=0;
    }
    return(cnt >= m);
}
bool cmp(int p , int q){
    return(p > q);
}

int main(){
    migmig
    cin >> n  >> m;
    for (int  i = 0 ; i < n ; i ++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a , a+ n, cmp);

    if (sum < m){
        dokme(-1);
    }
    if (sum == m){
        dokme(n);
    }
    ll l = 1 , r = n;
    ll ans =1e11;
    while (r - l > 1){
        ll mid = (l+r)/2;
        if (chk(mid)){
            r = mid;
            ans = min (ans , mid);
        }
        else{
            l=mid;
        }
    }
    if (chk(1)){
        dokme(1);
    }
    dokme(ans);
    return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
