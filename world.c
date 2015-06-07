/*FUNÇÕES QUE PODERIAM SER IMPLEMENTADAS QUE CORRESPONDEM AO MUNDO 3D*/

#include <stdlib.h>
#include <time.h>
#include "world.h"

Tree initTree(float x, float z) {

	Tree t;
	
	t.loc[0] = x;
	t.loc[1] = 0.0f;
	t.loc[2] = z;

	return t;
}

Map initWorld() {

	srand(time(NULL));
	int i, r, b;
	float x, z;

	Map m;

	m.size = MAPSIZE;

	m.tree_count = TREECOUNT;
	m.trees = (Tree *) malloc (m.tree_count*sizeof(Tree));

	for (i = 0; i < m.tree_count; i++){
		if ((r = rand()%100) >= 50) r = -1;
		else r = 1;
		if ((b = rand()%100) >= 50) b = -1;
		else b = 1;
		x = (float) (rand()% (int) m.size) *r;
		z = (float) (rand()% (int) m.size)  *b;
		m.trees[i] = initTree(x, z);
	}

	return m;
}
