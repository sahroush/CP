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

int n , m , k;
int   a[maxn] , c[maxn];
pii b[maxn];
int srt[maxn];

bool cmp(int i ,int j){
    return(a[i] >= a[j]);
}

int main(){
    migmig
    int cnt = 0;
    cin >> n >> m >> k;
    for (int i = 0 ; i < n ; i ++){
        int inp;
        cin >> a[i];
    }
    for (int i = 0 ; i < m ; i ++){
        cin >> b[i].first;
        b[i].second = i;
        srt[i] = i;
    }
    sort(b , b + m);
    sort(a , a + n );
    /*
    int l = 0 , r = m + 1;
    while(r - l > 1){
        int mid = (l + r)/2;
        if(chk(mid)){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    l--;
    if(!chk(l)){
        dokme(-1);
    }
    cout << l << endl;
    for (int i = 0 ; i  < l ; i ++){
        cout << srt[i] << ' ';
    }
    */
    cnt = n - 1;
    for (int i = 2*pw(10 , 6) - 1 ; i >= 0 ; i --){
        while(cnt >= 0 and a[cnt]>= i and c[i] < k){
            c[i]++;
            cnt--;
        }
    }
    if(cnt!=-1){
        dokme(-1)
    }
    cnt = 0;
    int ans = 0;
    for (int i = 0 ; i < 2*pw(10 , 6) ; i ++){
        while(cnt < m and b[cnt].first < i ) cnt++;
        while(cnt < m and b[cnt].first >= i and c[i] < k){
            c[i]++;
            cnt++;
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 1 ; i <= ans ; i ++ ){
        cout << b[m - i].second + 1 << ' ';
    }




    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
