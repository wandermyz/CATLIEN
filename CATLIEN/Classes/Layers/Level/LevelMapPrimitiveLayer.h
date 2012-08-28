//
//  LevelMapPrimitiveLayer.h
//  CATLIEN
//
//  Created by Wander on 8/27/12.
//
//

#ifndef __CATLIEN__LevelMapPrimitiveLayer__
#define __CATLIEN__LevelMapPrimitiveLayer__

#include "cocos2d.h"
#include "../../GameObjects/GameObject.h"

class LevelMapPrimitiveLayer : public cocos2d::CCLayerColor
{
private:
    cocos2d::CCArray* _selections;
    
public:
    LAYER_CREATE_FUNC(LevelMapPrimitiveLayer);
    
    void selectElement(GameObject* gameObject);
    void deselectElement(GameObject* gameObject);
    void deselectAll();
    
    inline cocos2d::CCArray* getSelections() { return _selections; }
    
    virtual void draw();
    virtual bool init();
    virtual void onExit();
};

#endif /* defined(__CATLIEN__LevelMapPrimitiveLayer__) */
