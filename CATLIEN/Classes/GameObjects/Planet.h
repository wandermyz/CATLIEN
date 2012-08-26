//
//  Planet.h
//  CATLIEN
//
//  Created by Wander on 8/19/12.
//
//

#ifndef __CATLIEN__Planet__
#define __CATLIEN__Planet__

#include "GameObject.h"
#include <string>

class Planet : public GameObject
{
protected:
    float _radius;
    float _density;
    std::string _texturePath;
    int _frameCount;
 
    cocos2d::CCNode* _texture;
    
public:
    GAME_OBJECT_CREATE_FUNC(Planet);
    GAME_OBJECT_TYPE_FUNC("Planet");
    
    virtual bool init();
    virtual bool containsPoint(const cocos2d::CCPoint& p);
};

#endif /* defined(__CATLIEN__Planet__) */
