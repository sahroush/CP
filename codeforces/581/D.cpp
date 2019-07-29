#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);



int main(){
	int x1;
	int x2;
	int x3;
	int y1;
	int y2;
	int y3;
	cin >> x1 >> y1;
	cin  >> x2 >> y2;
	cin >> x3 >> y3;
	int s1=x1*y1, s2=x2*y2,s3=x3*y3;
	if (sqrt((s1+s2+s3)) * sqrt((s1+s2+s3)) != (s1+s2+s3)){
		cout << -1;
		return(0);
	}
	int l[6]={x1,x2,x3,y1,y2,y3};
	sort (l,l+6);
	int cm=l[5];
	int q,r;
	string s[cm];
	int a=x1;
	int b=y1;
	int c=x2;
	int d=y2;
	int x=x3;
	int y=y3;
	/*
	#include <iostream>
using namespace std;
const int INF = 1000002;
bool f[INF];
int ok[80000],out[10000];
int n, sum, ans;
void sift (int n) {
    for (int i = 2; i <= n; i++) {
        if (!f[i]) {
            ok[++sum] = i;
            for (int j = i + i; j <= n; j += i)    f[j] = 1;
        }
    }
}
int main() {
    cin >> n;
    sift (n);
    for (int i = 1; i < sum; i++)
        if (!f[ok[i] + 2])        out[++ans]=ok[i];
�
    cout << ans << endl;
    for(int i=1;i<=ans;i++)
        cout<<2<<' '<<out[i]<<endl;
}
�
�*/
	
	int cnt=0;
	int flag=0;
	if (b < a)	swap(a, b);
		if (d < c)	swap(c,d);
		if (x > y)	swap(x,y);
		flag = max(b, max(d, y));
		cnt = flag;
		if (b == d && d == y && b == flag){
			if (a + c + x == flag){
				cout << cnt << endl;
				for (int i = 0; i < a; ++i){
					for (int j = 0; j < flag; ++j)	cout << "A";
					cout << '\n';
				}
				for (int i = 0; i < c; ++i){
					for (int j = 0; j < flag; ++j)	cout << "B";
					cout << '\n';
				}
				for (int i = 0; i < x; ++i){
					for (int j = 0; j < flag; ++j)	cout << "C";
					cout << '\n';
				}
			}
			else	cout << -1;
		}
		else {
			if (b == flag){
				flag -= a;
				if (c != flag)	swap(c, d);
				if (x != flag)	swap(x,y);
				if (c == x && c == flag && d + y == cnt){
					cout << cnt << endl;
					for (int i = 0; i < a; ++i){
						for (int j = 0; j < cnt; ++j)	cout << "A";
						cout << '\n';
					}
					for (int i = 0; i < flag; ++i){
						for (int j = 0; j < d; ++j)	cout << "B";
						for (int j = 0; j < y; ++j)	cout << "C";
						cout << '\n';
					}
				}
				else	cout << -1;
			}
			else if (d == flag){
				flag -= c;
				if (a != flag)	swap(a, b);
				if (x != flag)	swap(x,y);
				if (a == x && a == flag && b + y == cnt){
					cout << cnt << endl;
					for (int i = 0; i < c; ++i){
						for (int j = 0; j < cnt; ++j)	cout << "B";
						cout << '\n';
					}
					for (int i = 0; i < flag; ++i){
						for (int j = 0; j < b; ++j)	cout << "A";
						for (int j = 0; j < y; ++j)	cout << "C";
						cout << '\n';
					}
				}
				else	cout << -1;
			}
			else if (y == flag){
				flag -= x;
				if (c != flag)	swap(c, d);
				if (a != flag)	swap(a,b);
				if (c == a && c == flag && d + b == cnt){
					cout << cnt << endl;
					for (int i = 0; i < x; ++i){
						for (int j = 0; j < cnt; ++j)	cout << "C";
						cout << '\n';
					}
					for (int i = 0; i < flag; ++i){
						for (int j = 0; j < b; ++j)	cout << "A";
						for (int j = 0; j < d; ++j)	cout << "B";
						cout << '\n';
					}
				}
				else	cout << -1;
			}
		}
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
