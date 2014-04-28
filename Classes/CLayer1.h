#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Layer1 :
	public Layer
{
public:
	Layer1(void);
	~Layer1(void);

	CREATE_FUNC(Layer1);

	virtual bool init();
};


