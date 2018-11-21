#ifndef SPARTANOS_CONSOLE_H
#define SPARTANOS_CONSOLE_H

#include <stdarg.h>
#include <stdint.h>

static const uint32_t VIDEO_MEMORY = 0xB8000;
static const uint32_t WIDTH = 80;
static const uint32_t HEIGHT = 25;
static const uint32_t LINE_BYTES = WIDTH * 2;
static const uint32_t SCREEN_BYTES = HEIGHT * LINE_BYTES;

static const uint32_t DEFAULT_COLOR = 0x07;
static const uint32_t HEADER_COLOR = 0x0F;

void print(char c);
void putChar(uint16_t x, uint16_t y, char c, uint8_t color);
void putString(uint16_t x, uint16_t y, const char* c, uint8_t color);
void setColor(uint8_t nColor);
void clearConsole();
void printk(char *c);

void scrollUp();

#endif
