#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ll maxn = 1e5+100;
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

int n , k ;
string  s[2];
bool mark[2][maxn];
queue <pair < int , pair < bool , int > > > q;

int main (){
    migmig
    cin >> n >> k;
    cin >> s[0] >> s[1];
    q.push(make_pair( 0 , make_pair( 0 , 0)));
    mark[0][0] = 1;
    while(!q.empty()){
        pair < int , pair < bool , int > > v = q.front();
        q.pop();
        int a , c;
        bool b;
        a = v.first;        //current water level
        b = v.second.first; //side
        c = v.second.second;//our level right now
        if (c>=n){
            dokme("YES");
        }
        if (!mark[!b][c + k] and s[!b][c+k]!='X'){
            mark[!b][c+k] = 1;
            q.push(make_pair(a+1 , make_pair(!b , c+k)));
        }
        if(c-1 >= 0) if (!mark[b][c -1] and c-1 > 1 and c-1 >= a+1 and s[b][c-1]!='X'){
            mark[b][c-1] = 1;
            q.push(make_pair(a+1 , make_pair(b , c-1)));
        }
        if (!mark[b][c+1] and s[b][c+1]!='X'){
            mark[b][c+1] = 1;
            q.push(make_pair(a+1 , make_pair(b , c+1)));
        }
    }
    cout << "NO";
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you wiint come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.