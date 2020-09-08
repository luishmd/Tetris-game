#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "espacojogo.h"
#include "heap.h"
#include "hash.h"

/*
-----------------------------------------------
Função que lê uma peça do stdin e armazena em v
-----------------------------------------------
*/
void LeInput(input *v)

{
scanf("%d %d %c", &(v->tipo), &(v->ncol), &(v->cor)) ;
} 


/*
-------------------------------
Função que inicializa a memória
-------------------------------
*/
void InicMem(memoria *ptr_mem)

{
int i ;
/* Coloca espaços no vector de caracteres mem */
for(i=0; i<NUM_CORES; i++){
	(ptr_mem->mem[i])=' ';
} ;
/* Coloca o número de cores a zero */
(ptr_mem->ncores)=0 ;
/* Coloca a linha completamente vazia */
(ptr_mem->nesp)=NUM_COL ;	
}




/*
-----------------------------------
Função que imprime o espaço de jogo
-----------------------------------
*/
void Imprime(espaco *esp, int *ptr_pts, lststr *lst, tabsim *st)

{
int i, N=lst->num ;
linha *aux=esp->topo ;
notabsim *aux1 ;
char c ;

/* Se o espaço de jogo está vazio, o numero de linhas maximo é 0 */
if(aux == NULL){
	printf("0\n") ;
	printf("%d\n\n", (*ptr_pts)) ;
}
/* Caso contrário há pelo menos uma linha... */
else {
	/* Imprime o número da linha máxima e os pontos obtidos*/
	printf("%d\n", esp->topo->nlin) ;
	printf("%d\n\n", (*ptr_pts)) ;
	/* Imprime o espaço de jogo */
	for(; aux != NULL; aux=aux->ant){
		printf("|") ;
		for(i=0; i< NUM_COL; i++){
			printf("%c", aux->espacojogo[i]) ;
		} ;
		printf("| %d\n", aux->nlin) ;
	} ;
} ;
/* Imprime a base do espaço de jogo */
printf(" ----------\n\n") ;

printf("%d\n", st->comp) ;

for(i=1; i<=NUMPECAS; i++){
	aux1=st->tab[Hash(i)] ;
	while(aux1 != NULL){
		while(aux1->num > 0){
			printf("%d %c\n", i, aux1->cor) ;
			aux1->num-=1 ;
		} ;
		aux1=aux1->prox ;
	} ;
} ;

printf("\n") ;

if(N != 0 ){
	if((N%2) != 0)
		N=N/2+1 ;
	else
		N=N/2 ;
	i=0 ;
	while((c=(*Posiciona(lst, N)).ch[i]) != ' ' && i< NUM_COL){
		printf("%c", c) ;
		i++ ;
	} ;
	printf("\n") ;
}
else
	printf("No eliminations\n") ;
}


/*
-----------------------------
Função que preenche a memoria
-----------------------------
*/
void PreencheMem(linha *ptr, memoria *ptr_mem)

/*
Descrição: Preenche a memoria da linha apontada por ptr e devolve ptr. Se não estiver (e a peça inserida for != de 1) então verifica a linha abaixo. Se a peça for != 1 então devolve um apontador para a linha abaixo.
*/
{
int i, j ;
char c ;

InicMem(ptr_mem) ;
for(i=0; i<NUM_COL; i++){
	c=(ptr->espacojogo[i]) ;
	for(j=0; j<NUM_CORES; j++){
		if(c == (ptr_mem->mem[j]))
			break ;
		else if((ptr_mem->mem[j]) == ' '){
			(ptr_mem->mem[j])=c ;
			(ptr_mem->ncores)++ ;
			break ;
		} ;
	} ;
	if(c != ' ')
		(ptr_mem->nesp)-- ;
} ;
}


/*
--------------------------------
Função que actualiza a pontuação
--------------------------------
*/
void Actualiza(espaco *esp, linha *ptr, input *in, int *ptr_pts, lststr *lst, tabsim *st)

/* Descrição: Esta função tem como principal tarefa actualizar a pontuação e como tarefa secundária eliminar as linhas respectivas.
   Para facilitar a tarefa da eliminação, usa-se um vector pts[] para codificar a acção de eliminação. 
   De notar que ptr está sempre a apontar para a linha onde a peça foi inserida (no caso de peças de duas linhas é para a de cima).
   A codificação é a seguinte:
	pts[0] - número de linhas a remover
	pts[1] - codificação da primeira linha a remover (0 - linha inesxistente ou não preenchida; 1 - linha monocor; 2 - linha multicor)
	pts[2] - codificação da segunda linha a remover (0 - linha inesxistente ou não preenchida; 1 - linha monocor; 2 - linha multicor)
	pts[3] - codificação da posição da linha monocor (0 - não há linha multicor; 1 - em cima; 2 - em baixo (engloba também o caso de duas monocores)

	ex/ duas linhas multicores terão a codificação - 2 2 2 0
	    a primeira linha monocor e a de baixo não está preenchida - 1 1 0 1
*/
{
memoria mem, *ptr_mem=&mem ;
int pts[]={0, 0, 0, 0}, bonus=0;

/* Determina o estado da primeira linha - se tiver zero espaços está cheia e nesse caso interessa ver o número de cores para ver se é multi ou monocor */
PreencheMem(ptr, ptr_mem) ;
if(ptr_mem->nesp == 0){
	pts[0]++ ;
	if(ptr_mem->ncores == 1){
		pts[1]=1 ;
		pts[3]=1 ;
		bonus+=NUM_PTS_MONO ;
	} 
	else {
		pts[1]=2 ;
		bonus+=NUM_PTS_MULTI ;
	} ;
} ;
if((in->tipo) != 1 && (ptr->ant) != NULL){
/* Determina o estado da segunda linha - se tiver zero espaços está cheia e nesse caso interessa ver o número de cores para ver se é multi ou monocor */
	PreencheMem(ptr->ant, ptr_mem) ;
	if(ptr_mem->nesp == 0){
		pts[0]++ ;
		if(ptr_mem->ncores == 1){
			pts[2]=1 ;
			pts[3]=2 ;
			bonus+=NUM_PTS_MONO ;
		} 
		else {
			pts[2]=2 ;
			bonus+=NUM_PTS_MULTI ;
		} ;
	} ;
} ;

(*ptr_pts)+=bonus ;

/* Se houver(em) linhas a remover */
if(pts[0] > 0)
	Elimina(esp, ptr, pts, lst, st) ;
}

