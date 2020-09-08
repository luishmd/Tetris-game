/*
=====================================================
Biblioteca de funções das operações no espaço de jogo
=====================================================
*/

/*
--------------------------------------
Função que inicializa o espaço de jogo
--------------------------------------
*/
espaco* CriaEspJogo() ;


/*
-------------------------------
Função que inicializa uma linha
-------------------------------
*/
void InicLinha(espaco *esp, linha *lin) ;


/*
---------------------------------------------
Função que cria nlin linhas no espaço de jogo
---------------------------------------------
*/
void CriaLinhas(espaco *esp, int nlin) ;


/*
------------------------------------------------------------------------------
Função que actualiza a numeração do jogo após eliminação de uma ou mais linhas
------------------------------------------------------------------------------
*/
void ActualizaIndice(espaco *esp, linha *lin) ;


/*
----------------------------------------------
Função que elimina uma linha do espaço de jogo
----------------------------------------------
*/
void Elimina1(espaco *esp, linha *lin, lststr *lst, tabsim *st) ;


/*
------------------------------------------------
Função que elimina três linhas do espaço de jogo
------------------------------------------------
*/
void Elimina(espaco *esp, linha *lin, int pts[4], lststr *lst, tabsim *st) ;


/*
----------------------------------------------
Função que liberta a memória do espaço de jogo
----------------------------------------------
*/
void DestroiEspaco(espaco *esp) ;

