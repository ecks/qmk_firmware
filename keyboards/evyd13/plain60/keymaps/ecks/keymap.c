#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum _layer {
  _QWERTY,
  _DVORAK,
  _FN
};

enum my_keycodes {
    M_TABBS = SAFE_RANGE,
    QWERTY,
    DVORAK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
  KC_GRAVE,       KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  \
  M_TABBS,        KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          \
  CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, _______, KC_ENT,           \
  KC_LSPO,        _______, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, MO(_FN),   \
  _______,        KC_LGUI, KC_LALT,                 KC_SPC,                                  _______, KC_RALT, KC_RGUI, _______),

[_DVORAK] = LAYOUT(
  KC_GRAVE,       KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  \
  M_TABBS,        KC_QUOT, KC_COMM, KC_DOT, KC_P,   KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS,          \
  CTL_T(KC_ESC),  KC_A,    KC_O,    KC_E,   KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,    KC_S,    KC_MINS, _______, KC_ENT,           \
  KC_LSPO,        _______, KC_SCLN, KC_Q,   KC_J,   KC_K,   KC_X,   KC_B,   KC_M,   KC_W,    KC_V,    KC_Z, KC_RSPC,    MO(_FN),   \
  _______,        KC_LGUI, KC_LALT,                 KC_SPC,                                  _______, KC_RALT, KC_RGUI, _______),

[_FN] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, _______, \
  KC_BSPC, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______, KC_BSPC,    \
  _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______, KC_PENT,  \
  _______, _______, QWERTY,  DVORAK,  _______, _______, _______, _______, _______, KC_END,  KC_PGDN, KC_DOWN, _______, _______,  \
  _______, _______, _______,                            RESET,                              _______, _______, _______, _______)
};

// based on solution by TheTalljoe -- https://www.reddit.com/r/olkb/comments/4u36wk/qmk_question_how_do_i_make_backspace_send_delete/
uint16_t lastcode = KC_NO;

bool process_record_user(uint16_t keycode, keyrecord_t *record){
	switch(keycode) {
		case M_TABBS: {// layer 0
            uint16_t kc = KC_TAB;
			if(record->event.pressed){
				if(get_mods() & MOD_MASK_SHIFT) {
					kc = KC_BSPC;
                }

			    register_code(kc);
                lastcode = kc;
			} else {
				unregister_code(lastcode);
			}
			return false;
        }
        case QWERTY:
			if(record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case DVORAK:
			if(record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
    }
	return true;
}
