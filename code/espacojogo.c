#include <stdlib.h>
#include "structs.h"
#include "lststrops.h"
#include "pecaops.h"

/*
--------------------------------------
Função que inicializa o espaço de jogo
--------------------------------------
*/
espaco* CriaEspJogo()

{
espaco *esp=malloc(sizeof(espaco)) ;
(esp->base)=(esp->topo)=NULL ;
return esp ;
} 


/*
-------------------------------
Função que inicializa uma linha
-------------------------------
*/
void InicLinha(espaco *esp, linha *lin)

{
int i ;
for(i=0; i<NUM_COL; i++){
	(lin->espacojogo[i])=' ';
} ;

lin->espacojogo[i]='\0' ;
(lin->ant)=(lin->prox)=NULL ;

if(esp->topo == NULL)
	(lin->nlin)=1 ;		
else
	(lin->nlin)=(esp->topo->nlin)+1 ;
lin->pec=NULL ;
}


/*
---------------------------------------------
Função que cria nlin linhas no espaço de jogo
---------------------------------------------
*/
void CriaLinhas(espaco *esp, int nlin)

{
int i ;	
linha *ptr ;
for(i=0; i<nlin; i++){
	ptr=malloc(sizeof(linha)) ;
	InicLinha(esp, ptr) ;
	(ptr->ant)=(esp->topo) ;
	/* Se o espaço de jogo esta vazio */
	if((esp->topo) != NULL){
		(esp->topo->prox)=ptr ;
		(esp->topo)=ptr ;
	}
	else
		(esp->topo)=(esp->base)=ptr ;
} ;
}


/*
------------------------------------------------------------------------------
Função que actualiza a numeração do jogo após eliminação de uma ou mais linhas
------------------------------------------------------------------------------
*/
void ActualizaIndice(espaco *esp, linha *lin)

{
linha *aux=lin ;

/* Se o espaço de jogo não estiver vazio */
if(esp->base != NULL){
	/* Se a base tiver sido removida aux estará a apontar para NULL */
	if(aux == NULL){
		aux=esp->base ;
		aux->nlin=1 ;
	} ;
	aux=aux->prox ;
	while(aux != NULL){
		aux->nlin=aux->ant->nlin+1 ;
		aux=aux->prox ;
	} ;
} ;

return ;
}


/*
----------------------------------------------
Função que elimina uma linha do espaço de jogo
----------------------------------------------
*/
linha* Elimina1(espaco *esp, linha *lin, lststr *lst, tabsim *st)

/* Devolve sempre um apontador para a linha que estava abaixo antes da remoção (se estiver a apontar para a base fica a apontar para NULL)
   Se a função é chamada há pelo menos uma linha. */
{
linha *aux=lin ;
chave1 k=DevolveChave1(aux) ;

EliminaPecaIncomp(lin, st) ;

/* Se só houver uma linha então a estrutura fica vazia */
if((esp->topo) == (esp->base))
	(esp->topo)=(esp->base)=lin=NULL ;
/* Se a linha a remover está no topo já sabemos que há pelo menos uma linha abaixo */ 	
else if((esp->topo) == lin){
	(esp->topo)=(lin->ant) ;
	(esp->topo->prox)=NULL ;
	lin=(esp->topo) ;
}
/* Se a linha a remover está na base já sabemos que há pelo menos uma linha acima */ 
else if((esp->base) == lin){
	(esp->base)=(lin->prox) ;
	/* Se a linha é a base então a convenção é retornar NULL */ 
	(esp->base->ant)=lin=NULL ;
}
/* Caso contrário a linha está entre o topo e base */ 
else {
	(lin->prox->ant)=(lin->ant) ;
	(lin->ant->prox)=(lin->prox) ;
	lin=(lin->ant) ;
} ;

InsereChave1(lst, k) ;
free(aux) ;

return lin ;
}


/*
-------------------------------------------
Função que elimina linhas do espaço de jogo
-------------------------------------------
*/
void Elimina(espaco *esp, linha *lin, int pts[2], lststr *lst, tabsim *st)

/* Se esta função é chamada então existe(m) linha(s) a eliminar */
{
/* Testa situação - Uma linha monocor e a outra não está cheia */
if(pts[0] == 1 && pts[3] != 0){
	if(pts[3] == 1 && lin != NULL && (lin->prox) != NULL)
		lin=Elimina1(esp, lin->prox, lst, st) ;	
	lin=Elimina1(esp, lin, lst, st) ;
	if(lin != NULL)
		lin=Elimina1(esp, lin, lst, st) ;
	if(pts[3] == 2 && lin != NULL)
		lin=Elimina1(esp, lin, lst, st) ;
} ;
/* Testa situação - Uma linha multicor e a outra não está cheia */
if(pts[0] ==1 && pts[3] == 0){
	if(pts[1] == 2)
		lin=Elimina1(esp, lin, lst, st) ;
	else {
		if((lin->ant) != NULL)
			lin=Elimina1(esp, lin->ant, lst, st) ;
	} ;
} ;
/* Testa situação - Duas linhas multicores */
if(pts[0] == 2 && pts[3] == 0){
	/* Tenho a certeza que estas duas linhas existem */
	lin=Elimina1(esp, lin, lst, st) ;
	lin=Elimina1(esp, lin, lst, st) ;
} ;
/* Testa situação - Duas linhas monocores */
if(pts[0] == 2 && pts[1] == 1 && pts[2] == 1){
	if(lin != NULL && (lin->prox) != NULL)
		lin=Elimina1(esp, lin->prox, lst, st) ;	
	/* Tenho a certeza que pelo menos estas duas linhas existem */
	lin=Elimina1(esp, lin, lst, st) ;
	lin=Elimina1(esp, lin, lst, st) ;
	if(lin != NULL)
		lin=Elimina1(esp, lin, lst, st) ;
	
} ;
/* Testa situação - Uma linha multicor e outra monocor */
if(pts[0] == 2 && pts[1] != pts[2]){
	if(pts[1] == 1 && lin != NULL && (lin->prox) != NULL)
		lin=Elimina1(esp, lin->prox, lst, st) ;
	/* Tenho a certeza que pelo menos estas duas linhas existem */
	lin=Elimina1(esp, lin, lst, st) ;
	lin=Elimina1(esp, lin, lst, st) ;
	if(pts[1] == 2 && lin != NULL)
		lin=Elimina1(esp, lin, lst, st) ;
} ;

ActualizaIndice(esp, lin) ;
}


/*
----------------------------------------------
Função que liberta a memória do espaço de jogo
----------------------------------------------
*/
void DestroiEspaco(espaco *esp)

{
linha *aux=esp->topo ;

if(aux == NULL){
	free(esp) ;
	return ;
}
else{
	esp->topo=esp->topo->ant ;
	DestroiEspaco(esp) ;
	DestroiListaPeca(aux->pec) ;
	free(aux) ;
} ;
}

