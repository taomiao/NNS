#pragma once
#include"NNS_cell.h"
#include<string>
using namespace std;
#define MaxCellCount 65535
class NNS_feel_layer
{
public:
	NNS_feel_layer(void);
	~NNS_feel_layer(void);
	string buf[3];//[0]����һ����,[1]�е�ǰ��,[2]����һ����
	NNS_cell* cellNet[MaxCellCount];
	int cellCount;
	int getFeeling();
};

