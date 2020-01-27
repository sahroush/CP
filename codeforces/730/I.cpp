#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =8e5+5;
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

struct stu{
    int a ,b , id;
}s[maxn];

bool cmp(stu a , stu b){
    return(a.a > b.a);
}

int n , p , sp;
int dp[3100][3100];
int mark[maxn];
int mx = 0;
int pro[maxn] , spo[maxn];


int main(){
    migmig
    cin >> n >> p >> sp;
    for (int i = 1 ; i <= n ; i ++) cin >> s[i].a , pro[i] = s[i].a;
    for (int i = 1 ; i <= n ; i ++) cin >> s[i].b , spo[i] = s[i].b;
    for (int i = 1 ; i <= n ; i ++) s[i].id = i;
    sort(s + 1 , s + n  + 1, cmp);
    //dokme(s[1].a)
    for(int i = 1 ; i <= p; i  ++){
        dp[i][0] = dp[i - 1][0] + s[i].a;
        mark[s[i].id] = 1;
    }
    mx = dp[p][0];

    int pos = p, j = 0;
    while(sp--){
        while(mark[s[pos].id] and pos < n)pos++;
        int k = 0 , l = 0;
        for (int i = n  ; i > 0 ; i--){
            if(!mark[i]){
                j = spo[i];
            }
            else if(mark[i] == 2 or spo[i] + pro[s[pos].id] < pro[i]){
                j = 0;
            }
            else{
                j = spo[i] + pro[s[pos].id]-pro[i];
            }
            if(j > k){
                l = i , k = j;
            }
        }
        mx+=k;
        if(mark[l]){
            mark[s[pos].id] = 1;
        }
        mark[l] = 2;
    }
    cout << mx << endl;
    for (int i = 1 ; i <= n ; i ++)if(mark[i]==1)cout << i << ' ';
    cout << endl;
    for (int i = 1 ; i <= n ; i ++)if(mark[i]==2)cout << i << ' ';
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
