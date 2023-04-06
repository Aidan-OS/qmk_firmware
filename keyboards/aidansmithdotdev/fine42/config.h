// Copyright 2022 Aidan Smith (@Aidan-OS)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19

#define LCD_RST_PIN GP23
#define LCD_DC_PIN GP22
#define LCD_CS_PIN GP21

#define LCD_SPI_DIVISOR 8

#define QUANTUM_PAINTER_DEBUG
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS true