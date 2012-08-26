//
//  LevelMapLayer.cpp
//  CATLIEN
//
//  Created by Wander on 8/18/12.
//
//

#include "cocos2d.h"
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
    
    return true;
}

void LevelMapLayer::onEnter()
{
    CCLayer::onEnter();
    GlobalEngine::sharedGlobalEngine()->setLevelMapLayer(this);
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void LevelMapLayer::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
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

void LevelMapLayer::addElement(GameObject *gameObject)
{
    addChild(gameObject);
}

void LevelMapLayer::setElementPosition(GameObject *gameObject, cocos2d::CCPoint position)
{
    gameObject->setPosition(position);
}

void LevelMapLayer::randomizeElementPosition(GameObject *gameObject)
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCRect bb = gameObject->boundingBox();
    
    float minX = -bb.getMinX();
    float minY = -bb.getMinY();
    float maxX = winSize.width - bb.getMaxX();
    float maxY = winSize.height - bb.getMaxY();
    
    float x = minX + CCRANDOM_0_1() * (maxX - minX);
    float y = minY + CCRANDOM_0_1() * (maxY - minY);
    
    gameObject->setPosition(ccp(x, y));
}




