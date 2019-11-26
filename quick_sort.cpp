#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

using namespace std;

void Quick(int vetor[], int inicio, int fim);
int main(){

	int vetor[1000000];
	int n = 1000000;
	srand(time(NULL));
	for(int i = 0; i < n; i++){
        vetor[i] = rand() % 1000000;
	}

    cout << "Vetor desordenado:\n";
	for(int i = 0; i < n; i++){
		cout << vetor[i] << " - ";
	}

	Quick(vetor, 0, n-1);

	cout << "Vetor ordenado:\n";
	for(int i = 0; i < n; i++){
		cout << vetor[i] << " - ";
	}
}

void Quick(int vetor[], int inicio, int fim){

	int pivo, aux, i, j, meio;

	i = inicio;
	j = fim;

	meio = (int) ((i + j) / 2);
	pivo = vetor[meio]; /*define o pivo */

	do{
		while (vetor[i] < pivo) i = i + 1;
		while (vetor[j] > pivo) j = j - 1;
    /*mudar (vetor[i] < pivo) e (vetor[j] > pivo) para (vetor[i] > pivo) e (vetor[j] < pivo) muda de crescente para decrescente*/
		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i = i + 1;
			j = j - 1;
		}
	}while(j > i);

	if(inicio < j) Quick(vetor, inicio, j);
	if(i < fim) Quick(vetor, i, fim);

}
