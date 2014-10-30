//
//  Player.cpp
//  PaoKu
//
//  Created by zc on 14-10-12.
//
//

#include "Player.h"

Player::Player() {
    mHP = 1000;
    jumpTimes=0;
}

bool Player::init() {
    return true;
}

void Player::jump() {
    if (getSprite() == NULL) {
        return;
    }
    if (jumpTimes>1) {
        return;
    }
    jumpTimes++;
    
    CCJumpBy* jump = CCJumpBy::create(3.0f, ccp(0, 0), 200, 1);
    CCCallFunc* func = CCCallFunc::create(this, callfunc_selector(Player::jumpEnd));
    CCActionInterval* jumpAct = CCSequence::create(jump,func,NULL);
    getSprite()->runAction(jumpAct);
}

void Player::jumpEnd() {
    if(isJumping()==false){
        jumpTimes=0;
    }
}

bool Player::isJumping() {
    if(getSprite()==NULL){
        return false;
    }
    
    CCPoint spPosition = getSprite()->getPosition();
    if(spPosition.y<10)
        return false;
    else
        return true;
}


void Player::hit(){
    if (getSprite() == NULL) {
        return;
    }
    FlowWord* word = FlowWord::create();
    this->addChild(word);
    word->showWord("-15", getSprite()->getPosition());
    
    mHP = mHP-15;
    if (mHP<0) {
        mHP = 0;
    }
    
    
}

int Player::getHP() {
    return this->mHP;
}

CCRect Player::getBoundBox(){
    if (getSprite()==NULL) {
        return CCRectMake(0, 0, 0, 0);
    }
    CCSize spriteSize = getSprite()->getContentSize();
    CCPoint spPos =getSprite()->getPosition();

//    std::cout << spPos.y<< std::endl;
    //这里坐标有问题，getSprite()->getPosition()获取的是坐标是精灵自己的坐标为（0，0），getPosition（）获取的是精灵设置时候的坐标（但用这个无法获取JumpBy函数精灵跳起来后的坐标）
    return CCRectMake(spPos.x-spriteSize.width/2+200, spPos.y-spriteSize.height/2+160, spriteSize.width, spriteSize.height);
}
