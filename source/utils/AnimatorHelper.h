#pragma once

#define CREATE_ANIMATOR(page, idx, numAnims) (_this->createAnimator(idx, _this->mMainControl, numAnims))
#define BIND_ANIM(animator, idx, str) (animator->bind(idx, str))