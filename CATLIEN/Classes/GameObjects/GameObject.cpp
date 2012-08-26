//
//  GameObject.cpp
//  CATLIEN
//
//  Created by Wander on 8/19/12.
//
//

#include "GameObject.h"
USING_NS_CC;

GameObject::GameObject() : _name("")
{
}

bool GameObject::init()
{
    return true;
}

void GameObject::onEnter()
{
    CCNode::onEnter();
    
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void GameObject::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCNode::onExit();
}

bool GameObject::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    //return if in editor mode
    if (containsPoint(touch->getLocation()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void GameObject::ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    setPosition(ccpAdd(getPosition(), touch->getDelta()));
}

void GameObject::ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    
}

bool GameObject::containsPoint(const CCPoint& p)
{
    return boundingBox().containsPoint(p);
}
