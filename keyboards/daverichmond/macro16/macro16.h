#pragma once

#include "quantum.h"

/* Layout: 4x4 Matrix */

#define LAYOUT( \
	k00, k01, k02, k03, \
	k04, k05, k06, k07, \
	k08, k09, k10, k11, \
	k12, k13, k14, k15 \
) { \
	{ k00, k01, k02, k03 }, \
	{ k04, k05, k06, k07 }, \
	{ k08, k09, k10, k11 }, \
	{ k12, k13, k14, k15 } \
}
