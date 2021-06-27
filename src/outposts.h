#ifndef OUTPOSTS_H
#define OUTPOSTS_H

#include "eval.h"

//various OUTPOSTS PSQT are defined here

/**
 * @brief [color][sqv] 
 */ 

const int KNIGHT_PROT_OUTPOST_BLACK[64] = {
           gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0),
           gS(0,3), gS(7,5), gS(0,4), gS(0,-1), gS(17,0), gS(0,3), gS(0,0), gS(0,0),
           gS(24,17), gS(7,33), gS(23,18), gS(21,20), gS(10,30), gS(36,22), gS(29,37), gS(31,10),
           gS(12,12), gS(25,17), gS(26,22), gS(26,27), gS(36,33), gS(34,28), gS(41,22), gS(15,18),
           gS(10,11), gS(18,12), gS(26,13), gS(35,15), gS(35,15), gS(29,8), gS(21,11), gS(12,8),
           gS(-4,3), gS(0,-1), gS(-2,-2), gS(3,-2), gS(4,-2), gS(-4,0), gS(-5,0), gS(-8,2),
           gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0),
           gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0),
};

const int BISHOP_PROT_OUTPOST_BLACK[64] = {
           gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,-5), gS(0,0), gS(0,0), gS(0,0),
           gS(0,1), gS(22,0), gS(10,-4), gS(0,-4), gS(1,-11), gS(2,0), gS(26,0), gS(0,-1),
           gS(-5,0), gS(29,1), gS(19,0), gS(37,0), gS(33,0), gS(62,-3), gS(34,11), gS(-10,0),
           gS(0,0), gS(27,6), gS(36,0), gS(41,5), gS(43,3), gS(42,6), gS(30,13), gS(0,6),
           gS(-6,0), gS(33,5), gS(37,1), gS(43,2), gS(44,6), gS(36,4), gS(33,5), gS(-8,0),
           gS(0,5), gS(9,11), gS(5,9), gS(10,10), gS(9,4), gS(0,0), gS(11,7), gS(-4,0),
           gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0),
           gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0),
};

const int KNIGHT_OUTPOST_BLACK[64] = {
           gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0),
           gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0),
           gS(8,-5), gS(9,0), gS(11,0), gS(18,2), gS(8,0), gS(31,-2), gS(22,1), gS(-8,0),
           gS(3,1), gS(11,1), gS(24,3), gS(40,3), gS(45,4), gS(39,6), gS(26,1), gS(11,8),
           gS(1,-2), gS(9,-1), gS(17,2), gS(20,11), gS(29,4), gS(22,-3), gS(10,-1), gS(6,1),
           gS(-3,0), gS(4,5), gS(5,9), gS(3,10), gS(3,14), gS(2,13), gS(8,0), gS(0,4),
           gS(-15,-2), gS(-2,2), gS(-10,17), gS(-5,8), gS(-1,2), gS(-10,11), gS(0,1), gS(-13,0),
           gS(-3,0), gS(-8,0), gS(-9,7), gS(-8,1), gS(-7,0), gS(-5,0), gS(-1,0), gS(-7,0),
};

const int BISHOP_OUTPOST_BLACK[64] = {
           gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0),
           gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0), gS(0,0),
           gS(2,-8), gS(13,-12), gS(15,0), gS(18,0), gS(6,0), gS(27,0), gS(10,0), gS(-9,1),
           gS(12,-2), gS(14,-3), gS(22,1), gS(33,1), gS(27,0), gS(27,0), gS(20,0), gS(9,0),
           gS(5,-1), gS(12,-5), gS(18,2), gS(25,3), gS(28,5), gS(24,1), gS(18,0), gS(3,0),
           gS(3,4), gS(2,8), gS(3,4), gS(6,7), gS(5,8), gS(0,4), gS(0,5), gS(-3,3),
           gS(-6,2), gS(-3,2), gS(-2,8), gS(-1,7), gS(1,7), gS(-2,1), gS(2,0), gS(-5,1),
           gS(5,5), gS(-4,16), gS(-1,3), gS(0,7), gS(0,4), gS(-8,0), gS(-2,6), gS(1,2),
};
#endif