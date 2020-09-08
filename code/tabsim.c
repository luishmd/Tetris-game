#include <stdlib.h>
#include "structs.h"
#include "hash.h"

/*
--------------------------------------------
Função que inicializa uma tabela de simbolos
--------------------------------------------
*/
tabsim* InicTabSim()

{
tabsim *st=malloc(sizeof(tabsim)) ;
int i ;

st->comp=0 ;

for(i=0; i<NUMPECAS; i++){
	st->tab[i]=NULL ;
	st->ult[i]=NULL ;
} ;

return st ;
}


/*
-----------------------------------------
Função que destroi uma tabela de simbolos
-----------------------------------------
*/
void DestroiTabSim(tabsim *st)

{
int i ;
notabsim *aux1, *aux2 ;

for(i=0; i<NUMPECAS; i++){
	aux1=st->tab[i] ;
	if(aux1 != NULL){
		aux2=aux1->prox ;
		while(aux2 != NULL){
			free(aux1) ;
			aux1=aux2 ;
			aux2=aux2->prox ;
		} ;
		free(aux1) ;
	} ;
} ;
free(st) ;
}


/*
-------------------------------------------
Função que cria uma nova estrutura notabsim
-------------------------------------------
*/
notabsim* CriaNoTabSim()

{
notabsim *aux=malloc(sizeof(notabsim)) ;
aux->prox=NULL ;
aux->num=0 ;

return aux ;
}


/*
---------------------------------------------------
Função que procura uma chave3 na tabela de simbolos
---------------------------------------------------
*/
notabsim* ProcuraTabSim(tabsim* st, input* ptr)

/* A função devolve NULL caso a lista esteja vazia */
{
notabsim *aux=st->tab[Hash(key2(ptr))] ;

if(aux != NULL)
	while(aux != NULL && aux->cor != key3(ptr))
		aux=aux->prox ;

return aux ;
}


/*
------------------------------------------------
Função que insere uma peça na tabela de simbolos
------------------------------------------------
*/
void InsereTabSim(tabsim* st, input* ptr)

{
notabsim* aux=ProcuraTabSim(st, ptr) ;

if(aux == NULL){
	aux=CriaNoTabSim() ;
	aux->cor=key3(ptr) ;
	if(st->ult[Hash(key2(ptr))] == NULL){
		st->ult[Hash(key2(ptr))]=aux ;
		st->tab[Hash(key2(ptr))]=st->ult[Hash(key2(ptr))] ;
	}
	else{
		st->ult[Hash(key2(ptr))]->prox=aux ;
		st->ult[Hash(key2(ptr))]=aux ;
	} ;
} ;
aux->num+=1 ;
st->comp+=1 ;

}


/*
------------------------------------------------
Função que remove uma peça na tabela de simbolos
------------------------------------------------
*/
void RemoveTabSim(tabsim* st, peca* pec)

{
input in ;
notabsim* aux ;

in.tipo=pec->tipo ;
in.cor=pec->cor ;
in.ncol=0 ;

aux=ProcuraTabSim(st, &in) ;
aux->num-=1 ;
st->comp-=1 ;
}

