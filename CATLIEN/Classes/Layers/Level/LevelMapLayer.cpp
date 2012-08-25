//
//  LevelMapLayer.cpp
//  CATLIEN
//
//  Created by Wander on 8/18/12.
//
//

#include "LevelMapLayer.h"
#include "AnimationTexture.h"
USING_NS_CC;

bool LevelMapLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    

    editorLayer = LevelEditorLayer::create();
    this->addChild(editorLayer);

    /*AnimationTexture* tex = AnimationTexture::createWithSpriteFrameName("planet_1.png");
    tex->setPosition(ccp(0,0));
    this->addChild(tex);*/
    //editorLayer->addChild(tex);
    
    return true;
}

