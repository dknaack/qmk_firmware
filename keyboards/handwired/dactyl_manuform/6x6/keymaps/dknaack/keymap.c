// Copyright 2021 david@impstyle.com (@zwnk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define LAYOUT_dknaack(\
  L00, L01, L02, L03, L04, L05,			 R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,			 R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,			 R20, R21, R22, R23, R24, R25, \
  L30, L31, L32, L33, L34, L35,			 R30, R31, R32, R33, R34, R35, \
  L40, L41, L42, L43, L44, L45,			 R40, R41, R42, R43, R44, R45, \
  					  L53, L52,          R52, R53,					   \
  						   L51,	         R51,						   \
  				 L61, L60, L50,          R50, R60, R61				   \
  ) \
  { \
	{ L05,   L04,   L03,   L02,   L01, L00 }, \
	{ L15,   L14,   L13,   L12,   L11, L10 }, \
	{ L25,   L24,   L23,   L22,   L21, L20 }, \
	{ L35,   L34,   L33,   L32,   L31, L30 }, \
	{ L45,   L44,   L43,   L42,   L41, L40 }, \
	{ KC_NO, KC_NO, L53,   L52,   L51, L50 }, \
	{ KC_NO, KC_NO, KC_NO, KC_NO, L61, L60 }, \
											  \
	{ R00,   R01,   R02,   R03,   R04, R05 }, \
	{ R10,   R11,   R12,   R13,   R14, R15 }, \
	{ R20,   R21,   R22,   R23,   R24, R25 }, \
	{ R30,   R31,   R32,   R33,   R34, R35 }, \
	{ R40,   R41,   R42,   R43,   R44, R45 }, \
	{ KC_NO, KC_NO, R53,   R52,   R51, R50 }, \
	{ KC_NO, KC_NO, KC_NO, KC_NO, R61, R60 }, \
}

#define ESCR   LT(_RAISE, KC_ESC)
#define TABL   LT(_LOWER, KC_TAB)
#define TABS   MT(MOD_LSFT, KC_TAB)
#define ENTA   MT(MOD_LALT, KC_ENT)

#define LS_D LSFT_T(KC_D)
#define LC_F LCTL_T(KC_F)
#define LA_S LALT_T(KC_S)
#define LG_A LGUI_T(KC_A)

#define RS_K RSFT_T(KC_K)
#define RC_J RCTL_T(KC_J)
#define RA_L RALT_T(KC_L)
#define RG_SCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_dknaack(
	     KC_HOME, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,		 KC_6  , KC_7   , KC_8   , KC_9  , KC_0    , KC_END  ,
	     KC_GRV , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,	 	 KC_Y  , KC_U   , KC_I   , KC_O  , KC_P    , QK_BOOT ,
	     KC_BSLS, LG_A  , LA_S  , LS_D  , LC_F  , KC_G  ,	 	 KC_H  , RC_J   , RS_K   , RA_L  , RG_SCLN , KC_QUOT ,
	     KC_LBRC, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,	 	 KC_N  , KC_M   ,KC_COMM , KC_DOT, KC_SLSH , KC_MINS ,
	     KC_RBRC,_______,_______,_______,_______,_______,	 	_______, KC_LEFT,KC_DOWN , KC_UP , KC_RIGHT, KC_EQL  ,
	  								      ESCR  ,KC_LALT,       KC_DEL , TABL   ,
	                                             KC_LGUI,       KC_PGUP,
								  KC_SPC, TABS  ,KC_LCTL,       KC_PGDN, ENTA   , KC_BSPC
	),

    [_LOWER] = LAYOUT_dknaack(
	     _______,_______,_______,_______,_______,_______,		_______,_______ ,_______ ,_______,_______  , _______ ,
	     KC_GRV , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,	 	 KC_Y  ,_______ ,_______ ,_______, _______ , _______ ,
	     KC_BSLS, LG_A  , LA_S  , LS_D  , LC_F  , KC_G  ,	 	 KC_H  ,_______ ,_______ ,_______, _______ , _______ ,
	     KC_LBRC, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,	 	 KC_N  ,_______ ,_______ ,_______, _______ , _______ ,
	     KC_RBRC,_______,_______,_______,_______,_______,	 	_______,_______ ,_______ ,_______, _______ , _______ ,
	  								      ESCR  ,KC_LALT,       KC_DEL , TABL   ,
	                                             KC_LGUI,       KC_PGUP,
								  KC_SPC, TABS  ,KC_LCTL,       KC_PGDN, ENTA   , KC_BSPC
    ),
};
