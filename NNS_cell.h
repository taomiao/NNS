#pragma once
#ifndef NNS_CELL_H
#define NNS_CELL_H

#include<queue>
#include<math.h>

using namespace std;
#define H_P_signal 3
#define M_P_signal 2
#define L_P_signal 1
#define H_N_signal (-3)
#define M_N_signal (-2)
#define L_N_signal (-1)
#define MaxSignal 10


struct State{
	int life;
	int nextState(){
		life--;
		return life;
	}
};

class NNS_cell;

class Link{
public:	
	NNS_cell* next;
	int dist;
	int not_touch_count;
	Link(){
		next=NULL;
		dist=999999;
		not_touch_count=0;
	}
};

class NNS_cell
{
public:
	NNS_cell(void);
	~NNS_cell(void);
	State curState;
	unsigned int N_energy;
	unsigned int N_factor;
	unsigned int N_threshold;
	queue<int> S_queue;
	int Last_N_energy;
	Link links[256];
	int live();
	int recSignal(int s);
	int renewLinks();
};

#endif