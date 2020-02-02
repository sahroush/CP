#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6+5;
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

int q;
string s[200];
int r , c , k;
int cnt = 0;

int main(){
    migmig
    cin >> q;
    while(q--){
        cin >> r >> c >> k;
        cnt= 0;
        for (int i = 0 ; i < r ; i ++){
            cin >> s[i];
            for (int j = 0 ; j < c ; j ++ ){
                if(s[i][j] == 'R'){
                    cnt++;
                }
            }
        }
        int each = cnt/k;
        int rmn = cnt - each*k;
        pair < char , int > ans[62] = {
                make_pair( 'a', 0),{ 'b', 0},{ 'c', 0},{ 'd', 0},{ 'e', 0},{ 'f', 0},{ 'g', 0},
                { 'h', 0},
                { 'i', 0},
                { 'j', 0},
                { 'k', 0},
                { 'l', 0},
                { 'm', 0},
                { 'n', 0},
                { 'o', 0},
                { 'p', 0},
                { 'q', 0},
                { 'r', 0},
                { 's', 0},
                { 't', 0},
                { 'u', 0},
                { 'v', 0},
                { 'w', 0},
                { 'x', 0},
                { 'y', 0},
                { 'z', 0},
                { 'A', 0},
                { 'B', 0},
                { 'C', 0},
                { 'D', 0},
                { 'E', 0},
                { 'F', 0},
                { 'G', 0},
                { 'H', 0},
                { 'I', 0},
                { 'J', 0},
                { 'K', 0},
                { 'L', 0},
                { 'M', 0},
                { 'N', 0},
                { 'O', 0},
                { 'P', 0},
                { 'Q', 0},
                { 'R', 0},
                { 'S', 0},
                { 'T', 0},
                { 'U', 0},
                { 'V', 0},
                { 'W', 0},
                { 'X', 0},
                { 'Y', 0},
                { 'Z', 0},
                { '0', 0},
                { '1', 0},
                { '2', 0},
                { '3', 0},
                { '4', 0},
                { '5', 0},
                { '6', 0},
                { '7', 0},
                { '8', 0},
                { '9', 0}
            };
            for (int i = 0 ; i < k ; i ++){
                ans[i].second = each;
                if(rmn){
                    rmn--;
                    ans[i].second++;
                }
            }
            pii cur = {0 , 0};
            int pos = 0;
            int dir = 1;
            char ns[200][200];
            while(cur.second < r){
                if(cur.first == c){
                    cur.first = c-1;
                    cur.second++;
                    dir*=-1;
                    //cout << endl;
                }
                if(cur.first == -1){
                    //cur.first = c;
                    cur.first = 0;
                    cur.second++;
                    dir*=-1;
                    //cout << endl;
                }
                if(cur.second == r){
                    break;
                }
                ns[cur.first][cur.second] = (char)ans[pos].first;
                //cout << ns[cur.first][cur.second];
                //cout << cur.first  << ' '<< cur.second << endl;
                if(s[cur.second][cur.first] == 'R'){
                    ans[pos].second--;
                }
                if(ans[pos].second == 0){
                    pos++;
                    if(ans[pos].second == 0){
                        pos--;
                    }
                }
                cur.first+=dir;
            }
            for (int i = 0 ; i < r; i ++){
                for (int j = 0 ; j < c ; j ++){
                    cout << ns[j][i];
                }
                cout << endl;
            }
    }

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
