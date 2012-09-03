//
//  GameObject.h
//  CATLIEN
//
//  Created by Wander on 8/19/12.
//
//

#ifndef __CATLIEN__GameObject__
#define __CATLIEN__GameObject__

#include "cocos2d.h"
#include "Box2D.h"
#include "../Graphics/AnimationTexture.h"
#include <string>

// GameObject types
typedef enum
{
    GameObjectTypeNone,
    GameObjectTypePlanet,
    GameObjectTypePlayer
} GameObjectType;

// for the subclass of GameObject, each has to implement the static "create" method
#define GAME_OBJECT_CREATE_FUNC(clz) \
static clz* create() \
{ \
clz *pRet = new clz(); \
if (pRet && pRet->init()) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
CC_SAFE_DELETE(pRet); \
pRet = NULL; \
return NULL; \
} \
}

#define GAME_OBJECT_TYPE_FUNC(type) virtual GameObjectType getType() const {return (type);}

class GameObject : public cocos2d::CCNode
{
private:
    
protected:
    std::string _name;
    std::string _texturePath;
    int _frameCount;
    cocos2d::CCNode* _texture;
    b2Body* _b2Body;

public:
    GameObject();
    
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool containsPoint(const cocos2d::CCPoint& p);
    virtual void drawSelection();
    
    virtual GameObjectType getType() const = 0;
    
    inline std::string getName() const { return _name; }
    inline void setName(const std::string& name) {_name = name;}
    
    std::string getTexturePath() {return _texturePath;}
    int getFrameCount() {return _frameCount;}
    
    //return true if the texture is changed. 
    virtual bool setTexturePath(const char* texturePath);
    virtual void setFrameCount(int frameCount);
    
    virtual void createB2Body();
    virtual void destroyB2Body();
    virtual void update(float deltaTime);
    
    void resetB2Body();
};

#endif /* defined(__CATLIEN__GameObject__) */
