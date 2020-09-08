#include <stdlib.h>
#include "structs.h"
#include "espacojogo.h"

/*
------------------------------------------------------------------------------
Função que determina a linha do espaço de jogo onde a peça 1 deve ser inserida
------------------------------------------------------------------------------
*/
linha* LinhaPeca1(espaco *esp, input *in)

{
int nesp ;
linha *ptr=(esp->topo) ;

/* Se a estrutura está vazia é necessário criar uma linha */
if(ptr == NULL){
	CriaLinhas(esp, 1) ;
	ptr=(esp->topo) ;
} 
/* Caso contrário já existe pelo menos uma linha */
else {
	nesp=0 ;
	while(nesp<4 && (ptr->espacojogo[in->ncol-1+nesp]) == ' '){
		nesp++ ;
	} ;
	/* É possível colocar na linha do topo se o numero de espaços for 4. Se não for possivel tem de se criar uma linha acima */
	if(nesp != 4){
		CriaLinhas(esp, 1) ;
		ptr=(esp->topo) ;
	}
	/* Neste caso a linha de topo existe e está vazia, portanto tem de se verificar se há linhas abaixo e se elas estão vazias */
	else {
		/* Só se altera o apontador de linha a inserir se a linha de baixo estiver vazia */
		while(nesp == 4 && ptr != (esp->base)){
			nesp=0 ;
			/* verifica-se a linha abaixo */
			while(nesp<4 && (ptr->ant->espacojogo[in->ncol-1+nesp]) == ' ' ){
				nesp++ ;
			} ;
			/* A linha abaixo está vazia? */
			if(nesp == 4) 
				ptr=(ptr->ant) ;
		} ;
	} ;
} ;

return ptr ;
}


/*
------------------------------------------------------------------------------
Função que determina a linha do espaço de jogo onde a peça 2 deve ser inserida
------------------------------------------------------------------------------
*/
linha* LinhaPeca2(espaco *esp, input *in)

{
int nesp ;
linha *ptr=(esp->topo) ;

/* Se a estrutura está vazia é necessário criar duas linhas */
if(ptr == NULL){
	CriaLinhas(esp, 2) ;
	ptr=(esp->topo) ;
} 
/* Caso contrário já existe pelo menos uma linha */
else {
	nesp=0 ;
	while(nesp<2 && (ptr->espacojogo[in->ncol-1+nesp]) == ' ' ){
		nesp++ ;
	} ;
	/* Se não é possível inserir na linha do topo então têm de se criar também duas linhas */
	if(nesp != 2){
		CriaLinhas(esp, 2) ;
		ptr=(esp->topo) ;
	}
	/* Se há espaço na linha do topo tem de se verificar se há pelo menos uma linha abaixo com espaço */
	else {
		/* A linha do topo está vazia mas é única. Tem então de se criar outra linha acima*/
		if((esp->topo) == (esp->base)){		
			CriaLinhas(esp, 1) ;
			ptr=(esp->topo) ;
		} 
		/* Caso contrário há pelo menos uma linha abaixo */		
		else {
			nesp=0 ;
			while(nesp<2 && (ptr->ant->espacojogo[in->ncol-1+nesp]) == ' '){
				nesp++ ;
			} ;
			/* Se não for possivel inserir na linha abaixo tem de se criar outra linha acima */
			if(nesp != 2){
				CriaLinhas(esp, 1) ;
				ptr=(esp->topo) ;
			}
			/* Caso contrário há espaço para inserir nas duas primeiras linhas. No entanto tem de se verificar se é possivel inserir nas linhas abaixo */
			else {
				/* Só se altera o apontador de linha a inserir se a linha abaixo da de baixo estiver vazia */
				while(nesp == 2 && (ptr->ant) != (esp->base)){
					nesp=0 ;
					/* verifica-se a linha abaixo da de baixo */
					while(nesp<2 && (ptr->ant->ant->espacojogo[in->ncol-1+nesp]) == ' '){
						nesp++ ;
					} ;
					/* A linha abaixo da de baixo está vazia? */
					if(nesp == 2) 
						ptr=(ptr->ant) ;
					} ;
			} ;
		} ;
	} ;
} ;

return ptr ;
}


/*
------------------------------------------------------------------------------
Função que determina a linha do espaço de jogo onde a peça 3 deve ser inserida
------------------------------------------------------------------------------
*/
linha* LinhaPeca3(espaco *esp, input *in)

{
int nesp ;
linha *ptr=(esp->topo) ;

/* Se a estrutura está vazia é necessário criar duas linhas */
if(ptr == NULL){
	CriaLinhas(esp, 2) ;
	ptr=(esp->topo) ;
} 
/* Caso contrário já existe pelo menos uma linha */
else {
	nesp=0 ;
	while(nesp<2 && (ptr->espacojogo[in->ncol+nesp]) == ' '){
		nesp++ ;
	} ;
	/* Se não é possível inserir na linha do topo então têm de se criar também duas linhas */
	if(nesp != 2){
		CriaLinhas(esp, 2) ;
		ptr=(esp->topo) ;
	}
	/* Se há espaço na linha do topo tem de se verificar se há pelo menos uma linha abaixo com espaço */
	else {
		/* A linha do topo está vazia mas é única. Tem então de se criar outra linha acima*/
		if((esp->topo) == (esp->base)){		
			CriaLinhas(esp, 1) ;
			ptr=(esp->topo) ;
		} 
		/* Caso contrário há pelo menos uma linha abaixo */		
		else {
			nesp=0 ;
			while(nesp<2 && (ptr->ant->espacojogo[in->ncol+nesp]) == ' '){
				nesp++ ;
			} ;
			/* Se não for possivel inserir na linha abaixo tem de se criar outra linha acima */
			if(nesp != 2 || (ptr->espacojogo[in->ncol-1]) != ' '){
				CriaLinhas(esp, 1) ;
				ptr=(esp->topo) ;
			}
			/* Caso contrário há espaço para inserir nas duas primeiras linhas. No entanto tem de se verificar se é possivel inserir nas linhas abaixo */
			else {
				/* Só se altera o apontador de linha a inserir se a linha abaixo da de baixo estiver vazia */
				while(nesp == 2 && (ptr->ant) != (esp->base) && (ptr->ant->espacojogo[in->ncol-1]) == ' '){
					nesp=0 ;
					/* verifica-se a linha abaixo da de baixo */
					while(nesp<2 && (ptr->ant->ant->espacojogo[in->ncol+nesp]) == ' '){
						nesp++ ;
					} ;
					/* A linha abaixo da de baixo está vazia? */
					if(nesp == 2 && (ptr->ant->espacojogo[in->ncol-1]) == ' ') 
						ptr=(ptr->ant) ;
				} ;
			} ;
		} ;
	} ;
} ;

return ptr ;
}


/*
------------------------------------------------------------------------------
Função que determina a linha do espaço de jogo onde a peça 4 deve ser inserida
------------------------------------------------------------------------------
*/
linha* LinhaPeca4(espaco *esp, input *in)

{
int nesp ;
linha *ptr=(esp->topo) ;

/* Se a estrutura está vazia é necessário criar duas linhas */
if(ptr == NULL){
	CriaLinhas(esp, 2) ;
	ptr=(esp->topo) ;
} 
/* Caso contrário já existe pelo menos uma linha */
else {
	nesp=0 ;
	while(nesp<1 && (ptr->espacojogo[in->ncol+nesp]) == ' '){
		nesp++ ;
	} ;
	/* Se não é possível inserir na linha do topo então têm de se criar também duas linhas */
	if(nesp != 1){
		CriaLinhas(esp, 2) ;
		ptr=(esp->topo) ;
	}
	/* Se há espaço na linha do topo tem de se verificar se há pelo menos uma linha abaixo com espaço */
	else {
		/* A linha do topo está vazia mas é única. Tem então de se criar outra linha acima*/
		if((esp->topo) == (esp->base)){		
			CriaLinhas(esp, 1) ;
			ptr=(esp->topo) ;
		} 
		/* Caso contrário há pelo menos uma linha abaixo */		
		else {
			nesp=0 ;
			while(nesp<1 && (ptr->ant->espacojogo[in->ncol]) == ' '){
				nesp++ ;
			} ;
			/* Se não for possivel inserir na linha abaixo tem de se criar outra linha acima */
			if(nesp != 1 || (ptr->espacojogo[in->ncol-1]) != ' ' || (ptr->espacojogo[in->ncol+1]) != ' '){
				CriaLinhas(esp, 1) ;
				ptr=(esp->topo) ;
			}
			/* Caso contrário há espaço para inserir nas duas primeiras linhas. No entanto tem de se verificar se é possivel inserir nas linhas abaixo */
			else {
				/* Só se altera o apontador de linha a inserir se a linha abaixo da de baixo estiver vazia */
				while(nesp == 1 && (ptr->ant) != (esp->base) && (ptr->ant->espacojogo[in->ncol-1]) == ' ' && (ptr->ant->espacojogo[in->ncol+1]) == ' '){
					nesp=0 ;
					/* verifica-se a linha abaixo da de baixo */
					while(nesp<1 && (ptr->ant->ant->espacojogo[in->ncol]) == ' '){
						nesp++ ;
					} ;
					/* A linha abaixo da de baixo está vazia? */
					if(nesp == 1 && (ptr->ant->espacojogo[in->ncol-1]) == ' ' && (ptr->ant->espacojogo[in->ncol+1]) == ' ') 
						ptr=(ptr->ant) ;
				} ;
			} ;
		} ;
	} ;
} ;

return ptr ;
}


/*
------------------------------------------------------------------------------
Função que determina a linha do espaço de jogo onde a peça 5 deve ser inserida
------------------------------------------------------------------------------
*/
linha* LinhaPeca5(espaco *esp, input *in)

{
int nesp ;
linha *ptr=(esp->topo) ;

/* Se a estrutura está vazia é necessário criar duas linhas */
if(ptr == NULL){
	CriaLinhas(esp, 2) ;
	ptr=(esp->topo) ;
} 
/* Caso contrário já existe pelo menos uma linha */
else {
	nesp=0 ;
	while(nesp<1 && (ptr->espacojogo[in->ncol-1]) == ' '){
		nesp++ ;
	} ;
	/* Se não é possível inserir na linha do topo então têm de se criar também duas linhas */
	if(nesp != 1){
		CriaLinhas(esp, 2) ;
		ptr=(esp->topo) ;
	}
	/* Se há espaço na linha do topo tem de se verificar se há pelo menos uma linha abaixo com espaço */
	else {
		/* A linha do topo está vazia mas é única. Tem então de se criar outra linha acima*/
		if((esp->topo) == (esp->base)){		
			CriaLinhas(esp, 1) ;
			ptr=(esp->topo) ;
		} 
		/* Caso contrário há pelo menos uma linha abaixo */		
		else {
			nesp=0 ;
			while(nesp<1 && (ptr->ant->espacojogo[in->ncol-1]) == ' '){
				nesp++ ;
			} ;
			/* Se não for possivel inserir na linha abaixo tem de se criar outra linha acima */
			if(nesp != 1 || (ptr->espacojogo[in->ncol]) != ' ' || (ptr->espacojogo[in->ncol+1]) != ' '){
				CriaLinhas(esp, 1) ;
				ptr=(esp->topo) ;
			}
			/* Caso contrário há espaço para inserir nas duas primeiras linhas. No entanto tem de se verificar se é possivel inserir nas linhas abaixo */
			else {
				/* Só se altera o apontador de linha a inserir se a linha abaixo da de baixo estiver vazia */
				while(nesp == 1 && (ptr->ant) != (esp->base) && (ptr->ant->espacojogo[in->ncol]) == ' ' && (ptr->ant->espacojogo[in->ncol+1]) == ' '){
					nesp=0 ;
					/* verifica-se a linha abaixo da de baixo */
					while(nesp<1 && (ptr->ant->ant->espacojogo[in->ncol-1]) == ' '){
						nesp++ ;
					} ;
					/* A linha abaixo da de baixo está vazia? */
					if(nesp == 1 && (ptr->ant->espacojogo[in->ncol]) == ' ' && (ptr->ant->espacojogo[in->ncol+1]) == ' ') 
						ptr=(ptr->ant) ;
				} ;
			} ;
		} ;
	} ;
} ;

return ptr ;
}

		
/*
----------------------------------------------------------------------------
Função que determina a linha do espaço de jogo onde a peça deve ser inserida
----------------------------------------------------------------------------
*/
linha* LinhaPeca(espaco *esp, input *in)

{
linha* lin=NULL ;



/* Verifica o tipo de peça e usa a respectiva função */
switch(in->tipo){
	case 1 : lin=LinhaPeca1(esp,in); break ;
	case 2 : lin=LinhaPeca2(esp,in); break ;
	case 3 : lin=LinhaPeca3(esp,in); break ;
	case 4 : lin=LinhaPeca4(esp,in); break ;
	case 5: lin=LinhaPeca5(esp,in); break ;
} ;

return lin ;
}


