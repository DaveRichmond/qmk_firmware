#include "macro16.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
	{ NO_LED, NO_LED, NO_LED, NO_LED },
	{ NO_LED, NO_LED, NO_LED, NO_LED },
	{ NO_LED, NO_LED, NO_LED, NO_LED },
	{ NO_LED, NO_LED, NO_LED, NO_LED },
}, {
	{110, 29}, {111, 29}, {112, 29},
	{110, 30}, {111, 30}, {112, 30}, {113, 30}, {114, 30},
	{110, 31}, {111, 31}, {112, 31}, {113, 31}, {114, 31},
	{110, 32}, {111, 32}, {112, 32}, {113, 32}, {114, 32},
	{110, 33}, {111, 33}, {112, 33}, {113, 33}, {114, 33},
	{110, 34}, {111, 34}, {112, 34}, {113, 34}, {114, 34}
}, {
	LED_FLAG_INDICATOR, LED_FLAG_INDICATOR, LED_FLAG_INDICATOR,
	LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
	LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
	LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
	LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
	LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
} };

void rgb_matrix_indicators_kb(void){
	if(host_keyboard_led_state().caps_lock){
		rgb_matrix_set_color(0, 255, 0, 0);
	} else {
		rgb_matrix_set_color(0, 0, 0, 0);
	}
	if(host_keyboard_led_state().scroll_lock){
		rgb_matrix_set_color(1, 255, 0, 0);
	} else {
		rgb_matrix_set_color(1, 0, 0, 0);
	}
	if(host_keyboard_led_state().num_lock){
		rgb_matrix_set_color(2, 255, 0, 0);
	} else {
		rgb_matrix_set_color(2, 0, 0, 0);
	}
}

#endif
