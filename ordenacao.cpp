#include "ordenacao.hpp"

bool ordenado(int a[],  unsigned int t){
    for(int i=1; i<t; i++){
        if(a[i-1] >= a[i]) return false;
    }
    return true;
}

void selecao(int a[], unsigned int t){
    int min, aux;
    for(int i=0; i<t-1; i++){       // valor que será comparado 
        min = i;                    // considera i como o atual índice do menor valor
        for(int j=i+1; j<t; j++){   // varre todos os valores posteriores a a[i]
            if(a[j] < a[min]){      // se o valor em questão for menor que a[i]...
                min = j;            // ...então o mínimo passa a se encontrar neste índice j 
            }
            if(a[i] != a[min]){     // se a[i] for diferente do menor valor encontrado... 
                aux = a[i];         // o auxiliar recebe a[i]
                a[i] = a[min];      // o menor valor é deslocado para o índice i
                a[min] = aux;       // a[i] é deslocado para o índice onde estava o menor valor
            }
        }
    }
}


void insercao(int a[], unsigned int t){
    for(int i = 1; i<t; i++){
        int atual = a[i]; // valor atual a ser (ou não) reposicionado
        int j = i-1;

        // Deslocamento dos elementos entre a[0] e a[i-1] que são maiores o valor atual para uma posição à frente de sua posição atual
        while(j >= 0 && a[j] > aux){
            a[j+1] = a[j];
            j = j-1;
        }

        a[j+1] = aux; // inserção do auxiliar na posição correta
    }
}

void merge_sort(int a[], unsigned int t){
    int meio, primeiro, ultimo;
    primeiro = a[0];
    ultimo = a[t-1];
    if(primeiro < ultimo){
        meio = (primeiro+ultimo)/2;
        merge_sort(a, primeiro, meio);
        merge_sort(a, meio+1, ultimo);
        merge(a, primeiro, meio, meio+1, ultimo);
    }
}

void merge(int a[], int i1, int j1, int i2, int j2){
    int* aux = new int[((j1-i1) + (j2-i2) + 2)];
    int i, j, k;
    i = i1;
    j = i2;
    k = 0;
    while(i <= j1 && j <= j2){
        if(a[i] < a[j]){
            aux[k++] = a[i++];
        } else {
            aux[k++] = a[j++];
        }
    }
    while(i <= j1){
        aux[k++] = a[i++];
    }
    while(j <= j2){
        aux[k++] = a[j++];
    }
    for(i = i1; j = 0; i <= j2; i++; j++){
        a[i] = aux[j];
    }
    delete[] aux;
}