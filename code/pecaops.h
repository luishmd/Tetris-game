/*
====================================================
Biblioteca de funções de operações da estrutura Peca
====================================================
*/

/*
----------------------------------------
Função que inicializa uma estrutura peca
----------------------------------------
*/
void CriaInicPeca(linha *lin, input *in, char c) ;


/*
----------------------------------------------------------------
Função que elimina uma lista de estruturas de pecas de uma linha
----------------------------------------------------------------
*/
void DestroiListaPeca(peca *pec) ;


/*
------------------------------------------------------------------------------------
Função que procura uma estrutura peca numa lista de estruturas de pecas de uma linha
------------------------------------------------------------------------------------
*/
peca* PosicionaPeca(linha *lin, peca pec) ;


/*
--------------------------------------------------------------------
Função que remove uma estrutura peca de uma lista de estruturas peca
--------------------------------------------------------------------
*/
peca* RemovePeca(linha *lin, peca *pec) ;


/*
-------------------------------------------------------------------------------------
Função que elimina as peças que se tornaram incompletas com a eliminação da linha lin
-------------------------------------------------------------------------------------
*/
void EliminaPecaIncomp(linha *lin, tabsim *st) ;

