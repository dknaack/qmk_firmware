// Copyright 2021 david@impstyle.com (@zwnk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "layout.h"

enum tap_dance_keys {
    _MEDIA,
};

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _NUMBER,
    _SYMBOL,
    _GAME,
};

tap_dance_action_t tap_dance_actions[] = {
    [_MEDIA] = ACTION_TAP_DANCE_DOUBLE(KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK),
};

#define MEDIA TD(_MEDIA)
#define GAME TG(_GAME)
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define DE_AE RALT_T(KC_A)
#define DE_OE RALT_T(KC_P)
#define DE_UE RALT_T(KC_Y)

#define ESCR    LT(_RAISE, KC_ESC)
#define SFT_TAB MT(MOD_LSFT, KC_TAB)
#define ALT_ENT MT(MOD_RALT, KC_ENT)

#if 1
#  define NUM_SPC LT(_RAISE, KC_SPACE)
#  define SYM_ENT LT(_LOWER, KC_ENT)

#  define CTL_F    LCTL_T(KC_F)
#  define SFT_D    LSFT_T(KC_D)
#  define ALT_S    LALT_T(KC_S)
#  define GUI_A    LGUI_T(KC_A)
#  define CTL_J    RCTL_T(KC_J)
#  define SFT_K    RSFT_T(KC_K)
#  define ALT_L    RALT_T(KC_L)
#  define GUI_SCLN RGUI_T(KC_SCLN)

#  define GUI_1 LGUI_T(KC_1)
#  define ALT_2 LALT_T(KC_2)
#  define SFT_3 LSFT_T(KC_3)
#  define CTL_4 LCTL_T(KC_4)
#  define GUI_0 RGUI_T(KC_0)
#  define ALT_9 RALT_T(KC_9)
#  define SFT_8 RSFT_T(KC_8)
#  define CTL_7 RCTL_T(KC_7)
#else
#  define NUM_SPC KC_SPC
#  define SYM_ENT MT(MOD_RALT, KC_ENT)

#  define CTL_F KC_F
#  define SFT_D KC_D
#  define ALT_S KC_S
#  define GUI_A KC_A

#  define CTL_J KC_J
#  define SFT_K KC_K
#  define ALT_L KC_L
#  define GUI_SCLN KC_SCLN
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_dknaack(
	     KC_HOME,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,		KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0    ,KC_END ,
	     KC_GRV ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,	 	KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P    ,QK_BOOT,
	     KC_BSLS,GUI_A  ,ALT_S  ,SFT_D  ,CTL_F  ,KC_G   ,	 	KC_H   ,CTL_J  ,SFT_K  ,ALT_L  ,GUI_SCLN,KC_QUOT,
	     KC_LBRC,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,	 	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH ,KC_MINS,
	     KC_RBRC,MEDIA  ,GAME   ,KC_VOLU,KC_MUTE,KC_NO  ,	 	KC_NO  ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RIGHT,KC_EQL ,
	  								     ESCR   ,KC_LALT,       KC_DEL ,KC_TAB ,
	                                             KC_LGUI,       KC_PGUP,
								 NUM_SPC,KC_TAB ,KC_LCTL,       KC_PGDN,SYM_ENT, KC_BSPC
	),

    [_RAISE] = LAYOUT_dknaack(
	     KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,	 	KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
	     _______,_______,_______,_______,_______,_______,	 	_______,_______,_______,_______,_______,_______,
	     _______,GUI_1  ,ALT_2  ,SFT_3  ,CTL_4  ,KC_5   ,	 	KC_6   ,CTL_7  ,SFT_8  ,ALT_9  ,GUI_0  ,_______,
	     _______,KC_GRV ,KC_BSLS,KC_LBRC,KC_RBRC,KC_SPC ,	 	KC_BSPC,KC_QUOT,KC_MINS,KC_EQL ,_______,_______,
	     _______,_______,_______,_______,_______,_______,	 	_______,_______,_______,_______,_______,_______,
	  								     _______,_______,       _______,_______,
	                                             _______,       _______,
								 _______,_______,_______,       _______,KC_ENT ,_______
    ),

    [_LOWER] = LAYOUT_dknaack(
	     _______,_______,_______,_______,_______,_______,		_______,_______,_______,_______,_______,_______,
	     _______,KC_ESC ,KC_LT  ,KC_GT  ,KC_BSLS,KC_QUOT,	 	KC_AMPR,KC_LBRC,KC_RBRC,KC_AT  ,KC_CIRC,_______,
	     _______,KC_EXLM,KC_MINS,KC_PLUS,KC_EQL ,KC_DQUO,	 	KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_QUES,_______,
	     _______,KC_PERC,KC_SLSH,KC_ASTR,KC_UNDS,KC_GRV ,	 	KC_TILD,KC_LCBR,KC_RCBR,KC_DLR ,KC_DOT ,_______,
	     _______,_______,_______,_______,_______,_______,	 	_______,_______,_______,_______,_______,_______,
	  								     _______,_______,       _______,_______,
	                                             _______,       _______,
								 _______,_______,_______,       _______,_______,_______
    ),

	[_GAME] = LAYOUT_dknaack(
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
