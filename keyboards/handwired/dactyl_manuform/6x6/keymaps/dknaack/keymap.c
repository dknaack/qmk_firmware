// Copyright 2021 david@impstyle.com (@zwnk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "layout.h"
#include "keymap_us_international.h"
#include "sendstring_us_international.h"

#define LT1_SPC LT(1, KC_SPC)
#define LT2_TAB LT(2, KC_TAB)
#define LT3_ENT LT(3, KC_ENT)
#define LT4_BSPC LT(4, KC_BSPC)

/*
 * Home-row mods
 */

// base layer mods
#define GUI_A   LGUI_T(KC_A)
#define ALT_S   LALT_T(KC_S)
#define SFT_D   LSFT_T(KC_D)
#define CTL_F   LCTL_T(KC_F)
#define CTL_J   RCTL_T(KC_J)
#define SFT_K   RSFT_T(KC_K)
#define ALT_L   RALT_T(KC_L)
#define GUI_QT  RGUI_T(KC_QUOT)

// number layer mods
#define GUI_MIN LGUI_T(KC_MINS)
#define ALT_4   LALT_T(KC_4)
#define SFT_5   LSFT_T(KC_5)
#define CTL_6   LCTL_T(KC_6)

// colemak-dh mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)
#define HOME_N RCTL_T(KC_N)
#define HOME_E RALT_T(KC_E)
#define HOME_I RALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

/*
 * Combos
 */

const uint16_t PROGMEM combo_capsword[] = {SFT_D, SFT_K, COMBO_END};
const uint16_t PROGMEM combo_escape[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[] = {
    COMBO_ACTION(combo_capsword),
    COMBO(combo_escape, KC_ESC),
};

void
process_combo_event(uint16_t combo_index, bool pressed)
{
    if (combo_index == 0 && pressed) {
        caps_word_toggle();
    }
}

/*
 * Key overrides
 */
const key_override_t key_override_comma = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SCLN);
const key_override_t key_override_dot = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&key_override_comma,
	&key_override_dot,
};

/*
 * Keymap
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_dknaack(
         KC_HOME,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,       KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_END ,
         KC_GRV ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,       KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_NUBS,
         KC_BSLS,GUI_A  ,ALT_S  ,SFT_D  ,CTL_F  ,KC_G   ,       KC_H   ,CTL_J  ,SFT_K  ,ALT_L  ,GUI_QT ,KC_EQL ,
         KC_LBRC,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,       KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_MINS,
         KC_RBRC,TG(6)  ,TG(4)  ,TG(5)  ,KC_NO  ,KC_NO  ,       KC_NO  ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_EQL ,
                                         KC_ESC ,KC_LALT,       KC_DEL ,KC_TAB ,
                                                 KC_LGUI,       KC_PGUP,
                                 LT1_SPC,LT2_TAB,KC_LCTL,       KC_PGDN,LT3_ENT,LT4_BSPC
    ),

    [3] = LAYOUT_dknaack(
         _______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,
         _______,KC_LCBR,KC_7   ,KC_8   ,KC_9   ,KC_RCBR,       _______,_______,_______,_______,_______,_______,
         _______,KC_LBRC,ALT_4  ,SFT_5  ,CTL_6  ,KC_RBRC,       _______,_______,_______,_______,_______,QK_BOOT,
         _______,KC_LPRN,KC_1   ,KC_2   ,KC_3   ,KC_RPRN,       _______,_______,_______,_______,_______,_______,
         _______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,
                                         _______,_______,       _______,_______,
                                                 _______,       _______,
                                 KC_0   ,KC_UNDS,_______,       _______,_______,_______
    ),

    [2] = LAYOUT_dknaack(
        _______,_______,_______,_______,_______,_______,        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,        KC_CIRC,KC_AMPR,KC_ASTR,KC_PERC,KC_AT  ,_______,
        _______,_______,_______,_______,_______,_______,        KC_PIPE,KC_MINS,KC_PLUS,KC_EXLM,KC_GRV ,_______,
        _______,_______,_______,_______,_______,_______,        KC_TILD,KC_HASH,KC_LT  ,KC_GT  ,KC_BSLS,_______,
        _______,_______,_______,_______,_______,_______,        _______,_______,_______,_______,_______,_______,
                                        _______,_______,        _______,_______,
                                                _______,        _______,
                                _______,_______,_______,        _______,KC_EQL ,KC_DLR
    ),

    [1] = LAYOUT_dknaack(
         _______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,
         _______,_______,_______,_______,_______,_______,       _______,_______,MS_BTN4,MS_BTN5,KC_VOLU,_______,
         _______,_______,_______,_______,_______,_______,       KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_VOLD,_______,
         _______,_______,_______,_______,_______,_______,       _______,KC_MPLY,KC_MPRV,KC_MNXT,KC_MUTE,_______,
         _______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,
                                         _______,_______,       _______,_______,
                                                 _______,       _______,
                                 _______,_______,_______,       _______,KC_ENT ,KC_BSPC
    ),


    [4] = LAYOUT_dknaack(
        KC_HOME,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,        _______,_______,_______,_______,_______,_______,
        KC_GRV ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,        _______,_______,_______,_______,_______,_______,
        KC_BSLS,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,        _______,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,_______,
        KC_LBRC,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,        _______,_______,_______,_______,_______,_______,
                                        KC_ESC ,KC_LALT,        _______,_______,
                                                KC_TAB ,        _______,
                                KC_SPC ,KC_LSFT,KC_LCTL,        _______,KC_RETN,_______
    ),

    /* layout for testing 34 keys */
    [5] = LAYOUT_dknaack(
         KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,       KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,
         KC_NO  ,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,KC_NO  ,
         KC_NO  ,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,KC_NO  ,
         KC_NO  ,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,KC_NO  ,
         KC_NO  ,_______,_______,_______,_______,_______,       _______,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,
                                         KC_NO  ,KC_NO  ,       KC_NO  ,KC_NO  ,
                                                 KC_NO  ,       KC_NO  ,
                                 _______,_______,KC_NO  ,       KC_NO  ,_______,_______
    ),

    /* colemak-dh layer */
    [6] = LAYOUT_dknaack(
         KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,       KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,
         KC_NO  ,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_B   ,       KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_SCLN,KC_NO  ,
         KC_NO  ,HOME_A ,HOME_R ,HOME_S ,HOME_T ,KC_G   ,       KC_M   ,HOME_N ,HOME_E ,HOME_I ,HOME_O ,KC_NO  ,
         KC_NO  ,KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_V   ,       KC_K   ,KC_H   ,KC_COMM,KC_DOT ,KC_SLSH,KC_NO  ,
         KC_NO  ,_______,_______,_______,_______,_______,       _______,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,
                                         KC_NO  ,KC_NO  ,       KC_NO  ,KC_NO  ,
                                                 KC_NO  ,       KC_NO  ,
                                 _______,_______,KC_NO  ,       KC_NO  ,_______,_______
    ),

};
