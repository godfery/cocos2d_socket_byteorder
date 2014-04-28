#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "extensions/cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;



class HelloWorld : public cocos2d::Layer,public ScrollViewDelegate
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(Object* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);



private:
    //ScrollView中必须实现的2个虚函数方法
    virtual void scrollViewDidScroll(ScrollView* view);
    
    virtual void scrollViewDidZoom(ScrollView* view);
    
    Node* create9Sprite(float pWith,float pHeight);//创建9妹精灵
    
    bool onTouchBegan(Touch* touch, Event* event);//触摸开始方法
    
    void onTouchMoved(Touch* touch, Event* event);//触摸移动方法
    
    void onTouchEnded(Touch* touch, Event* event);//触摸结束方法
    
private:
    
    
    int x;        //scrollView的当前横坐标
    
    ScrollView *scrollView;
};

#endif // __HELLOWORLD_SCENE_H__
