#include "LoadingScene.h"
#include "HelloWorldScene.h"

CLoadingScene::CLoadingScene(void)
{
	 CCScene::init();
}

CLoadingScene::~CLoadingScene(void)
{
}

void CLoadingScene::onEnter()
{
	CCScene::onEnter();

	//add the menu item for back to main menu

	CCLabelTTF* label = CCLabelTTF::labelWithString("Start Game", "Arial", 20);

	CCMenuItemLabel* pMenuItem = CCMenuItemLabel::itemWithLabel(label, this, menu_selector(CLoadingScene::StartGameCallback));

	CCMenu* pMenu =CCMenu::menuWithItems(pMenuItem, NULL);
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	pMenu->setPosition( CCPointZero );
	pMenuItem->setPosition(ccp(s.width / 2, s.height / 2));

	addChild(pMenu, 1);
}

void CLoadingScene::StartGameCallback( CCObject* pSender )
{
	CCScene* pScene = CCScene::node();
	CCLayer* pLayer = new HelloWorld();
	pLayer->autorelease();

	pScene->addChild(pLayer);
	CCDirector::sharedDirector()->replaceScene(pScene);
}