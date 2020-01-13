#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =501;
const ll INF = 1e15;
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

string s[12];
pii st[] = {pii(0 , 1) , pii(1 , 0) , pii(1 , 1) , pii(-1 , 1) , pii(1 , -1)};
int x , y;
bool chk(int a , int b){
    int cnt = 0;
    for (int i = 0 ; i < 5 ; i ++){
        if(x > 10 or x < 1 or y < 1 or y > 10){
            return(0);
        }
        if(s[x][y] == 'O'){
            return(0);
        }
        if(s[x][y] == 'X'){
            cnt++;
        }
        x+=a , y+=b;
    }
    if(cnt>=4){
        return(1);
    }
    return(0);
}


int main(){
    migmig
    s[0] = "OOOOOOOOOOOO";
    for (int i = 1 ; i <= 10 ; i ++){
        cin >> s[i];
        s[i]+='O';
        s[i]='O' + s[i];
    }
    s[11] = "OOOOOOOOOOOO";
    for (int i = 1 ; i <= 10 ; i ++){
        for (int j = 1; j <= 10 ; j ++){
            for (int k = 0 ; k < 5; k ++){
                x = i , y = j;
                if(chk(st[k].first , st[k].second)){
                    dokme("YES");
                }
            }
        }
    }

    cout << "NO";
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
