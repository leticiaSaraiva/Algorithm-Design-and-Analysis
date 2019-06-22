#include <bits/stdc++.h>
#define MAXN 3300
#define INF -9999999

using namespace std;

string expr;
int PD[MAXN][MAXN];

int maiorValoracao(int n){
	int i, x, k, j, p, maior = 0, aux;
	for(i=0; i<n; i+=2){
		PD[i+1][i+1] = expr[i] -'0';
	}
	x=2;
	while(x<n){
		for(k=n-x; k>=1; k-=2){
			i = k;
			j = k+x;
			p = i+1;
			maior = INF;
			while(p < j){
				if(expr[p-1] == '+'){
					aux = PD[i][p-1] + PD[p+1][j];
				}else{
					aux = PD[i][p-1] * PD[p+1][j];
				}
				if(aux > maior){
					maior = aux;
				}
				p = p+2;
			}
			PD[i][j] = maior;
		}
		x = x+2;
	}
	return PD[1][n];
}

int main(){
	
	cin >> expr;
	
	cout << maiorValoracao((int)expr.length());
}


