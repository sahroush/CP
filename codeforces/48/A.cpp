#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int ,int > pii;

const ll maxn =2e5+10;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

string s[3];
bool f[3] , rps[3];


int main(){
    migmig
    cin >> s[0] >> s[1] >> s[2];
    f[0] = 1 , f[1] = 1 , f[2] = 1;
    for (int i = 0 ; i < 3 ; i ++){
        if (s[i] == "rock"){
            rps[0] = 1;
        }
        if (s[i] == "paper"){
            rps[1] = 1;
        }
        if (s[i] == "scissors"){
            rps[2] = 1;
        }
    }
    for (int i = 0 ; i < 3 ; i ++){
        if (s[i] == "rock" and rps[1]){
            f[i] = 0;
        }
        if (s[i] == "paper" and rps[2]){
            f[i] = 0;
        }
        if (s[i] == "scissors" and rps[0]){
            f[i] = 0;
        }
    }
    int cnt = 0;
    int pos;
    for (int i = 0;  i < 3 ; i ++){
        if(f[i]){
            cnt++;
            pos = i;
        }
    }
    if(cnt!=1){
        dokme('?');
    }
    char ans[3] = {'F' , 'M' , 'S'};
    dokme(ans[pos]);
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
