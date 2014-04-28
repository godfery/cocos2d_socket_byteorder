#ifndef _TESTSCENE_H_
#define  _TESTSCENE_H_

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

#include "CLayer1.h"
#include "CLayer2.h"
#include "CLayer3.h"
using namespace cocos2d;

class TestScene :public cocos2d::Layer
{
public:
	  virtual bool init();  
    
    static cocos2d::Scene* createScene();
    
    // implement the "static create()" method manually
    CREATE_FUNC(TestScene);
	void menuCallback(Object* pSender);

public:
	void onMenuSIOClientClicked(Object *sender);

private:
	Layer1* _layer1;
	Layer2* _layer2;
	Layer3* _layer3;
	int curLayerPos;

	LayerMultiplex* _layerMuticomplex;
};

#endif