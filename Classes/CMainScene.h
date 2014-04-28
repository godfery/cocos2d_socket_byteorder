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
    //ScrollView�б���ʵ�ֵ�2���麯������
    virtual void scrollViewDidScroll(ScrollView* view);
    
    virtual void scrollViewDidZoom(ScrollView* view);

	 bool onTouchBegan(Touch* touch, Event* event);//������ʼ����
    
    void onTouchMoved(Touch* touch, Event* event);//�����ƶ�����
    
    void onTouchEnded(Touch* touch, Event* event);//������������

public:
   // void AddSprite(CCSprite* pSprite);           // ������ڻ�����ʾ�ľ���
    bool IsMoveLayer()  { return m_bMoveLayer; } // �����ж��Ƿ���ָ������

private:
    Point m_ptTouchDown;      // �״ΰ��µĴ�����

	 bool m_bMoveLayer;          // �ƶ���
};
#endif

