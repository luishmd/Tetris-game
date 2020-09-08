/*
=========================================================
Biblioteca de funções das operações na tabela de simbolos
=========================================================
*/

/*
--------------------------------------------
Função que inicializa uma tabela de simbolos
--------------------------------------------
*/
tabsim* InicTabSim() ;


/*
-----------------------------------------
Função que destroi uma tabela de simbolos
-----------------------------------------
*/
void DestroiTabSim(tabsim *st) ;


/*
-------------------------------------------
Função que cria uma nova estrutura notabsim
-------------------------------------------
*/
notabsim* CriaNoTabSim() ;


/*
---------------------------------------------------
Função que procura uma chave3 na tabela de simbolos
---------------------------------------------------
*/
notabsim* ProcuraTabSim(tabsim *st, input *ptr) ;


/*
------------------------------------------------
Função que insere uma peça na tabela de simbolos
------------------------------------------------
*/
void InsereTabSim(tabsim *st, input *ptr) ;


/*
------------------------------------------------
Função que remove uma peça na tabela de simbolos
------------------------------------------------
*/
void RemoveTabSim(tabsim *st, peca *pec) ;


