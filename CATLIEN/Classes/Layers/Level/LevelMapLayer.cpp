//
//  LevelMapLayer.cpp
//  CATLIEN
//
//  Created by Wander on 8/18/12.
//
//

#include "LevelMapLayer.h"
#include "AnimationTexture.h"
#include "GlobalEngine.h"
USING_NS_CC;

bool LevelMapLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    /*AnimationTexture* tex = AnimationTexture::createWithSpriteFrameName("planet_1.png");
    tex->setPosition(ccp(0,0));
    this->addChild(tex);*/
    //editorLayer->addChild(tex);
    
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    return true;
}

bool LevelMapLayer::ccTouchBegan(CCTouch *touch, CCEvent *event)
{
    return true;
}

void LevelMapLayer::ccTouchMoved(CCTouch *touch, CCEvent *event)
{
    
}

void LevelMapLayer::ccTouchEnded(CCTouch *touch, CCEvent *event)
{
    GlobalEngine::sharedGlobalEngine()->getLevelEditorHandler()->showCreatingMenu();
}
