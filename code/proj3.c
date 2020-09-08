#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "tetris.h"
#include "inserepeca.h"
#include "espacojogo.h"
#include "determinalinha.h"
#include "lststrops.h"
#include "heap.h"
#include "hash.h"
#include "tabsim.h"
#include "selection.h"


int main(){

espaco *esp=CriaEspJogo() ;
linha *lin ;
int i, n, pts=0, *ptr_pts=&pts ;
input in, *ptr_in=&in ;
lststr *lst=InicLstStr() ;
tabsim *st=InicTabSim() ;

/* Lê o número de peças  a inserir */
scanf("%d", &n) ;

for(i=0; i<n; i++){
	LeInput(ptr_in) ;
	lin=LinhaPeca(esp, ptr_in) ;
	InserePeca(ptr_in, lin);
	InsereTabSim(st, ptr_in) ;
	/* Actualiza a pontuação e elimina as linhas respectivas */
	Actualiza(esp, lin, ptr_in, ptr_pts, lst, st) ;
} ;

OrdenaLinEliminadas(lst) ;
OrdenaTabSim(st) ;

Imprime(esp, ptr_pts, lst, st) ;

DestroiLstStr(lst) ;
DestroiEspaco(esp) ;
DestroiTabSim(st) ;

return 0 ;
}

