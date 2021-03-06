//
//  LevelScene.cpp
//  CATLIEN
//
//  Created by Wander on 8/18/12.
//
//

#include "LevelScene.h"

USING_NS_CC;

bool LevelScene::init() {
    if (!CCScene::init()) {
        return false;
    }
    
    levelMapLayer = LevelMapLayer::create();
    addChild(levelMapLayer);
    
    levelInfoLayer = LevelInfoLayer::create();
    addChild(levelInfoLayer);
    
    return true;
}

void LevelScene::end() {
    
}