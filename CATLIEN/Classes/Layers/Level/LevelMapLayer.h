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
#include "../../GameObjects/Player.h"
#include "LevelMapPrimitiveLayer.h"

#define LEVEL_MAP_LAYER_PRIMITIVE_Z 100
#define LEVEL_MAP_LAYER_ELEMENTS_Z 0
#define LEVEL_MAP_LAYER_PLAYER_Z 10

class LevelMapLayer : public cocos2d::CCLayer
{
private:
    cocos2d::CCArray* _gameObjects;
    cocos2d::CCArray* _planets;
    Player* _player;
    LevelMapPrimitiveLayer* _primitiveLayer;
    
    void addPlayer();
public:
    LAYER_CREATE_FUNC(LevelMapLayer);
    
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();

    inline cocos2d::CCArray* getGameObjects() { return _gameObjects; }
    
    //for editor
    void addElement(GameObject* gameObject);
    void setElementPosition(GameObject* gameObject, cocos2d::CCPoint position);
    void removeElement(GameObject* gameObject);
    void randomizeElementPosition(GameObject* gameObject);
    
    //method forward
    inline void selectElement(GameObject* gameObject) { _primitiveLayer->selectElement(gameObject);}
    inline void deselectElement(GameObject* gameObject) { _primitiveLayer->deselectElement(gameObject); }
    inline void deselectAll() { _primitiveLayer->deselectAll(); }
    inline cocos2d::CCArray* getSelections() {return _primitiveLayer->getSelections(); }
    
    virtual void update(float deltaTime);
    
    inline Player* getPlayer() const {return _player;}
    inline cocos2d::CCArray* getPlanets() const { return _planets;}
};

#endif /* defined(__CATLIEN__LevelMapLayer__) */
