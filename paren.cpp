#include <bits/stdc++.h>
#define MAXN 3000
#define INF 999999

using namespace std;

int PD[MAXN][MAXN];
string P;

int parentizacao(int i, int n, int parenAberto){
	if(i > n){
		if(parenAberto == 0){
			return 0;
		}else{
			return INF;
		}
	}
	if(parenAberto < 0){
		return INF;
	}
	if(PD[i][parenAberto] != -1){
		return PD[i][parenAberto];
	}
	if(P[i] == '('){
		PD[i][parenAberto] = min(1+parentizacao(i+1, n, parenAberto-1), parentizacao(i+1, n, parenAberto+1));
		return PD[i][parenAberto];
	}else{
		PD[i][parenAberto] = min(1+parentizacao(i+1, n, parenAberto+1), parentizacao(i+1, n, parenAberto-1));
		return PD[i][parenAberto];
	}
}

int main(){
		
	cin >> P;
	
	for(int i=0; i<(int)P.length()+20; i++){
		for(int j=0; j<(int)P.length()+20; j++){
			PD[i][j] = -1;
		}
	}
	
	int result = parentizacao(0, P.length()-1, 0);
	
	cout << result;
}
