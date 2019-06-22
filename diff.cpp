#include <bits/stdc++.h>
#define MAXN 8800
#define INF 999999
using namespace std;

typedef struct{
	int add;
	int rem;
}PD;

string a;
string b;
PD pd[MAXN][MAXN];
int n, m;

PD solve(int i, int j, int n, int m){
	if(i > n){
		PD res;
		res.rem = 0;
		res.add = max(m-j+1,0);
		return res;
	}
	if(j > m){
		PD res;
		res.rem = max(n-i+1,0);
		res.add = 0;
		return res;
	}
	
	if(pd[i][j].add != -1) return pd[i][j];
	
	if(a[i] == b[j])
		return pd[i][j] = solve(i+1,j+1,n,m);
		
	
	PD remove = solve(i+1,j,n,m); remove.rem++; //remover caractere em A
	PD insere = solve(i,j+1,n,m); insere.add++; //adicionar caractere em A
	
	if(remove.add + remove.rem < insere.add + insere.rem){
		return pd[i][j] = remove;
	}else{
		return pd[i][j] = insere;
	}	
}





int main(){
	int i,j;
	string ax;
	
	scanf("%d %d ", &n, &m);
	a = "!";
	b = "!";
	
	for(i = 1; i <= n; i++){
		getline(cin,ax);
		a += ax;
		if(i != n) a += "!";
	}
	
	for(i = 1; i <= m; i++){
		getline(cin,ax);
		b += ax;
		if(i != m) b += "!";
	}
	
	n = (int) a.size();
	m = (int) b.size();

	for(i = 0; i <= n+1; i++){
		for(j = 0; j <= m+1; j++){
			pd[i][j].add = -1;
		}
	}
	
	PD res = solve(1,1,n,m);
	cout << res.add << " " << res.rem << endl;
	
}



