#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

string s[6];
int len[6];
vector < string > vec;
char ans[40][40];

bool chk(string s , int a , int b , int c){
    for (int i = 0 ; i < s.size() ; i ++){
        if(ans[a][b]!='.' and ans[a][b]!=s[i]){
            return(0);
        }
        ans[a][b] = s[i];
        a+=c;
        b+=!c;
    }
    return(1);
}

int main(){
    migmig
    for (int i = 0 ; i < 6 ; i ++){
        cin >> s[i];
    }
    sort(s , s + 6);
    vec.pb("~");
    for (int i = 0 ; i < 720 ; i ++){
        next_permutation(s , s + 6);
        if(s[0].size() + s[4].size()-1!=s[3].size() or s[1].size()+s[5].size()-1!=s[2].size()){
            continue;
        }
        ms(ans , '.');
        int tol = s[2].size() , arz = s[3].size();
        if(!chk(s[0],0,0,0))continue;
        if(!chk(s[1],0,0,1))continue;
        if(!chk(s[2],0,s[0].size()-1,1))continue;
        if(!chk(s[3],s[1].size()-1,0,0))continue;
        if(!chk(s[4],tol-1,s[0].size()-1,0))continue;
        if(!chk(s[5],s[1].size()-1,arz-1,1))continue;
        vector < string > mn;
        mn.clear();
        for (int i = 0 ; i < tol ; i ++){
            string st ="";
            for (int j = 0 ;j < arz ; j ++){
                st+=ans[i][j];
            }
            mn.pb(st);
        }
        vec = min(vec , mn);
    }
    if(vec[0] == "~"){
        dokme("Impossible")
    }
    for (auto i : vec){
        cout << i << endl;
    }


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
