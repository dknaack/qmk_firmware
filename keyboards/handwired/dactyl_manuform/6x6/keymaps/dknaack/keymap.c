// Copyright 2021 david@impstyle.com (@zwnk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "layout.h"
#include "keymap_us_international.h"
#include "sendstring_us_international.h"

#define GAME TG(4)

#define SYM_ENT LT(2, KC_ENT)
#define NUM_TAB LT(1, KC_TAB)
#define NAV_TAB LT(3, KC_TAB)
#define NAV_ENT LT(3, KC_ENT)

/*
 * Home-row mods
 */

#define GUI_A   LGUI_T(KC_A)
#define ALT_S   LALT_T(KC_S)
#define SFT_D   LSFT_T(KC_D)
#define CTL_F   LCTL_T(KC_F)
#define CTL_J   RCTL_T(KC_J)
#define SFT_K   RSFT_T(KC_K)
#define ALT_L   RALT_T(KC_L)
#define GUI_SCL RGUI_T(KC_SCLN)

#define GUI_MIN LGUI_T(KC_MINS)
#define ALT_4   LALT_T(KC_4)
#define SFT_5   LSFT_T(KC_5)
#define CTL_6   LCTL_T(KC_6)
#define GUI_0 RGUI_T(KC_0)
#define ALT_9 RALT_T(KC_9)
#define SFT_8 RSFT_T(KC_8)
#define CTL_7 RCTL_T(KC_7)

/*
 * Combos
 */

// combos adapted from <https://gitlui.github.io/zmk-config-mone-layout/>
const uint16_t PROGMEM combo_ae[] = {KC_H, GUI_A, COMBO_END};
const uint16_t PROGMEM combo_oe[] = {KC_G, KC_O, COMBO_END};
const uint16_t PROGMEM combo_ue[] = {KC_G, KC_U, COMBO_END};
const uint16_t PROGMEM combo_ss[] = {KC_H, ALT_S, COMBO_END};
const uint16_t PROGMEM combo_at[] = {KC_H, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_capsword[] = {SFT_D, SFT_K, COMBO_END};

combo_t key_combos[] = {
    COMBO_ACTION(combo_capsword),
    COMBO(combo_ae, US_ADIA),
    COMBO(combo_oe, US_ODIA),
    COMBO(combo_ue, US_UDIA),
    COMBO(combo_ss, US_SS),
    COMBO(combo_at, KC_AT),
};

void
process_combo_event(uint16_t combo_index, bool pressed)
{
    if (combo_index == 0 && pressed) {
        caps_word_toggle();
    }
}

/*
 * Keymap
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_dknaack(
	     KC_HOME,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,		KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_END ,
	     KC_GRV ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,	 	KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_EQL ,
	     KC_BSLS,GUI_A  ,ALT_S  ,SFT_D  ,CTL_F  ,KC_G   ,	 	KC_H   ,CTL_J  ,SFT_K  ,ALT_L  ,GUI_SCL,KC_QUOT,
	     KC_LBRC,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,	 	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_MINS,
	     KC_RBRC,KC_NO  ,GAME   ,TG(5)  ,KC_NO  ,KC_NO  ,	 	KC_NO  ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_EQL ,
	  								     KC_ESC ,KC_LALT,       KC_DEL ,KC_TAB ,
	                                             KC_LGUI,       KC_PGUP,
								 KC_SPC ,NUM_TAB,KC_LCTL,       KC_PGDN,SYM_ENT, KC_BSPC
	),

    [1] = LAYOUT_dknaack(
	     _______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,
	     _______,KC_PLUS,KC_7   ,KC_8   ,KC_9   ,_______,       KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
	     _______,GUI_MIN,ALT_4  ,SFT_5  ,CTL_6  ,_______,       KC_6   ,CTL_7  ,SFT_8  ,ALT_9  ,GUI_0  ,QK_BOOT,
	     _______,KC_0   ,KC_1   ,KC_2   ,KC_3   ,_______,       KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_END ,
	     _______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,
	  								     _______,_______,       _______,_______,
	                                             _______,       _______,
								 _______,_______,_______,       _______,_______,_______
    ),

    [2] = LAYOUT_dknaack(
	     _______,_______,_______,_______,_______,_______,		_______,_______,_______,_______,_______,_______,
	     _______,MS_BTN2,MS_UP  ,MS_BTN1,MS_BTN3,MS_WHLU,	 	_______,_______,MS_BTN4,MS_BTN5,KC_VOLU,_______,
	     _______,MS_LEFT,MS_DOWN,MS_RGHT,_______,MS_WHLD,	 	KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_VOLD,_______,
	     _______,_______,_______,_______,_______,_______,	 	_______,KC_MPLY,KC_MPRV,KC_MNXT,KC_MUTE,_______,
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

    /* layout for testing no number row */
	[5] = LAYOUT_dknaack(
	     KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,		KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,
	     _______,_______,_______,_______,_______,_______,	 	_______,_______,_______,_______,_______,_______,
	     _______,_______,_______,_______,_______,_______,	 	_______,_______,_______,_______,_______,_______,
	     _______,_______,_______,_______,_______,_______,	 	_______,_______,_______,_______,_______,_______,
	     _______,_______,_______,_______,_______,_______,	 	_______,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,_______,
	  								     _______,_______,       _______,_______,
	                                             _______,       _______,
								 _______,_______,_______,       _______,_______,_______
	),

};
