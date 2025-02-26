#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT_5x6( \
    L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35, \
         L41, L42, L43, L44,                                    R41, R42, R43, R44, \
                                  L50, L55,      R50, R55,     \
                                       L54,      R51,          \
                             L53, L52, L51,      R54, R53, R52 \
) { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { XXX, L41, L42, L43, L44, XXX }, \
    { L50, L51, L52, L53, L54, L55 }, \
\
    { R00, R01, R02, R03, R04, R05 }, \
    { R10, R11, R12, R13, R14, R15 }, \
    { R20, R21, R22, R23, R24, R25 }, \
    { R30, R31, R32, R33, R34, R35 }, \
    { XXX, R41, R42, R43, R44, XXX }, \
    { R50, R51, R52, R53, R54, R55 } \
}
