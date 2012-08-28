//
//  LevelMapPrimitiveLayer.cpp
//  CATLIEN
//
//  Created by Wander on 8/27/12.
//
//

#include "LevelMapPrimitiveLayer.h"
USING_NS_CC;

bool LevelMapPrimitiveLayer::init()
{
    if (!CCLayerColor::init())
    {
        return false;
    }
    
    _selections = CCArray::create();
    _selections->retain();
    
    return true;
}

void LevelMapPrimitiveLayer::onExit()
{
    _selections->removeAllObjects();
    _selections->release();
    CCLayerColor::onExit();
}

void LevelMapPrimitiveLayer::selectElement(GameObject *gameObject)
{
    if (!_selections->containsObject(gameObject))
    {
        _selections->addObject(gameObject);
    }
}

void LevelMapPrimitiveLayer::deselectElement(GameObject *gameObject)
{
    if (_selections->containsObject(gameObject))
    {
        _selections->addObject(gameObject);
    }
}

void LevelMapPrimitiveLayer::deselectAll()
{
    _selections->removeAllObjects();
}

void LevelMapPrimitiveLayer::draw()
{
    for (int i = 0; i < _selections->count(); i++)
    {
        GameObject* obj = (GameObject*)_selections->data->arr[i];
        obj->drawSelection();
    }
}
