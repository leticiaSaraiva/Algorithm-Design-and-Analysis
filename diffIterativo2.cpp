#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int add, rem;
} mudancas;

mudancas diff(string A, string B){
    int n = A.size();
    int m = B.size();
    mudancas PD[n + 1][m + 1];

    for(int i = n; i >= 0 ; i--){
        mudancas d;
        d.add = 0;
        d.rem = n - i;
        PD[i][m] = d;
    }

    for(int j = m; j >= 0; j--){
        mudancas d;
        d.add = m - j;
        d.rem = 0;
        PD[n][j] = d;
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(A[i] == B[j]) 
                PD[i][j] = PD[i + 1][j + 1];
            else{
                mudancas remover = PD[i + 1][j];
                remover.rem++;
                mudancas adicionar = PD[i][j + 1]; 
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
    int i, j;
    cin >> i >> j;
    string A, B, C;
    getline(cin, C);
    //substituir as quebras de linha por um caractere, transformando o texto em uma string
    getline(cin, A);
    i--;
    while(i){
        i--;
        getline(cin, C);
        A += '!';
        A += C;
    }

    getline(cin, B);
    j--;
    while(j){
        j--;
        getline(cin, C);
        B += '!';
        B += C;
    }

    mudancas resp = diff(A, B);
    cout << resp.add << " " << resp.rem << endl;
}
