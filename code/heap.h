/*
===============================================
Biblioteca de funções para as operações na heap
===============================================
*/

/*
-----------------------------------------------------------
Função que determina se a chave1 k1 é maior que a chave1 k2
-----------------------------------------------------------
*/
int maior(chave1 k1, chave1 k2) ;


/*
--------------------------------------------------------
Função que troca a chave1 k1 e a chave1 k2 no lststr lst
--------------------------------------------------------
*/
void troca(nostr *ptr1, nostr *ptr2) ;


/*
--------------------------------------------------------------
Função que devolve um apontador para o i-ésimo elemento de lst
--------------------------------------------------------------
*/
nostr* Posiciona(lststr *lst, int i) ;


/*
----------------------------------------------
Função que cria uma heap a partir de um lststr
----------------------------------------------
*/
void FixDown(lststr *lst, int ind, int dim) ;


/*
----------------------------------------------
Função que cria uma heap a partir de um lststr
----------------------------------------------
*/
void Heapify(lststr *lst) ;


/*
------------------------------------------------------------------------
Função que ordena uma lista de chaves chave1 usando o algoritmo heapsort
------------------------------------------------------------------------
*/
void Heapsort(lststr *lst, int N) ;


/*
--------------------------------------------
Função que ordena uma lista de chaves chave1
--------------------------------------------
*/
void OrdenaLinEliminadas(lststr *lst) ;


