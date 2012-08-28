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
}

void GameObject::onExit()
{
    CCNode::onExit();
}

bool GameObject::containsPoint(const CCPoint& p)
{
    return boundingBox().containsPoint(p);
}

void GameObject::drawSelection()
{
    ccDrawColor4B(255, 255, 255, 255);
    glLineWidth(3);
    CCRect rect = boundingBox();
    
    CCPoint vertices[] = {
        ccp(rect.getMinX(), rect.getMinY()),
        ccp(rect.getMaxX(), rect.getMinY()),
        ccp(rect.getMaxX(), rect.getMaxY()),
        ccp(rect.getMinX(), rect.getMaxY()) };
    ccDrawPoly( vertices, 4, true);
}