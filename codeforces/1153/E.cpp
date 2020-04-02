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
//#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int n;
int r[1001] , c[1001];
int cntodd = 0 ;
pii head , tail;
vector < int > vec[2];
vector < pii > ans;

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
        cout << "? " << i << ' ' << 1 << ' ' << i << ' ' << n << endl;
        cin >> r[i];
        r[i]%=2;
        if(r[i]){
            vec[0].pb(i);
        }
        cout << "? " << 1 << ' ' << i << ' ' << n << ' ' << i << endl;
        cin >> c[i];
        c[i]%=2;
        if(c[i]){
            vec[1].pb(i);
        }
        //cntodd+=r[i];
    }
    if(vec[0].size() and vec[1].size()){
        for(int i = 0 ; i < 2 ; i ++){
            for(int j = 0 ; j < 2 ; j ++){
                cout << "? " << vec[0][i] << ' ' << vec[1][j] << ' ' << vec[0][i] << endl << vec[1][j] << endl;
                int inp;
                cin >> inp;
                if(inp%2){
                    ans.pb(pii(vec[0][i] , vec[1][j]));
                }
            }
        }
    }
    /*
    if(cntodd == 1){
        cntodd++;
        r[n]++;
    }
    if(cntodd){
        solve1();
        cout << "! " << head.first << ' ' << head.second << ' ' << tail.first << ' ' << tail.second;
        return(0);
    }
    for(int i = 1 ; i < n ; i ++){
        cout << "? " << i << ' ' << i << ' ' << 1 << ' ' << n << endl;
        cin >> c[i];
        c[i]%=2;
        cntodd+=c[i];
    }
    if(cntodd==1){
        c[n]++;
        cntodd++;
    }
    solve2();
    cout << "! " << head.first << ' ' << head.second << ' ' << tail.first << ' ' << tail.second;
    */
    int f = 1;
    if(vec[1].size() == 0){
        f = 0;
    }
    int l = 0 ,  r= n;
    while(r - l > 1){
        int mid= (l + r)/2;
        cout << "? ";
        if(f){
            cout << 1 << ' ' << vec[1][0] << ' ' << mid << ' ' << vec[1][0] << endl;
        }
        else{
            cout << vec[0][0] << ' ' << 1 << ' ' << vec[0][0] << ' ' << mid << endl;
        }
        int inp;
        cin >> inp;
        if(inp%2){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    if(f){
        ans.pb(pii(r , vec[1][0]));
        ans.pb(pii(r , vec[1][1]));
    }
    else{
        ans.pb(pii(vec[0][0] , r));
        ans.pb(pii(vec[0][1] , r));
    }
    cout << "! ";
    for(int i = 0 ; i < 2 ; i ++){
        cout << ans[i].first << ' ' << ans[i].second << ' ';
    }
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
