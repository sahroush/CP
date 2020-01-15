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

string s[20];
int n , m ;
bitset < 20 > bit;
int maxl[20] , maxr[20];
int h = 0;

int chk(){
    int cnt = 0 , room = 0;
    for (int i = 0  ; i < h ; i ++){
        if(room == 0 and maxr[i]){
            room = maxr[i];
            cnt+=room;
        }
        if(room == m + 1 and maxl[i]){
            room = (m + 1 ) - maxl[i];
            cnt+=maxl[i];
        }
        if(i == h - 1){
            continue;
        }
        if(bit[i]){
            cnt+=(m + 1) - room;
            room = m + 1;
        }
        else{
            cnt+=room;
            room = 0;
        }
    }
    return(cnt);
}

int main(){
    migmig
    cin >> n >> m;
    int ans = 1e5;
    int cnt = 0;
    for (int i = n - 1 ; i >= 0;  i --){
        cin >> s[i];
        for (int j = 1 ; j <= m ; j ++){
            if(s[i][j] == '1'){
                maxr[i] = j;
            }
        }
        maxl[i] = 0;
        for (int j = m ; j >= 1 ; j --){
            if(s[i][j] == '1'){
                maxl[i] = j;
            }
        }
        if(maxl[i]!=0)maxl[i] = (m + 1) - maxl[i];
        if(maxr[i]!=0 and h == 0){
            h = i + 1;
        }
        if(maxr[i] == 0){
            cnt++;
        }
    }
    for (int i = 0 ; i < pw(2 , n) ; i ++){
        bit = i;
        ans = min(ans , chk());
    }
    h--;
    h= max(h , 0);
    cout << ans + h;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
