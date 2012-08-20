//
//  LevelMapLayer.cpp
//  CATLIEN
//
//  Created by Wander on 8/18/12.
//
//

#include "LevelMapLayer.h"
#include "AnimationTexture.h"
USING_NS_CC;

bool LevelMapLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    //CCSprite* mySprite = CCSprite::createWithSpriteFrameName("planet_1.png");
    //this->addChild(mySprite, 0);
    
    AnimationTexture* tex = AnimationTexture::createWithSpriteFrameName("planet_1.png");
    this->addChild(tex);
    
    this->removeChild(tex, true);
    
    return true;
}

