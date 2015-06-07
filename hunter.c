/*FUNÇÕES QUE PODERIAM SER IMPLEMENTADAS QUE CORRESPONDEM A TODAS AS EXECUÇÕES DO PERSONGAEM*/

#include <stdlib.h>
#include <math.h>
#include "hunter.h"
#include "weapon.h"

Hunter initHunter(){
	Hunter h;
	h.pos[0] = 0.0f;
	h.pos[1] = 0.0f;
	h.pos[2] = 0.0f;
	h.collision = 0.5f;
	h.move_speed = 0.4f;
	h.hight = 1.5f;
	h.angle = 0;
	h.action = STANDING;
	h.weapon = WEAPON_FIST;
	h.hp = MAX_HP;
	h.ep = MAX_EP;
	h.pts = 0;

	return h;
}

//FUNÇÕES DE MOVIMENTO
Hunter forward(Hunter h, float mouseZ) {
	int factor = 1;
	if (mouseZ < 0) factor = -1;
	h.pos[0] += sin(M_PI * h.angle / 180) *h.move_speed*factor;
	h.pos[2] += cos(M_PI * h.angle / 180) *h.move_speed*factor;
	return h;
}

Hunter back(Hunter h, float mouseZ) {
	int factor = 1;
	if (mouseZ < 0) factor = -1;
	h.pos[0] -= sin(M_PI * h.angle / 180) *h.move_speed*factor;
	h.pos[2] -= cos(M_PI * h.angle / 180) *h.move_speed*factor;
	return h;
}

Hunter right(Hunter h, float mouseZ) {
    	int factor = 1;
	if (mouseZ < 0) factor = -1;
	h.pos[0] += sin(M_PI * h.angle / 180) *h.move_speed*factor;
	h.pos[2] -= cos(M_PI * h.angle / 180) *h.move_speed*factor;
	return h;
}

Hunter left(Hunter h, float mouseZ) {
	int factor = 1;
	if (mouseZ < 0) factor = -1;
	h.pos[0] -= sin(M_PI * h.angle / 180) *h.move_speed*factor;
	h.pos[2] += cos(M_PI * h.angle / 180) *h.move_speed*factor;
	return h;
}

int isHunterDead(Hunter h){
	if (h.hp <= 0) return 1;
	else return 0;
}
