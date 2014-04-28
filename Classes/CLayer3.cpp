#include "CLayer3.h"


Layer3::Layer3(void)
{
}


Layer3::~Layer3(void)
{
}

bool Layer3::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!Layer::init());

		Size visibleSize =Director::getInstance()->getVisibleSize();
		Point origin = Director::getInstance()->getVisibleOrigin();

		LabelTTF* pLabel = LabelTTF::create("Hello Layer3", "Arial", 30);

		// position the label on the center of the screen
		pLabel->setPosition(Point(origin.x + visibleSize.width/2,
			origin.y + visibleSize.height - pLabel->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(pLabel, 1);

		// add "HelloWorld" splash screen"
		Sprite* pSprite = Sprite::create("HelloWorld.png");

		// position the sprite on the center of the screen
		pSprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(pSprite, 0);
		bRet=true;
	} while (0);
	return bRet;
}