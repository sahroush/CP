#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , k;
int t[maxn];
int r[maxn];
vector < int > vec;

int main(){
    migmig
    //lets write it 1 indexed and more clean with less cases.
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1 ; i <= n ; i ++){
        cin >> t[i];
        if(t[i] < 0){
            cnt++;
        }
    }
    if( cnt == 0){
        dokme(0)
    }
    if(n<=k){
        dokme(1)
    }
    if(cnt > k){
        dokme(-1)
    }
    k -= cnt;
    /*
    //for each pos save when is the next -1 temp
    r[n] = 1e9;
    for (int i = n-1 ; i >= 0 ; i --){
        r[i] = r[i + 1];
        if(t[i] < 0 and r[i] > 1e6){
            r[i] = 1;
        }
        else if(t[i] < 0){
            r[i]++;
        }
    }
    for (int i = 0 ; i < n ; i ++){
        r[i]--;
    }
    */
    int pos = 1;
    while(t[pos]>= 0 and pos <= n ){
        pos++;
    }
    cnt = 0;
    int ans = 2;
    for (int i = pos  + 1; i <= n ; i ++){
        if(t[i] < 0 ){
            vec.pb(cnt);
            cnt = 0;
            ans+=2;
        }
        else{
            cnt++;
        }
    }
    pos = n;
	while(t[pos] >= 0){
        pos --;
    }
    //cout << pos;
    //cout << ans;
	sort(vec.begin() , vec.end());
    for(int i = 0 ; i < vec.size() ; i ++){
        if(vec[i] <= k){
            k-=vec[i];
            ans-=2;
        }
        else{
            break;
        }
    }
    if(k>= n - pos){
        ans--;
    }
	cout << ans;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.