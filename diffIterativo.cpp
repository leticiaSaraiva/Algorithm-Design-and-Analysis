#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int add, rem;
} programa;

programa diff(string A, string B){
    int n = A.size();
    int m = B.size();
    programa PD[n + 1][m + 1];

    for(int i = n; i >= 0 ; i--){
        programa d;
        d.add = 0;
        d.rem = n - i;
        PD[i][m] = d;
    }

    for(int j = m; j >= 0; j--){
        programa d;
        d.add = m - j;
        d.rem = 0;
        PD[n][j] = d;
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(A[i] == B[j]) 
                PD[i][j] = PD[i + 1][j + 1];
            else{
                programa remover = PD[i + 1][j];
                remover.rem++;
                programa adicionar = PD[i][j + 1]; 
                adicionar.add++;
                int rem = remover.rem + remover.add;
                int add = adicionar.rem + adicionar.add;
                PD[i][j] = rem < add ? remover : adicionar;
            }
        }
    }
    return PD[0][0];
}

int main(){
	string A;
	string B;
	int i;
	string ax;
	int n, m;
	
	scanf("%d %d ", &n, &m);
	A = "!";
	B = "!";
	
	for(i = 1; i <= n; i++){
		getline(cin,ax);
		A += ax;
		if(i != n) A += "!";
	}
	
	for(i = 1; i <= m; i++){
		getline(cin,ax);
		B += ax;
		if(i != m) B += "!";
	}
	
	n = (int) A.size();
	m = (int) B.size();
	
	programa res = diff(A,B);
	cout << res.add << " " << res.rem << endl;
	
}
