//
//  AnimatableTexture.cpp
//  CATLIEN
//
//  Created by Wander on 8/19/12.
//
//

#include "AnimationTexture.h"
USING_NS_CC;

AnimationTexture* AnimationTexture::createWithSpriteFrameName(const char *spriteFrameName)
{
    AnimationTexture* res = new AnimationTexture();
    if (res && res->initWithSpriteFrameName(spriteFrameName))
    {
        res->autorelease();
        return res;
    }
    
    CC_SAFE_DELETE(res);
    
    return NULL;
}

AnimationTexture::AnimationTexture()
{
    CCLOG("AnimationTexture created");
}

AnimationTexture::~AnimationTexture()
{
    CCLOG("AnimationTexture cleaned up.");
}

bool AnimationTexture::initWithSpriteFrameName(const char *spriteFrameName)
{
    sprite = CCSprite::createWithSpriteFrameName(spriteFrameName);
    if (!sprite)
    {
        return false;
    }
    
    addChild(sprite);
    sprite->setPosition(ccp(0,0));
    sprite->setAnchorPoint(ccp(0,0));
    
    CCRect bb = sprite->boundingBox();
    
    setAnchorPoint(ccp(0.5, 0.5));
    setContentSize(sprite->getContentSize());
    
    return true;
}
