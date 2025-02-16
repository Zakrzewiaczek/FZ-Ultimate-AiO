#ifndef BITMAP_RESOURCES_H
#define BITMAP_RESOURCES_H

#include <avr/pgmspace.h>

class BitmapResources
{
    BitmapResources() = delete;
    BitmapResources(BitmapResources const &) = delete;
    void operator=(BitmapResources const &) = delete;

public:
    /// @brief ESP32 bitmap.
    static const unsigned char esp32_bitmap[] PROGMEM;
};

#endif // BITMAP_RESOURCES_H