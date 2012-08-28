//
//  LevelMapLayer.h
//  CATLIEN
//
//  Created by Wander on 8/18/12.
//
//

#ifndef __CATLIEN__LevelMapLayer__
#define __CATLIEN__LevelMapLayer__

#include "cocos2d.h"
#include "../../GameObjects/GameObject.h"
#include "LevelMapPrimitiveLayer.h"

#define LEVEL_MAP_LAYER_PRIMITIVE_Z 100
#define LEVEL_MAP_LAYER_ELEMENTS_Z 0

class LevelMapLayer : public cocos2d::CCLayer
{
private:
    cocos2d::CCArray* _gameObjects;
    LevelMapPrimitiveLayer* _primitiveLayer;
    
public:
    LAYER_CREATE_FUNC(LevelMapLayer);
    
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();

    inline cocos2d::CCArray* getGameObjects() { return _gameObjects; }
    
    //for editor
    void addElement(GameObject* gameObject);
    void setElementPosition(GameObject* gameObject, cocos2d::CCPoint position);
    void randomizeElementPosition(GameObject* gameObject);
    
    //method forward
    inline void selectElement(GameObject* gameObject) { _primitiveLayer->selectElement(gameObject);}
    inline void deselectElement(GameObject* gameObject) { _primitiveLayer->selectElement(gameObject); }
    inline void deselectAll() { _primitiveLayer->deselectAll(); }
    inline cocos2d::CCArray* getSelections() {return _primitiveLayer->getSelections(); }
};

#endif /* defined(__CATLIEN__LevelMapLayer__) */
