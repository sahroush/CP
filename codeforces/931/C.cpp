#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;//AmShZ
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);
}

ll n , a[maxn] , sum;

int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n; i ++){
        cin >> a[i];
        sum+=a[i];
    }
    if(*max_element(a , a+n) - *min_element(a , a + n) <= 1){
        cout << n << endl;
        for(int i =0  ; i < n ; i ++){
            cout << a[i] << ' ';
        }
        return(0);
    }
    ll mx = *max_element(a , a+n);
    ll mn = mx-2;
    int cntmn = 0  , cntmid = 0 , cntmx = 0;
    for(int i = 0;  i < n ; i ++){
        if(a[i] == mn){
            cntmn++;
        }
        else if(a[i] == mx){
            cntmx++;
        }
        else{
            cntmid++;
        }
    }
    sort(a , a + n);
    if(min(cntmn , cntmx) > cntmid/2){
        int ans = n;
        for(int i = 0 , j = n-1 ; i < min(cntmn , cntmx); i ++ , j -- ){
            a[i]++;
            a[j]--;
            ans-=2;
        }
        cout << ans << endl;
        for(int i =0  ; i < n ; i ++){
            cout << a[i] << ' ';
        }
        return(0);
    }
    int ans = n;
    for(int i = 0 ; i < n-1; i ++){
        if(a[i] == a[i + 1] and a[i] == mn+1){
            a[i]--;
            a[i+1]++;
            ans-=2;
            ++i;
        }
    }
    cout << ans << endl;
    for(int i =0  ; i < n ; i ++){
        cout << a[i] << ' ';
    }
    return(0);
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
