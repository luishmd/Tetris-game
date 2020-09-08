#include "structs.h"
#include "espacojogo.h"
#include "pecaops.h"

/*
--------------------------
Função que insere a peça 1
           ####
--------------------------
*/
void Peca1(input *in, linha *lin)

{
int i ;

for(i=0; i<4 ; i++){
	(lin->espacojogo[in->ncol-1+i])=in->cor ;
} ;
/* Por defeito o caracter é 'c' mas como a peça 1 só ocupa uma linha é indiferente */
CriaInicPeca(lin, in, 'c') ;
}

/*
--------------------------
Função que insere a peça 2
           ##
           ##
--------------------------
*/
void Peca2(input *in, linha *lin)

{
int i ;
linha *aux=lin ;

for(i=0; i<2 ; i++){
	(aux->espacojogo[in->ncol-1+i])=in->cor ;
} ;
CriaInicPeca(aux, in, 'c') ;
aux=(aux->ant) ;
for(i=0; i<2 ; i++){
	(aux->espacojogo[in->ncol-1+i])=in->cor ;
} ;
CriaInicPeca(aux, in, 'b') ;
}

/*
--------------------------
Função que insere a peça 3
           ##
            ##
--------------------------
*/
void Peca3(input *in, linha *lin)

{
int i ;
linha *aux=lin ;

for(i=0; i<2 ; i++){
	(aux->espacojogo[in->ncol-1+i])=in->cor ;
} ;
CriaInicPeca(aux, in, 'c') ;
aux=(aux->ant) ;
for(i=0; i<2 ; i++){
	(aux->espacojogo[in->ncol+i])=in->cor ;
} ;
CriaInicPeca(aux, in, 'b') ;
}

/*
--------------------------
Função que insere a peça 4
           ###
            #
--------------------------
*/
void Peca4(input *in, linha *lin)

{
int i ;
linha *aux=lin ;

for(i=0; i<3 ; i++){
	(aux->espacojogo[in->ncol-1+i])=in->cor ;
} ;
CriaInicPeca(aux, in, 'c') ;
aux=(aux->ant) ;
(aux->espacojogo[in->ncol])=in->cor ;
CriaInicPeca(aux, in, 'b') ;
} 


/*
--------------------------
Função que insere a peça 5
           ###
           #
--------------------------
*/
void Peca5(input *in, linha *lin)

{
int i ;
linha *aux=lin ;

for(i=0; i<3 ; i++){
	(aux->espacojogo[in->ncol-1+i])=in->cor ;
} ;
CriaInicPeca(aux, in, 'c') ;
aux=(aux->ant) ;
(aux->espacojogo[in->ncol-1])=in->cor ;
CriaInicPeca(aux, in, 'b') ;
} 


/*
--------------------------
Função que insere uma peça
--------------------------
*/
void InserePeca(input *in, linha *lin)

{
switch (in->tipo) {
	case 1 : Peca1(in,lin); break;
	case 2 : Peca2(in,lin); break;
	case 3 : Peca3(in,lin); break;
	case 4 : Peca4(in,lin); break;
	case 5 : Peca5(in,lin);
} ;
}

