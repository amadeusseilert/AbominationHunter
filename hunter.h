/*FUNÇÕES QUE PODERIAM SER IMPLEMENTADAS QUE CORRESPONDEM A TODAS AS EXECUÇÕES DO PERSONGAEM*/

#define MAX_HP 100
#define MAX_EP 100

//AÇÕES
#define STANDING 0
#define MOVING 1
#define ATTACKING1 2
#define ATTACKING2 3
#define SPECIAL 4

typedef struct hunter {
	//propriedades físicas
	float pos[3]; //posição corrente no mapa
	float collision;
	int angle; // angulo de orientação
	float move_speed; //velocidade de deslocamento	
	float hight;
	//propriedades de estado
	int action; //ação corrente a ser renderizada
	int weapon; //arma equipada
	int hp; //vida corrente
	int ep; //pontos de energia corrente
	int pts; //pontuação geral
} Hunter;

Hunter initHunter();
Hunter forward(Hunter h, float mouseZ);
Hunter back(Hunter h, float mouseZ);
Hunter right(Hunter h, float mouseZ);
Hunter left(Hunter h, float mouseZ);

int isHunterDead(Hunter h);
