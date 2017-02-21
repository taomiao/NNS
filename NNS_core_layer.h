#pragma once
#include"NNS_rand_core.h"
#include"NNS_logic_core.h"
class NNS_core_layer
{
public:
	NNS_core_layer(void);
	~NNS_core_layer(void);
	NNS_rand_core r_core;
	NNS_logic_core l_core;
};

