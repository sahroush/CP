#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , q;
string s ;
char alp[26] = {'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' ,'t' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z'};

int main(){
    migmig;
    cin >> q;
    while (q--){
        bool f[26];
        pair <int , char> ans [1000];
        fill (f , f+26 , 0);
        cin >> s;
        n = s.size();
        string pos;
        int sz = 0;
        int i = 0;
        while (i < n){
            pos = s[i];
            int cnt = 1;

            while (i < n and s[i]==s[i+1] ){
                cnt++;
                i++;
            }

            ans[sz].first = cnt;
            ans[sz].second= s[i];

            sz++;
            i++;
        }
        for (int i = 0; i  < sz ; i ++){
            if (ans[i].first%2 == 1){
                f[ans[i].second - 'a'] = 1;

            }
        }

        for (int i = 0 ; i < 26 ; i ++){
            if (f[i]){
                cout << alp[i];
            }
        }
        cout << endl;

    }

    return(0);
}




//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
