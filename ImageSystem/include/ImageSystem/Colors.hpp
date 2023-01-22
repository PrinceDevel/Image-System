#pragma once
#include <stdint.h>
#include <sstream>

namespace ImageSystem
{
    struct ColorRGBA
    {
        float r, g, b, a = 1.0f;
    };
    struct ColorRGB
    {
        float r, g, b;
    };

    struct Color32
    {
        union {
            struct {
                uint8_t red, green, blue, alpha;
            };
            uint32_t value;
        };

        Color32 (uint32_t value) : value(value) {}
        Color32 (uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = UINT8_MAX) : red(red), green(green), blue(blue), alpha(alpha) {}
        friend std::ostream& operator<<(std::ostream&, const Color32&);
    };

    struct Color64
    {
        union {
            struct {
                uint16_t red, green, blue, alpha;
            };
            uint64_t value;
        };

        Color64 (uint64_t value) : value(value) {}
        Color64 (uint16_t red, uint16_t green, uint16_t blue, uint16_t alpha = UINT16_MAX) : red(red), green(green), blue(blue), alpha(alpha) {}
        friend std::ostream& operator<<(std::ostream&, const Color64&);
    };
}