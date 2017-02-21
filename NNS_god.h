#pragma once
#ifndef NNS_GOD_H
#define NNS_GOD_H

#include<map>
#include"NNS_cell.h"

class NNS_god
{
public:
	NNS_god(void);
	~NNS_god(void);
	unsigned long tick_count;
	
	int onTimer();
	int start();

	pair<NNS_cell* , int> findMyNeibor( NNS_cell* cell );//Ñ°ÕÒ¸½½ü×î»îÔ¾cell
};

#endif