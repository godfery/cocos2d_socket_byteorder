#ifndef _MAINSCENE1_H_
#define  _MAINSCENE1_H_
#include "cocos2d.h"
#include "CLayer1.h"
#include "CLayer2.h"
#include "CLayer3.h"

#include "extensions/cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;
//using namespace cocos2d;
class MainScene1 :public cocos2d::Scene ,public ScrollViewDelegate
{
public:
	
	MainScene1(void);
	~MainScene1(void);
	virtual bool init();
	CREATE_FUNC(MainScene1);
	

	void menuCallback(Object* pSender);

private:
	Layer1* _layer1;
	Layer2* _layer2;
	Layer3* _layer3;
	int curLayerPos;

	LayerMultiplex* _layerMuticomplex;


private:
    //ScrollView中必须实现的2个虚函数方法
    virtual void scrollViewDidScroll(ScrollView* view);
    
    virtual void scrollViewDidZoom(ScrollView* view);

	 bool onTouchBegan(Touch* touch, Event* event);//触摸开始方法
    
    void onTouchMoved(Touch* touch, Event* event);//触摸移动方法
    
    void onTouchEnded(Touch* touch, Event* event);//触摸结束方法

public:
   // void AddSprite(CCSprite* pSprite);           // 添加用于滑屏显示的精灵
    bool IsMoveLayer()  { return m_bMoveLayer; } // 用于判断是否手指滑动了

private:
    Point m_ptTouchDown;      // 首次按下的触摸点

	 bool m_bMoveLayer;          // 移动层
};
#endif

