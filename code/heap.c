#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "lststrops.h"

/*
-----------------------------------------------------------
Função que determina se a chave1 k1 é maior que a chave1 k2
-----------------------------------------------------------
*/
int maior(chave1 k1, chave1 k2)

{
int a=0 ;

if(strcmp(k1, k2) > 0)
	a=1 ;

return a ;
}


/*
--------------------------------------------------------
Função que troca a chave1 k1 e a chave1 k2 no lststr lst
--------------------------------------------------------
*/
void troca(nostr *ptr1, nostr *ptr2)

{
chave1 aux1 ;
if(ptr1 != NULL && ptr2 != NULL){
	aux1=ptr1->ch ;
	ptr1->ch=ptr2->ch ;
	ptr2->ch=aux1 ; 
} ;
}


/*
--------------------------------------------------------------
Função que devolve um apontador para o i-ésimo elemento de lst
--------------------------------------------------------------
*/
nostr *Posiciona(lststr *lst, int i)

{
nostr *ptr=lst->prim ;
int p=1 ;

while(p<i){
	ptr=ptr->prox ;
	p++ ;
} ;
return ptr ;
}


/*
----------------------------------------------
Função que cria uma heap a partir de um lststr
----------------------------------------------
*/
void FixDown(lststr *lst, int ind, int dim)

{
int i=ind, m, j=2*ind ;
nostr *aux1, *aux2 ;

while(j <= dim){
	m=0 ;
	if((j+1) <= dim){
		aux1=Posiciona(lst, j+1) ;
		aux2=Posiciona(lst, j) ;
		m=maior(aux1->ch, aux2->ch) ;
		if(m == 1)
			aux2=aux1 ;
	}	
	else
		aux2=Posiciona(lst, j) ;
	aux1=Posiciona(lst, i) ;	
	if(maior(aux2->ch, aux1->ch))
		troca(aux1, aux2) ;
	i=j+m ;
	j=2*i ;
} ;
}


/*
----------------------------------------------
Função que cria uma heap a partir de um lststr
----------------------------------------------
*/
void Heapify(lststr *lst)

{
int N=lst->num ;
int i=N/2 ;

while(i > 0)
	FixDown(lst, i--, N) ;
}


/*
------------------------------------------------------------------------
Função que ordena uma lista de chaves chave1 usando o algoritmo heapsort
------------------------------------------------------------------------
*/
void Heapsort(lststr *lst, int N)

{
int t=N ;
nostr *aux2=Posiciona(lst, N) ;

while(t > 1){
	troca(lst->prim, aux2) ;	
	FixDown(lst, 1, --t) ;
	aux2=aux2->ant ;
} ;
}


/*
--------------------------------------------
Função que ordena uma lista de chaves chave1
--------------------------------------------
*/
void OrdenaLinEliminadas(lststr *lst)

{
Heapify(lst) ;
Heapsort(lst, lst->num) ;
}
