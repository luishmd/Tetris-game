/*
====================================================================
Biblioteca de funções das operações para a lista de strings (lststr)
====================================================================
*/

/*
---------------------------
Função que inicia um lststr
---------------------------
*/
lststr* InicLstStr() ;


/*
--------------------------
Função que inicia um nostr
--------------------------
*/
void InicNoStr(nostr *no) ;


/*
----------------------------
Função que destroi um lststr
----------------------------
*/
void DestroiLstStr(lststr *lst) ;


/*
---------------------------------------
Função que insere uma chave1 num lststr
---------------------------------------
*/
void InsereChave1(lststr *lst, chave1 k) ;


/*
-------------------------------------------------
Função que devolve a chave de uma linha eliminada
-------------------------------------------------
*/
chave1 DevolveChave1(linha *lin) ;
