// Copyright 2022 Aidan Smith (@Aidan-OS)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"
#include <qp.h>
#include "Ene.qgf.h"

enum keyboard_layers {
	_MAIN,
	_RIGHT,
	_LEFT,
	_TAB,
};


#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
   if (!encoder_update_user(index, clockwise)) {
       return false;
   }
   // Volume control
   if (clockwise) {
   	tap_code(KC_VOLU);
   } else {
   	tap_code(KC_VOLD);
   }
   return true;
}
#endif

static painter_device_t display;
static painter_image_handle_t image;
//static deferred_token animation;

void keyboard_post_init_kb(void)
{
    display = qp_st7789_make_spi_device(240, 280, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, 0);
    qp_init(display, QP_ROTATION_180);
    
    image = qp_load_image_mem(gfx_Ene);
    if (image != NULL)
    {
        qp_drawimage(display, (239 - image->width), (279 - image->height), image);
    }
    
}

void keyboard_post_init_user(void)
{
    debug_enable = true;
}