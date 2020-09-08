#include <stdlib.h>
#include <string.h>
#include "structs.h"

/*
---------------------------
Função que inicia um lststr
---------------------------
*/
lststr* InicLstStr()

{
lststr *lst=malloc(sizeof(struct _lststr)) ;

lst->prim=lst->ult=NULL ;
lst->num=0 ;

return lst ;
}


/*
--------------------------
Função que inicia um nostr
--------------------------
*/
void InicNoStr(nostr *no)

{
no->prox=no->ant=NULL ;
no->ch=NULL ;
}


/*
----------------------------
Função que destroi um lststr
----------------------------
*/
void DestroiLstStr(lststr *lst)

{
nostr *aux=lst->prim ;
chave1 aux2 ;

if(aux == NULL){
	free(lst) ;
	return ;
}
else{
	aux2=aux->ch ;
	lst->prim=lst->prim->prox ;
	DestroiLstStr(lst) ;
	free(aux2) ;
	free(aux) ;
} ;
}


/*
---------------------------------------
Função que insere uma chave1 num lststr
---------------------------------------
*/
void InsereChave1(lststr *lst, chave1 k)

{
nostr *no=malloc(sizeof(struct _nostr)) ;
InicNoStr(no) ;

no->ch=malloc(sizeof(char)*(NUM_COL+1)) ;
no->ch=strcpy(no->ch, k) ;
lst->num+=1 ;

if(lst->prim == NULL)
	lst->prim=lst->ult=no ;
else{
	lst->ult->prox=no ;
	lst->ult->prox->ant=lst->ult ;
	lst->ult=no ;
} ;
}


/*
-------------------------------------------------
Função que devolve a chave de uma linha eliminada
-------------------------------------------------
*/
chave1 DevolveChave1(linha *lin)

{
chave1 aux=lin->espacojogo ;
int i=0, esp, c, j ;

while(i<NUM_COL){
	j=i ;
	c=0 ;
	while(j < NUM_COL && c == 0){
		if(aux[j] == ' '){
			esp=j ;
			c=1 ;
		} ;
		j++ ;
	} ;
	while(j < NUM_COL && aux[j] == ' ')
		j++ ;
	if(j < NUM_COL){
		aux[esp]=aux[j] ;
		aux[j]=' ' ;
	} ;
	i++ ;
} ;

return aux ;
}

