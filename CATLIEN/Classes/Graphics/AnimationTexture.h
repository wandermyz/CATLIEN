//
//  AnimatableTexture.h
//  CATLIEN
//
//  Created by Wander on 8/19/12.
//
//

#ifndef __CATLIEN__AnimationTexture__
#define __CATLIEN__AnimationTexture__

#include "cocos2d.h"

class AnimationTexture: public cocos2d::CCNode
{
private:
    cocos2d::CCSprite* sprite;
    
public:
    static AnimationTexture* createWithSpriteFrameName(const char* spriteFrameName);
    //TODO: static AnimatableTexture* createWithSpriteFrameNameSequence(const char* spriteFrameNamePrefix, int start, int frameCount);
    //TODO: create with data file

    AnimationTexture();
    virtual ~AnimationTexture();

    bool initWithSpriteFrameName(const char* spriteFrameName);
    //TODO: void initWithSpriteFrameNameSequence(const char* spriteFrameNamePrefix, int start, int frameCount);
};

#endif /* defined(__CATLIEN__AnimationTexture__) */
