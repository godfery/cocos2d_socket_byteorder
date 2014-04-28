#include "TestScene.h"
#include "ODSocket.h"
#include "ByteArray.h"
Scene* TestScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TestScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
struct Data{
    unsigned short flgs; //2
    unsigned short len;  //2
    unsigned int no;     //4
    char content;
} Message;
bool TestScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	Size winSize = Director::getInstance()->getWinSize();
    
    const int MARGIN = 40;
    const int SPACE = 35;
    
    auto label = LabelTTF::create("SocketIO Extension Test", "Arial", 28);
    label->setPosition(Point(winSize.width / 2, winSize.height - MARGIN));
    addChild(label, 0);
    	
    auto menuRequest = Menu::create();
    menuRequest->setPosition(Point::ZERO);
    addChild(menuRequest);
    
    // Test to create basic client in the default namespace
    auto labelSIOClient = LabelTTF::create("SocketIO Client", "Arial", 22);
    auto itemSIOClient = MenuItemLabel::create(labelSIOClient, CC_CALLBACK_1(TestScene::onMenuSIOClientClicked, this));
	itemSIOClient->setPosition(Point(labelSIOClient->getContentSize().width / 2 + 5, winSize.height - MARGIN - SPACE));
    menuRequest->addChild(itemSIOClient);



    
	/*auto uiLayer = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("DemoLogin/DemoLogin.ExportJson");    
	
	addChild(uiLayer);

	*/

	/*_layer1=Layer1::create();
		_layer2=Layer2::create();
		_layer3=Layer3::create();

		_layerMuticomplex=LayerMultiplex::create(_layer1,_layer2,_layer3,NULL);
		this->addChild(_layerMuticomplex);

			Size visibleSize =Director::getInstance()->getVisibleSize();
		Point origin = Director::getInstance()->getVisibleOrigin();

		MenuItemImage *pCloseItem1 = MenuItemImage::create(
			"w_b.png",
			"w_b.png",
			CC_CALLBACK_1(TestScene::menuCallback,this));

		MenuItemImage *pCloseItem2 = MenuItemImage::create(
			"r_b.png",
			"r_b.png",
			CC_CALLBACK_1(TestScene::menuCallback,this));

		MenuItemImage *pCloseItem3 = MenuItemImage::create(
			"g_b.png",
			"g_b.png",
			CC_CALLBACK_1(TestScene::menuCallback,this));

		// create menu, it's an autorelease object
		pCloseItem1->setTag(0);
		pCloseItem2->setTag(1);
		pCloseItem3->setTag(2);
		Menu* pMenu = Menu::create(pCloseItem1, pCloseItem2, pCloseItem3, NULL);
		pMenu->alignItemsHorizontallyWithPadding(-1);
		pMenu->setPosition(visibleSize.width/2,25);
		this->addChild(pMenu, 1);*/

	return true;

}
struct HimiObject{
	int id;
   /* short len;
    short code;
    int   playerid;*/
	std::string name;
};
#define T(x) (((x&0xff)<<24)|((x&0xff00)<<8)|((x&0xff0000)>>8)|((x&0xff000000)>>24))
void TestScene::onMenuSIOClientClicked(Object *sender)
{
	//create a client by using this static method, url does not need to contain the protocol
	/*_sioClient = SocketIO::connect(*this, "ws://channon.us:3000");
	//you may set a tag for the client for reference in callbacks
	_sioClient->setTag("Test Client");

	//register event callbacks using the CC_CALLBACK_2() macro and passing the instance of the target class
	_sioClient->on("testevent", CC_CALLBACK_2(SocketIOTestLayer::testevent, this));
	_sioClient->on("echotest", CC_CALLBACK_2(SocketIOTestLayer::echotest, this));

	*/
	ODSocket cSocket; 
	cSocket.Init(); 
	cSocket.Create(AF_INET,SOCK_STREAM,0); 
	cSocket.Connect("127.0.0.1",9988); 
	char recvBuf[1024] = "\0"; 
	std::string testmsg="我你他---------fsdjfsdg324234324324324"; 
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) 
	//GBKToUTF8(testmsg,"gb2312","utf-8"); 
	#endif 

	/*Message info;
    info.flgs = htons(127);
    info.len = htons(11);// 这里写死了，实际是 包头 8 （2+2+4）再加包身 x；
    info.no = htonl(10001);
    memcpy((void*)&info.content,testmsg,strlen(testmsg));
    
	
	
	cSocket.Send(info.,strlen(testmsg.c_str())+1,1); */

	HimiObject per;
       /* per.len=8;
        per.code=789;
        per.playerid=123466;
		*/
	per.id=2312321;
	per.name="fdsfsdf";
//	cSocket.Send((const char*)&per,sizeof(per),0); 

	/*cSocket.Send(testmsg.c_str(),strlen(testmsg.c_str())+1,1); 
	cSocket.Recv(recvBuf,1024,0); 
	std::string rec_msg=std::string(recvBuf); 
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) 
	//GBKToUTF8(rec_msg,"utf-8","gb2312"); 
	#endif 
	//printf("%s",rec_msg);
	CCLog("%s",rec_msg.c_str());
	*/
	
	
/*	int i=T(5);
	byte bytes[20];
    bytes[0] = (byte) (0xff & i);  
    bytes[1] = (byte) ((0xff00 & i) >> 8);  
    bytes[2] = (byte) ((0xff0000 & i) >> 16);  
    bytes[3] = (byte) ((0xff000000 & i) >> 24);  

	i= T(strlen(testmsg.c_str()));
	bytes[4] = (byte) (0xff & i);  
    bytes[5] = (byte) ((0xff00 & i) >> 8);  
    bytes[6] = (byte) ((0xff0000 & i) >> 16);  
    bytes[7] = (byte) ((0xff000000 & i) >> 24);  
	
	byte * val = (byte * )testmsg.c_str();
	byte * srcByte = val + 0;
	byte * desByte = bytes + 8;
	memcpy(desByte, srcByte, strlen(testmsg.c_str()));
	
	cSocket.Send((const char*)&desByte,sizeof(desByte),0); 
	*/

	ByteArray byteArray(1000000);
	
	//byteArray._bytes = tb;
	byteArray.setEndian(BIG_ENDIAN, LIT_ENDIAN);
	//byteArray.writeNumber(1000);
	byteArray.writeNumber(5);
	//string str("string test");
	//byteArray.writeNumber(strlen(testmsg.c_str()));
	char * val = (char * )testmsg.c_str();
	byteArray.write4BChars(val);
	
	
	//byteArray.setEndian(LIT_ENDIAN, LIT_ENDIAN);

	

	cSocket.Send((const char*)byteArray._bytes,byteArray.writePosition,0); 
	//byte tb1[100];
	//needSend._bytes = tb1;
//	needSend.writeInt(byteArray.readNumber(byteArray._bytes));
//	needSend.writeBytes(byteArray._bytes,byteArray.readNumber(byteArray._bytes),0);

//	cSocket.Send((const char*)&needSend._bytes,sizeof(needSend._bytes),0); 
	
	
//	CCLog("%d",intVal);
	//CCMessageBox(rec_msg.c_str(),"recived data is:"); 
	cSocket.Close(); 
	cSocket.Clean(); 
}
void TestScene::menuCallback(Object* pSender)
{
	int item=((MenuItemImage*)pSender)->getTag();
	if (item!=curLayerPos)
	{
		_layerMuticomplex->switchTo(item);
		curLayerPos=item;
	}
}

/*

//============================================================================
// Name        : ByteArray.cpp
// Author      : RockyF
// Version     :
// Copyright   : TBS workshop
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <windows.h>
#include "ByteArray.h"
#include <iostream>
using namespace std;

int main() {
	ByteArray byteArray(1000000);
	//byteArray.setEndian(LIT_ENDIAN, LIT_ENDIAN);

	byteArray.writeNumber(1000);
	byteArray.writeBool(false);
	byteArray.writeChars("char test");
	string str("string test");
	byteArray.writeString(&str);

	int intVal;
	byteArray.readNumber(&intVal);
	cout<<intVal<<endl;

	bool bVal;
	byteArray.readBool(&bVal);
	cout<<bVal<<endl;

	char chars[100];
	byteArray.readChars(chars, 9);
	cout<<chars<<endl;

	string strOut = byteArray.readString();
	cout<<strOut<<endl;

	return 0;
}


*/