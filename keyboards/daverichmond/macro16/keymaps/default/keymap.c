#include QMK_KEYBOARD_H

enum layers {
	_BL,
	_FL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BL] = LAYOUT(
			KC_F1, KC_F2, KC_F3, KC_F4,
			KC_F5, KC_F6, KC_F7, KC_F8,
			KC_F9, KC_F10, KC_F11, KC_F12,
			KC_F13, KC_F14, KC_F15, KC_F16
		),
	[_FL] = LAYOUT(
			DM_REC1, DM_REC2, DM_PLY1, DM_PLY2,
			KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, DM_RSTP,
			KC_MS_WH_LEFT, KC_MS_UP, KC_MS_WH_RIGHT, KC_MS_WH_UP,
			KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN
		)
};

#ifdef OLED_DRIVER_ENABLE
static void render_oled(void){
	oled_write_P(PSTR("Macro16"), false);
};
oled_rotation_t oled_init_user(oled_rotation_t rotation){
	return rotation;
}
void oled_task_user(void){
	render_oled();
}
#endif
