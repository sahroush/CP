#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n;
string s;

int main(){
    migmig
    cin >> s;
    int f = 0 ;
    n = s.size();
    int cnt = 0;
    for (int i = 0 ; i < n ; i ++){
        if(s[i] == 'a' or s[i] == 'o' or s[i] == 'e' or s[i] == 'u' or s[i] == 'i'){
            cnt = 0 ;
            f = 0;

        }

        else{
            cnt++;
            if (s[i] == s[i-1] and i){
                f++;
                if (f==1){
                    f=2;
                }
            }

            //cout << cnt;

        }
        if (cnt >= 3 and f < cnt){
            cout << ' ';
            f = 0;
            cnt = 1;
        }
        //if (s[i] == 'l'){
            //cout << f;
        //}
        cout << s[i];
    }



    return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
