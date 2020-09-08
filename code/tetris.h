/*
===================================================================
Biblioteca de funções diversas necessárias ao funcionamento do jogo
===================================================================
*/

/*
-----------------------------------------------
Função que lê uma peça do stdin e armazena em v
-----------------------------------------------
*/
void LeInput(input *v) ;


/*
-------------------------------
Função que inicializa a memória
-------------------------------
*/
void InicMem(memoria *ptr_mem) ;


/*
-----------------------------------
Função que imprime o espaço de jogo
-----------------------------------
*/
void Imprime(espaco *esp, int *ptr_pts, lststr *lst, tabsim *st) ;


/*
-----------------------------
Função que preenche a memoria
-----------------------------
*/
void PreencheMem(linha *ptr, memoria *ptr_mem) ;


/*
--------------------------------
Função que actualiza a pontuação
--------------------------------
*/
void Actualiza(espaco *esp, linha *ptr, input *in, int *ptr_pts, lststr *lst, tabsim *st) ;

