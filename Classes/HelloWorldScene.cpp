#include "HelloWorldScene.h"

USING_NS_CC;
#define NUM 10 

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
/*
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	//auto uiLayer = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("DemoLogin/DemoLogin.ExportJson");    
	
	//addChild(uiLayer);

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    

	 CCLayerGradient* layer1 = CCLayerGradient::create(ccc4(255, 0, 0, 255), ccc4(255, 0, 255, 255));
    layer1->setContentSize(CCSizeMake(80, 80));
    layer1->setPosition(ccp(50,50));
    addChild(layer1);

    CCLayerGradient* layer2 = CCLayerGradient::create(ccc4(0, 0, 0, 127), ccc4(255, 255, 255, 127));
    layer2->setContentSize(CCSizeMake(80, 80));
    layer2->setPosition(ccp(100,90));
    addChild(layer2);

    CCLayerGradient* layer3 = CCLayerGradient::create();
    layer3->setContentSize(CCSizeMake(80, 80));
    layer3->setPosition(ccp(150,140));
    layer3->setStartColor(ccc3(255, 0, 0));
    layer3->setEndColor(ccc3(255, 0, 255));
    layer3->setStartOpacity(255);
    layer3->setEndOpacity(255);
    ccBlendFunc blend;
    blend.src = GL_SRC_ALPHA;
    blend.dst = GL_ONE_MINUS_SRC_ALPHA;
    layer3->setBlendFunc(blend);
    addChild(layer3);

    return true;
}*/


void HelloWorld::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


bool HelloWorld::init()
{
    if (!Layer::init()){return false;}
    

	auto uiLayer = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("DemoUi_2/DemoUi_2.ExportJson");    
	
	addChild(uiLayer);
    Size screenSize=Director::getInstance()->getVisibleSize();
    Sprite *bg=Sprite::create("HelloWorld.png");
    bg->setPosition(screenSize.width/2,screenSize.height/2);
    bg->setOpacity(125);
    addChild(bg,2);
    
    //设置容器
    Layer* continerLayer = Layer::create();
    continerLayer->setContentSize(Size(NUM*200,200));//设置滚动区域的大小
    continerLayer->setPosition(Point(0,0));
    //添加button
    for (int i = 0; i<NUM; i++)
    {
        continerLayer->addChild(this->create9Sprite(i*200+100,100));
    }
    
    scrollView = ScrollView::create();
    
    scrollView->setViewSize(Size(600,200));//设置滚动试图的试图大小
    
    scrollView->setPosition(150,210);//设置位置  新的层默认左下角为原点


    
    scrollView->setContainer(continerLayer);//添加容器
    
    scrollView->setDirection(ScrollView::Direction::HORIZONTAL);//设置滑动方向
    
    scrollView->setDelegate(this);//注册
    
    this->addChild(scrollView);//添加
    
    
    
    //创建屏幕监听事件
    auto listener = EventListenerTouchOneByOne::create();
    //设置可向下传递
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    
    listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
    
    listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}


bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
    return true;
}

void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
    x = scrollView->getContentOffset().x;//x轴的偏移量
    CCLOG("%d",x);
}

void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
    // 关闭CCScrollView中的自调整
    scrollView->unscheduleAllSelectors();
    
    
    //矫正view的位置
    int offset =  x % 200;
    int num    =  x / 200;
    Point adjustPos;
    float adjustAnimDelay;//慢慢返回中间的位置需要的时间
//图片在几种特殊情况下的处理
    if (offset<=-100) {
        
        adjustPos = Point((num-1)*200,scrollView->getContentOffset().y);
        adjustAnimDelay=(offset*(-1)%100)/600;
    }
    
    if (offset<=0&&offset>-100) {
        
        adjustPos = Point(num*200,scrollView->getContentOffset().y);
        adjustAnimDelay=(offset*(-1)%100)/600;
    }
    
    if (offset>0) {
        
        adjustPos = Point(0,scrollView->getContentOffset().y);
        adjustAnimDelay=(offset*(1)%100)/600;
    }
    
    if (x<=-1400) {
        adjustPos = Point(-1400,scrollView->getContentOffset().y);
        adjustAnimDelay=(offset*(-1)%100)/600;
    }

    adjustAnimDelay=0.7;
    scrollView->setContentOffsetInDuration(adjustPos, adjustAnimDelay); // 调整位置
    
    
}

void HelloWorld::scrollViewDidScroll(ScrollView* view)
{
    return;
}

void HelloWorld::scrollViewDidZoom(ScrollView* view)
{
    return;
}
Node* HelloWorld::create9Sprite(float pWith,float pHeight)
{
    auto sprite9 = Scale9Sprite::create("button.png");
    
    LabelTTF *label = LabelTTF::create("Demo","",50);
    
    //创建按钮cb
    ControlButton* cb = ControlButton::create(sprite9);
    
     //setPreferredSize 就是设置需要生成的尺寸大小
    /* 强制设置按钮大小,如果按钮标题大小超过这个范围，则会自动扩大 */
    cb->setPreferredSize(Size(190, 190));
    cb->setPosition(Point(pWith, pHeight));
    
    return cb;
}