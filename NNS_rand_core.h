#pragma once
#ifndef NNS_RAND_CORE_H
#define NNS_RAND_CORE_H
#include"NNS_cell.h"
#include<queue>
#define MaxCellCount 65535
#define InCellCount 1
#define OutCellCount 1
class NNS_rand_core
{
public:
	NNS_rand_core(void);
	~NNS_rand_core(void);
	int cellCount;

	NNS_cell* cellNet[MaxCellCount];
	NNS_cell* inCell[InCellCount];
	NNS_cell* outCell[OutCellCount];
	int infoIn(int info);
	int infoOut();
	void live();

};
#endif
