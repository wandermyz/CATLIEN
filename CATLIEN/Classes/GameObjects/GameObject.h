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
#include <string>

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

#define GAME_OBJECT_TYPE_FUNC(type) virtual std::string getType() const {return (type);}

class GameObject : public cocos2d::CCNode
{
private:
    
protected:
    std::string _name;

public:
    GameObject();
    
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool containsPoint(const cocos2d::CCPoint& p);
    virtual void drawSelection();
    
    virtual std::string getType() const = 0;
    
    inline std::string getName() const { return _name; }
    inline void setName(const std::string& name) {_name = name;}
};

#endif /* defined(__CATLIEN__GameObject__) */
