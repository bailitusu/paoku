//
//  Entity.cpp
//  PaoKu
//
//  Created by zc on 14-10-12.
//
//

#include "Entity.h"

Entity::Entity() {
    msprite = NULL;
}

CCSprite* Entity::getSprite() {
    return this->msprite;
}

void Entity::bindSprite(CCSprite *sprite) {
    this->msprite = sprite;
    this->addChild(msprite);
}