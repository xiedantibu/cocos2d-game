#include "HelloWorldScene.h"
#pragma warning (disable:4996)
using namespace cocos2d;

#define kTopScale 0.8f
#define kGlassScale 0.5f

#define kLabelTopStart  470.0f
#define kLabelBottomEnd  10.0f
#define kLabelLeft  80.0f

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::node();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::node();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    CCLayer::init();
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite* bg = CCSprite::spriteWithFile("data/bg.png");
	CCSize bgSize = bg->getContentSize();
	bg->setAnchorPoint(ccp(0, 0));
	bg->setScaleX(winSize.width / bgSize.width);
	bg->setScaleY(winSize.height / bgSize.height);
	bg->setPosition(ccp(0, 0));
	this->addChild(bg, -1);

	CCSprite* top = CCSprite::spriteWithFile("sm/top.png");
	CCSize imageSize = top->getContentSize();
	top->setAnchorPoint(ccp(0, 0));
	top->setScaleX(winSize.width / imageSize.width);
	top->setScaleY(kTopScale);
	top->setPosition(ccp(0, 0));
	this->addChild(top, 4);
	CCSprite* bottom = CCSprite::spriteWithFile("sm/top.png");
	bottom->setFlipY(true);
	bottom->setAnchorPoint(ccp(0, 0));
	bottom->setScaleX(winSize.width / imageSize.width);
	bottom->setScaleY(kTopScale);
	bottom->setPosition(ccp(0, winSize.height - imageSize.height * kTopScale));
	this->addChild(bottom, 4);


	CCSprite* topg = CCSprite::spriteWithFile("sm/glass.png");
	CCSize imageGlassSize = topg->getContentSize();
	topg->setAnchorPoint(ccp(0, 0));
	topg->setScaleX((winSize.width - 30) / imageGlassSize.width);
	topg->setScaleY(kGlassScale);
	topg->setPosition(ccp(15, imageSize.height * kTopScale - 10));
	this->addChild(topg, 3);

	CCSprite* bottomg = CCSprite::spriteWithFile("sm/glass.png");
	bottomg->setFlipY(true);
	bottomg->setAnchorPoint(ccp(0, 0));
	bottomg->setScaleX((winSize.width - 30) / imageGlassSize.width);
	bottomg->setScaleY(kGlassScale);
	bottomg->setPosition(ccp(15, winSize.height - imageSize.height * kTopScale - imageGlassSize.height * kGlassScale + 10));
	this->addChild(bottomg, 3);


	CCMenuItemImage* start = CCMenuItemImage::itemFromNormalImage("sm/startn.png", "sm/startc.png", "sm/startd.png", this, menu_selector(HelloWorld::menuCallbackPlay));
	start->setScaleX(0.6f);
	start->setScaleY(0.6f);
	CCSize startSize = start->getContentSize();
	CCMenu* menu  = CCMenu::menuWithItem(start);
	menu->setPosition(ccp(winSize.width  / 2, startSize.height / 2 - 10));
	this->addChild(menu, 10);

	float height = kLabelTopStart;

	for (int i = 0; i < LABEL_COUNT; ++i) {
		m_labelBg[i] = CCSprite::spriteWithFile("sm/labelbg.png");
		this->addChild(m_labelBg[i], 0);

		CCSize size = m_labelBg[i]->getContentSize();
		m_labelBg[i]->setPosition(ccp(winSize.width / 2, height - size.height / 2));
		m_labelBg[i]->setScaleX((imageGlassSize.width * kGlassScale - 30) / m_labelBg[i]->getContentSize().width);
		m_labelBg[i]->setScaleY(0.6f);

		height -= size.height / 2 + 10;
	}

	char text[128] = {0};
	for (int i = 0; i < LABEL_COUNT; ++i) {
		_snprintf(text, sizeof(text) - 1, "Test%d", i);
		m_label[i] = CCLabelTTF::labelWithString(text, "Zapfino", 18);
		this->addChild(m_label[i], 20);
	}

	m_focusLabel = CCSprite::spriteWithFile("sm/labelbgf.png");
	if (m_focusLabel) {
		m_focusLabel->setScaleX((imageGlassSize.width * kGlassScale - 30) / m_focusLabel->getContentSize().width);
		m_focusLabel->setScaleY(0.6f);
		m_focusLabel->setPosition(ccp(winSize.width / 2, winSize.height / 2));
		this->addChild(m_focusLabel, 1);
	}
	return true;
}

void HelloWorld::menuCallbackPlay(CCObject* pSender)
{

}

