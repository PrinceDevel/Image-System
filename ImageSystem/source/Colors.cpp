#include "precompiled.hpp"
#include "ImageSystem/Colors.hpp"

namespace ImageSystem
{
    std::ostream& operator<<(std::ostream& os, const Color32& color)
    {
        os << "(" << (int) color.red << "," << (int) color.green << "," << (int) color.blue << "," << (int) color.alpha << ") [" << color.value << "]";
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Color64& color)
    {
        os << "(" << (int) color.red << "," << (int) color.green << "," << (int) color.blue << "," << (int) color.alpha << ") [" << color.value << "]";
        return os;
    }
}