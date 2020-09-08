#include <stdlib.h>
#include "structs.h"
#include "heap.h"

/*
-----------------------------------------------------------
Função que determina se a chave3 k1 é maior que a chave3 k2
-----------------------------------------------------------
*/
int MaiorChave3(chave3 k1, chave3 k2)

{
return (k1>k2)?1:0 ;
}


/*
------------------------------------------------------
Função que troca dois nós notabsim (troca no1 com no2)
------------------------------------------------------
*/
void TrocaNoTabSim(notabsim *no1, notabsim *no2)

{
/* Uma vez que não se vai eliminar o nó basta trocar os campos */
chave3 ch=no2->cor ;
int i=no2->num ;

no2->cor=no1->cor ;
no2->num=no1->num ;

no1->cor=ch ;
no1->num=i ;
}


/*
------------------------------------------------------------------------
Função que ordena uma lista de notabsim usando o algoritmo SelectionSort
------------------------------------------------------------------------
*/
void SelectionSort(notabsim *prim)

{
notabsim *no1=prim, *no2 ;

if(no1 != NULL){
	while(no1 != NULL ){
		no2=no1->prox ;
		while(no2 != NULL){
			if(MaiorChave3(key3(no1), key3(no2)))
				TrocaNoTabSim(no1, no2) ;
		no2=no2->prox ;
		} ;
	no1=no1->prox ;
	} ;
} ;
}


/*
-------------------------------------------------------------------------
Função que ordena uma tabela de simbolos usando o algoritmo SelectionSort
-------------------------------------------------------------------------
*/
void OrdenaTabSim(tabsim *st)

{
int i ;

for(i=0; i<NUM_CORES; i++)
	SelectionSort(st->tab[i]) ;
}

