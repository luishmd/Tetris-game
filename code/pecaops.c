#include <stdlib.h>
#include "structs.h"
#include "tabsim.h"

/*
----------------------------------------
Função que inicializa uma estrutura peca
----------------------------------------
*/
void CriaInicPeca(linha *lin, input *in, char c)

/* Cria, inicia e insere a estrutura peca na linha lin */
{
peca *aux2=lin->pec ;
peca *aux=malloc(sizeof(peca)) ;

/* Incializa a estrutura peca criada */
aux->tipo=in->tipo ;
aux->cor=in->cor ;
aux->parte=c ;
aux->ptr=NULL ;

/* Insere essa estrutura na última posição da lista de peças da linha lin */
if(lin->pec == NULL)
	lin->pec=aux ;
else{
	while(aux2->ptr != NULL)
		aux2=aux2->ptr ;
	aux2->ptr=aux ;	
} ;
}


/*
----------------------------------------------------------------
Função que elimina uma lista de estruturas de pecas de uma linha
----------------------------------------------------------------
*/
void DestroiListaPeca(peca *pec)

{
peca *aux=pec ;

if(aux == NULL)
	return ;
else{
	DestroiListaPeca(aux->ptr) ;
	free(aux) ;
} ;
}


/*
------------------------------------------------------------------------------------
Função que procura uma estrutura peca numa lista de estruturas de pecas de uma linha
------------------------------------------------------------------------------------
*/
peca* PosicionaPeca(linha *lin, peca pec)

{
peca *aux=lin->pec ;

while(1){
	if(aux->tipo == pec.tipo && aux->cor == pec.cor && aux->parte == pec.parte)
		break ;	
	aux=aux->ptr ;
} ;

return aux ;
}



/*
--------------------------------------------------------------------
Função que remove uma estrutura peca de uma lista de estruturas peca
--------------------------------------------------------------------
*/
peca* RemovePeca(linha *lin, peca *pec)

{
peca* aux=lin->pec ;

if(pec != lin->pec){
	while(aux->ptr != pec)
		aux=aux->ptr ;
	aux->ptr=pec->ptr ;
}
else
	lin->pec=pec->ptr ;
aux=aux->ptr ;

free(pec) ;

return aux ;
}


/*
-------------------------------------------------------------------------------------
Função que elimina as peças que se tornaram incompletas com a eliminação da linha lin
-------------------------------------------------------------------------------------
*/
void EliminaPecaIncomp(linha *lin, tabsim *st)

{
peca *pec1=lin->pec, *pec2 ;


/* O incremento deste ciclo está na função RemovePeca */
while(pec1 != NULL){
	if(pec1->tipo != 1){
		if(pec1->parte == 'c'){
			pec1->parte='b' ;
			pec2=PosicionaPeca(lin->ant, *pec1) ;
			pec2=RemovePeca(lin->ant, pec2) ;
		}
		else{
			pec1->parte='c' ;
			pec2=PosicionaPeca(lin->prox, *pec1) ;
			pec2=RemovePeca(lin->prox, pec2) ;
		} ;
	} ;
	RemoveTabSim(st, pec1) ;
	pec1=RemovePeca(lin, pec1) ;
} ;
}

