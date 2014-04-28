#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Layer3 :
	public Layer
{
public:
	Layer3(void);
	~Layer3(void);

	CREATE_FUNC(Layer3);

	virtual bool init();
};

