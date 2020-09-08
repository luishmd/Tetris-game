#define NUM_COL 10
#define NUM_CORES 6
#define NUM_PTS_MULTI 1
#define NUM_PTS_MONO 3
#define NUMPECAS 5

#define key2(in) (in->tipo)
#define key3(in) (in->cor)

typedef char* chave1 ;

typedef int chave2 ;

typedef char chave3 ;

typedef struct _peca{
	int tipo ;
	char cor ;
	char parte ;
	struct _peca *ptr ;
} peca ;

typedef struct _nostr{
	chave1 ch ;
	struct _nostr *prox, *ant ;
} nostr ;

typedef struct _lststr{
	nostr *prim, *ult ;
	int num ;
} lststr ;

typedef struct _notabsim{
	chave3 cor ;
	int num ;
	struct _notabsim *prox ;
} notabsim ;

typedef struct _tabsim{
	notabsim *tab[NUMPECAS], *ult[NUMPECAS] ;
	int comp ;
} tabsim ;

typedef struct _linha{
	char espacojogo[NUM_COL+1] ;
	int nlin ;
	struct _linha *ant, *prox ;
	struct _peca *pec ;
} linha ;

typedef struct _mem{
	char mem[NUM_CORES] ;
	int ncores ;
	int nesp ;
} memoria ;

typedef struct _espaco{
	linha *base, *topo ;
} espaco ;

typedef struct _input{
	int tipo ;
	int ncol ;
	char cor ;
} input ;

