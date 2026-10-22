/* 9 functions from 0x00426600 to 0x00427470, found by Ghidra. */
#include "common.h"

struct Frame_00426600 {
    unsigned short id;
    unsigned short unk_0x02;
};

struct Anim_00426600 {
    unsigned count;
    Frame_00426600 *frames;
    unsigned duration;
};

struct AnimState_00426600 {
    unsigned short frame;
    unsigned short index;
    float time;
    char reset;
};
