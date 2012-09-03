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

class Planet : public GameObject
{
protected:
    float _originalRadius;
    float _radius;
    float _density;
    
public:
    GAME_OBJECT_CREATE_FUNC(Planet);
    GAME_OBJECT_TYPE_FUNC(GameObjectTypePlanet);
    
    virtual bool init();
    virtual bool containsPoint(const cocos2d::CCPoint& p);
    virtual void drawSelection();
    virtual bool setTexturePath(const char *texturePath);
    
    inline float getRadius() {return _radius;}
    inline float getDensity() {return _density;}
    
    void setRadius(float radius);
    void setDensity(float density);
    
    virtual void createB2Body();
};

#endif /* defined(__CATLIEN__Planet__) */
