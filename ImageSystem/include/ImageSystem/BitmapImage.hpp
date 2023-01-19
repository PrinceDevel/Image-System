#include <iostream>
#include <vector>

namespace ImageSystem
{

    class Pixel
    {
    public:
        unsigned char r = 10;
        unsigned char g = 10;
        unsigned char b = 10;

        Pixel() = default;
        Pixel(unsigned char _r, unsigned char _g, unsigned char _b) : r(_r), g(_g), b(_b) {};
    };

    class BitmapImage
    {
        unsigned int m_Width, m_Height, m_Count;

    public:
        std::vector<Pixel> m_PixelData;
        BitmapImage() = default;
        BitmapImage (unsigned int a_Width, unsigned int a_Height) : m_Width(a_Width), m_Height(a_Height)
        {
            this->m_Count = a_Width * a_Height; 
            this->m_PixelData = std::vector<Pixel> (m_Count);
        }
        
        void SetPixel(unsigned int x, unsigned int y, Pixel pixel)
        {
            if (x < m_Width && y < m_Height)
                m_PixelData[y * m_Width + x] = pixel;
        }
        void SetPixel(unsigned int index, Pixel pixel)
        {
            if (index < m_Count)
                m_PixelData[index] = pixel;
        }

        Pixel GetPixel(unsigned int x, unsigned int y)
        {
            return (x < m_Width && y < m_Height) ? m_PixelData[x * m_Width + y] : Pixel();
        }
        Pixel GetPixel(unsigned int index)
        {
            return index < m_Count ? m_PixelData[index] : Pixel();
        }
        
        inline unsigned int GetWidth() { return m_Width; }
        inline unsigned int GetHeight() { return m_Height; }
        inline unsigned int GetCount() { return m_Count; }


        void Write (const char* a_Filepath);
        static BitmapImage* Read(const char* a_Filepath);
    };

}