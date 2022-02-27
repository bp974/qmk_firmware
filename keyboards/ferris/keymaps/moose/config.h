/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// Pick good defaults for enabling homerow modifiers
#define TAPPING_TERM 220
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TOGGLE 2
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD

#define LAYOUT_split_3x5_2( \
        L01, L02, L03, L04, L05, R05, R04, R03, R02, R01, \
        L06, L07, L08, L09, L10, R10, R09, R08, R07, R06, \
        L11, L12, L13, L14, L15, R15, R14, R13, R12, R11, \
                  L16, L17, R17, R16       \
    ) \
    { \
        { L01, L02, L03, L04, L05 }, \
        { L06, L07, L08, L09, L10 }, \
        { L11, L12, L13, L14, L15 }, \
        { L16, L17, ___, ___ , ___}, \
        { R01, R02, R03, R04, R05 }, \
        { R06, R07, R08, R09, R10 }, \
        { R11, R12, R13, R14, R15 }, \
        { R16, R17, ___, ___, ___ }  \
    }
