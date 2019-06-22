#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int seq[MAXN];
int pd[MAXN];
int n;
int res;

bool sig(int a, int b){
	if(a < 0 && b > 0) return true;
	if(a > 0 && b < 0) return true;
	return false;
}
void msc(){
	pd[n] = 0;
		
	int maior;
	int i, j;
	
	for(j=n-1; j>=0; j--){
		maior = 0;
		for(i = j+1; i <= n; i++){
			if(sig(seq[j],seq[i]) && abs(seq[j]) < abs(seq[i]) ){
				maior = max(maior, pd[i]);
			}
		}
		pd[j] = maior + 1;
		res = max(res,pd[j]);
	}
	
}
int main (){
	cin >> n;
	res = 0;
	int i;
	
	for(i = 0; i <= n+12; i++) pd[i] = -1;
	for(i = 0; i <= n-1; i++) cin >> seq[i];
	
	msc();
	cout << res << endl;
	
}
