#include <bits/stdc++.h>
#define MAXN 3000
#define INF 999999

using namespace std;

int PD[MAXN][MAXN];
string P;

int parentizacao_iterativo(int n){
	//Primeiro resolvemos os casos bases.
	//Para esse problema os primeiros casos bases são quando i passa de n.
	//Só precisamos tratar o caso n + 1, pq o único caso de precisar o n + 2
	//seria uma chamada do n + 1, mas não ocorre.
	PD[n + 1][0] = 0; //Para o caso de não haver parêntesis aberto o resultado é zero.
	for (int j = 1; j <= n + 1; j++){
		PD[n + 1][j] = INF; //Infinito para qualquer outro caso.
	}
	//O caso de parêntesis abertos negativos será tratados depois, porque não existe
	//posição negativa na matriz.

	//Nas chamadas recursivas sempre é para i + 1, então o for deve ser decrescente.
	for (int i = n; i >= 0; i--){
		//Trataremos em um caso separado quando não tiver nenhum parêntesis aberto,
		//pois não será possível subtrair.
		if (P[i] == '('){
			PD[i][0] = PD[i + 1][1]; //Só existe a opção de manter o parêntese aberto.
		}
		else{
			PD[i][0] = 1 + PD[i + 1][1]; //Só existe a opção de trocar o parêntese fechando por um abrindo.
		}

		//O número de parêntesis pode ser maior ou menor na chamada recursiva,
		//então tanto faz a ordem do for.
		for (int parenAberto = 1; parenAberto <= n; parenAberto++){
			//Aqui dentro será igual a função;
			if(P[i] == '('){
				PD[i][parenAberto] = min(1 + PD[i + 1][parenAberto - 1], PD[i + 1][parenAberto + 1]);
			}
			else{
				PD[i][parenAberto] = min(1 + PD[i + 1][parenAberto + 1], PD[i + 1][parenAberto - 1]);
			}
		}
	}
	//O retorno é igual a chamada externa.
	return PD[0][0];
}

int main(){
		
	cin >> P;
	int result = parentizacao_iterativo(P.length() - 1);
	
	cout << result;
}
