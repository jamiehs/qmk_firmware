#pragma once

#include "quantum.h"


#define KEYMAP( \
	k00, k01, k02, k03, \
	k10, k11, k12, \
	k20, k22,      k23, \
	k30,        k32 \
) \
{ \
	{ k00, k01, k02, k03 }, \
	{ k10, k11, k12, KC_NO }, \
	{ k20, KC_NO, k22, k23 }, \
	{ k30, KC_NO, k32, KC_NO } \
}
