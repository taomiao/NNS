#include "NNS_rand_core.h"


NNS_rand_core::NNS_rand_core(void)
{
	for(int i=0;i<MaxCellCount;i++){
		cellNet[i]=NULL;
	}
	cellCount=3;
	for(int i=0;i<cellCount;i++){
		cellNet[i]=new NNS_cell();
	}
	for(int i=0;i<InCellCount;i++){
		inCell[i]=cellNet[i];
	}
	for(int i=0;i<OutCellCount;i++){
		outCell[i]=cellNet[cellCount-1-i];
	}
	for(int i=0;i<cellCount;i++){
		for(int j=0;j<cellCount;j++){
			if(i==j)
				continue;
			(cellNet[i]->links[j]).next=cellNet[j];
			(cellNet[i]->links[j]).dist=abs(i-j);
		}
	}	
}

NNS_rand_core::~NNS_rand_core(void)
{
	for(int i=0;i<cellCount;i++){
		delete cellNet[i];
	}
}

int NNS_rand_core::infoIn(int info){
	for(int i=0;i<InCellCount;i++){
		inCell[i]->S_queue.push(info);
	}	
	return 0;
}

int NNS_rand_core::infoOut(){
	for(int i=0;i<OutCellCount;i++){
		if(outCell[i]->Last_N_energy>(outCell[i]->N_threshold)){
			printf("%d ",outCell[i]->Last_N_energy);
		}
	}
	printf("\n");
	return 0;
}

void NNS_rand_core::live(){
	for(int i=0;i<cellCount;i++){
		cellNet[i]->live();
	}
}