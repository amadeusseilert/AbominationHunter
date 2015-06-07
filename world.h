/*FUNÇÕES QUE PODERIAM SER IMPLEMENTADAS QUE CORRESPONDEM AO MUNDO 3D*/

#define SQRT2DIV2 0.707106
#define MAPSIZE 100.0
#define TREECOUNT 100

typedef struct tree {
	
	float loc[3];
	//texturas?
} Tree;

typedef struct map {

	float size;
	int tree_count;
	Tree *trees;
	//texturas?
} Map;


Tree initTree(float x, float z);

Map initWorld();

