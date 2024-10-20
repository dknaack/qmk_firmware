// Copyright 2021 david@impstyle.com (@zwnk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "layout.h"

#define GAME TG(4)

#define SYM_ENT LT(2, KC_ENT)
#define NUM_TAB LT(1, KC_TAB)
#define NAV_TAB LT(3, KC_TAB)
#define NAV_ENT LT(3, KC_ENT)

#define GUI_A    LGUI_T(KC_A)
#define ALT_S    LALT_T(KC_S)
#define SFT_D    LSFT_T(KC_D)
#define CTL_F    LCTL_T(KC_F)
#define CTL_J    RCTL_T(KC_J)
#define SFT_K    RSFT_T(KC_K)
#define ALT_L    RALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

#define GUI_1 LGUI_T(KC_1)
#define ALT_2 LALT_T(KC_2)
#define SFT_3 LSFT_T(KC_3)
#define CTL_4 LCTL_T(KC_4)
#define GUI_0 RGUI_T(KC_0)
#define ALT_9 RALT_T(KC_9)
#define SFT_8 RSFT_T(KC_8)
#define CTL_7 RCTL_T(KC_7)

const uint16_t PROGMEM semicolon_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM escape_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM backspace_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM caps_word_combo[] = {SFT_D, SFT_K, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_V, COMBO_END};
combo_t key_combos[] = {
    COMBO_ACTION(caps_word_combo),
    COMBO(semicolon_combo, KC_SCLN),
    COMBO(enter_combo, KC_ENT),
    //COMBO(escape_combo, KC_ESC),
    COMBO(backspace_combo, KC_BACKSPACE),
    COMBO(copy_combo, KC_COPY),
    COMBO(paste_combo, KC_PASTE),
};

void
process_combo_event(uint16_t combo_index, bool pressed)
{
    if (combo_index == 0 && pressed) {
        caps_word_toggle();
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_dknaack(
	     KC_HOME,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,		KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0    ,KC_END ,
	     KC_GRV ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,	 	KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P    ,QK_BOOT,
	     KC_BSLS,GUI_A  ,ALT_S  ,SFT_D  ,CTL_F  ,KC_G   ,	 	KC_H   ,CTL_J  ,SFT_K  ,ALT_L  ,GUI_SCLN,KC_QUOT,
	     KC_LBRC,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,	 	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH ,KC_MINS,
	     KC_RBRC,KC_NO  ,GAME   ,KC_VOLU,KC_MUTE,KC_NO  ,	 	KC_NO  ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RIGHT,KC_EQL ,
	  								     KC_ESC ,KC_LALT,       KC_DEL ,KC_TAB ,
	                                             KC_LGUI,       KC_PGUP,
								 KC_SPC ,NUM_TAB,KC_LCTL,       KC_PGDN,SYM_ENT, KC_BSPC
	),

    [1] = LAYOUT_dknaack(
	     _______,_______,_______,_______,_______,_______,		_______,_______,_______,_______,_______,_______,
	     _______,_______,_______,_______,_______,_______,	 	KC_PLUS,KC_7   ,KC_8   ,KC_9   ,KC_SLSH,_______,
	     _______,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______,	 	KC_MINS,KC_4   ,KC_5   ,KC_6   ,KC_ASTR,_______,
	     _______,_______,_______,_______,_______,_______,	 	KC_0   ,KC_1   ,KC_2   ,KC_3   ,KC_EQL ,_______,
	     _______,_______,_______,_______,_______,_______,	 	_______,_______,_______,_______,_______,_______,
	  								     _______,_______,       _______,_______,
	                                             _______,       _______,
								 _______,_______,_______,       _______,NAV_ENT,_______
    ),

    [2] = LAYOUT_dknaack(
	     KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,	 	KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
	     _______,KC_CIRC,KC_LT  ,KC_GT  ,KC_DLR ,KC_HASH,	 	KC_AMP ,KC_PERC,KC_LBRC,KC_RBRC,KC_GRV ,_______,
	     _______,KC_EXLM,KC_MINS,KC_PLUS,KC_UNDS,KC_QUOT,	 	KC_PIPE,KC_COLN,KC_LPRN,KC_RPRN,KC_SCLN,_______,
	     _______,KC_BSLS,KC_SLSH,KC_GT  ,KC_EQL ,KC_DQUO,	 	KC_TILD,KC_AT  ,KC_LCBR,KC_RCBR,KC_QUES,_______,
	     _______,_______,_______,_______,_______,_______,	 	_______,_______,_______,_______,_______,_______,
	  								     _______,_______,       _______,_______,
	                                             _______,       _______,
								 _______,NAV_TAB,_______,       _______,_______,_______
    ),

    [3] = LAYOUT_dknaack(
	     _______,_______,_______,_______,_______,_______,		_______,_______,_______,_______,_______,_______,
	     _______,KC_ESC ,MS_UP  ,MS_BTN1,MS_BTN3,MS_WHLU,	 	KC_AMPR,KC_LBRC,KC_VOLD,KC_VOLU,KC_CIRC,_______,
	     _______,MS_LEFT,MS_DOWN,MS_RGHT,MS_BTN2,MS_WHLD,	 	KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_QUES,_______,
	     _______,QK_BOOT,KC_MPLY,KC_MPRV,KC_MNXT,KC_MUTE,	 	KC_TILD,KC_MUTE,KC_MPRV,KC_MNXT,KC_MPLY,_______,
	     _______,_______,_______,_______,_______,_______,	 	_______,_______,_______,_______,_______,_______,
	  								     _______,_______,       _______,_______,
	                                             _______,       _______,
								 _______,_______,_______,       _______,_______,_______
    ),

	[4] = LAYOUT_dknaack(
	     KC_HOME,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,		_______,_______,_______,_______,_______,_______,
	     KC_GRV ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,	 	_______,_______,_______,_______,_______,_______,
	     KC_BSLS,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,	 	_______,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,_______,
	     KC_LBRC,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,	 	_______,_______,_______,_______,_______,_______,
	     _______,_______,_______,_______,_______,_______,	 	_______,_______,_______,_______,_______,_______,
	  								     KC_ESC ,KC_LALT,       _______,_______,
	                                             KC_TAB ,       _______,
								 KC_SPC ,KC_LSFT,KC_LCTL,       _______,KC_RETN,_______
	),
};
