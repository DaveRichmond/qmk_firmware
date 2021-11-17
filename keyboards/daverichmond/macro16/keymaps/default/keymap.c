#include QMK_KEYBOARD_H

enum layers {
	_SEL_L,
	_MACRO_L,
	_MOUSE_L,
	_BTN_L,
	_LED_L,
	_F_L
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_SEL_L] = LAYOUT(
			KC_NO, KC_NO, KC_NO, DF(_SEL_L),
			DF(_MOUSE_L), DF(_MACRO_L), DF(_F_L), DF(_BTN_L),
			DF(_LED_L), KC_NO, KC_NO, KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO),
	[_MACRO_L] = LAYOUT(
			KC_NO, KC_NO, KC_NO, DF(_SEL_L),
			DM_REC1, DM_REC2, DM_PLY1, DM_PLY2,
			KC_NO, KC_NO, KC_NO, KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO),
	[_MOUSE_L] = LAYOUT(
			KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, DF(_SEL_L),
			KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_BTN3,
			KC_NO, KC_MS_WH_UP, KC_NO, KC_NO,
			KC_MS_WH_RIGHT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_NO),
	[_BTN_L] = LAYOUT(
			KC_ESC, KC_W, KC_NO, DF(_SEL_L),
			KC_A, KC_S, KC_D, KC_NO,
			KC_NO, KC_UP, KC_NO, KC_NO,
			KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO),
	[_LED_L] = LAYOUT(
			KC_NO, RGB_SAI, KC_NO, DF(_SEL_L),
			RGB_HUI, RGB_SAD, RGB_HUD, KC_NO,
			KC_NO, RGB_VAI, KC_NO, RGB_SPI,
			RGB_MODE_FORWARD, RGB_VAD, RGB_MODE_REVERSE, RGB_SPD),
	[_F_L] = LAYOUT(
			KC_F1, KC_F2, KC_F3, DF(_SEL_L),
			KC_F4, KC_F5, KC_F6, KC_F7,
			KC_F8, KC_F9, KC_F10, KC_F11,
			KC_F12, KC_F13, KC_F14, KC_F15),
};

void keyboard_post_init_user(void){
	debug_enable = true;
	debug_matrix = true;
	debug_keyboard = true;
	debug_mouse = true;
}

#ifdef OLED_DRIVER_ENABLE
static void render_oled(void){
	oled_write_P(PSTR("Macro16\n"), false);
	oled_write_ln_P(PSTR("CAPS"), host_keyboard_led_state().caps_lock);
	oled_write_P(PSTR(" "), false);
	oled_write_ln_P(PSTR("NUM"), host_keyboard_led_state().num_lock);
	oled_write_P(PSTR(" "), false);
	oled_write_ln_P(PSTR("SCROLL"), host_keyboard_led_state().scroll_lock);
	oled_write_P(PSTR("\n"), false);
	oled_write_P(PSTR("Layer: "), false);
	switch(get_highest_layer(layer_state)){
		case _SEL_L: oled_write_P(PSTR("Select"), false); break;
		case _MOUSE_L: oled_write_P(PSTR("Mouse"), false); break;
		case _MACRO_L: oled_write_P(PSTR("Macro"), false); break;
		case _F_L: oled_write_P(PSTR("F Key"), false); break;
		case _BTN_L: oled_write_P(PSTR("Button"), false); break;
		case _LED_L: oled_write_P(PSTR("LED"), false); break;
		default: oled_write_P(PSTR("Unknown"), false); break;
	}
};
oled_rotation_t oled_init_user(oled_rotation_t rotation){
	return OLED_ROTATION_180; // screen is 180 degrees by default
}
void oled_task_user(void){
	render_oled();
}
#endif
