/*
==================================================
Biblioteca de funções necessárias ao selectionsort
==================================================
*/

/*
-----------------------------------------------------------
Função que determina se a chave3 k1 é maior que a chave3 k2
-----------------------------------------------------------
*/
int MaiorChave3(chave3 k1, chave3 k2) ;


/*
-----------------------------------------------------------------
Função que troca dois nós notabsim adjacentes (troca no1 com no2)
-----------------------------------------------------------------
*/
void TrocaNoTabSim(notabsim *no1, notabsim *no2) ;


/*
------------------------------------------------------------------------
Função que ordena uma lista de notabsim usando o algoritmo SelectionSort
------------------------------------------------------------------------
*/
void SelectionSort(notabsim *prim) ;


/*
-------------------------------------------------------------------------
Função que ordena uma tabela de simbolos usando o algoritmo SelectionSort
-------------------------------------------------------------------------
*/
void OrdenaTabSim(tabsim *st) ;

