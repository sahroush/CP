#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =1e5+5;
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

int n , k ;
int p[maxn] , dp[maxn] , pd[maxn];
int mark[3100][3100] , dist[3100][3100];
queue < pii > q;
int ans = 0;


int main(){
    migmig
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i ++){
        cin >> p[i];
    }
    for (int i = n ; i > 0 ; i --){
        if(i!=n){
            dp[i] = dp[i + 1];
            pd[i] = pd[i + 1];
        }
        if(p[i] == 100) pd[i]++;
        if(p[i]!=0) dp[i]++;
    }
    q.push(pii(1 , 2));
    mark[1][2] = 1;
    dist[1][2] = 1;
    while(!q.empty()){
        pii v = q.front();
        q.pop();
        if(v.first > n or v.second > n or dist[v.first][v.second] > k){
            continue;
        }
        int f = v.first , s = v.second;
        if(p[f] > 0 and !mark[f][s+1] and pd[s]==0){
            dist[f][s+1]=dist[f][s]+1;
            mark[f][s+1]=1;
            q.push(pii(f , s+1));
            ans++;
        }
        if(p[f] > 0 and dp[s] > 0 and !mark[s + 1][s + 2]){
            dist[s+1][s+2]=dist[f][s]+1;
            mark[s+1][s+2]=1;
            q.push(pii(s+1 , s+2));
            ans++;
        }
        if(p[f]<100 and dp[s]>0 and !mark[s][s+1]){
            dist[s][s+1]=dist[f][s]+1;
            mark[s][s+1]=1;
            q.push(pii(s , s+1));
            ans++;
        }
    }
    dokme(ans+1)
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.