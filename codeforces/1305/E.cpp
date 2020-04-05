#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6+100;//AmShZ
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define lowbit(x) ((x)&(-(x)))
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , k;
vector < ll > ans;

int main(){
    migmig
    cin >> n >> k;
    if(n <= 2){
        if(k == 0){
            if(n == 2){
                cout << 1 << ' ' << 2;
            }
            else{
                cout << n;
            }
            return(0);
        }
        dokme(-1);
    }
    ans.pb(1);
    ans.pb(2);
    int i = 3;
    while(1){
        if(ans.size() == n){
            break;
        }
        if(!k){
            int sz = ans.size();
            ll cur = 1e7;
            for(int j = sz ; j < n ; j ++){
                ans.pb(cur);
                cur+=i;
            }
            break;
        }
        ll boz = (i - 1)/2;
        if(k >= boz){
            k-=boz;
            ans.pb(i);
        }
        else{
            ll cnt = boz;
            for(int j = i + 1 ; ; j ++){
                if(cnt == k){
                    k = 0;
                    ans.pb(j);
                    i = j + 1;
                    break;
                }
                if(j%2==0){
                    cnt--;
                }
            }
        }
        i++;
    }
    if(k>0){
        dokme(-1);
    }
    for(int i : ans){
        cout << i << ' ';
    }




    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
