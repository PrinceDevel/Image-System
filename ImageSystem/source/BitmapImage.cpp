#include "precompiled.hpp"
#include "ImageSystem/BitmapImage.hpp"

namespace ImageSystem
{

    void BitmapImage::Write (const char* a_FilePath)
    {
        const unsigned int      fileHeaderSize      = 14;
        const unsigned int      infoHeaderSize      = 40;
        const unsigned int      pixelDataSize       = m_Count * 4;
        const unsigned int      pixelDataOffset     = fileHeaderSize + infoHeaderSize;
        const unsigned int      fileSize            = fileHeaderSize + infoHeaderSize + pixelDataSize;
        std::vector<unsigned char> rawdata (fileSize);

        // PUTTING DATA
        //? Refrence: http://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm
        { 
            rawdata[0] = 'B';
            rawdata[1] = 'M';
            
            rawdata[2] = fileSize;
            rawdata[3] = fileSize >> 8;
            rawdata[4] = fileSize >> 16;
            rawdata[5] = fileSize >> 24;

            rawdata[10] = pixelDataOffset;
            rawdata[11] = pixelDataOffset >> 8;
            rawdata[12] = pixelDataOffset >> 16;
            rawdata[13] = pixelDataOffset >> 24;

            rawdata[14] = infoHeaderSize;
            rawdata[15] = infoHeaderSize >> 8;
            rawdata[16] = infoHeaderSize >> 16;
            rawdata[17] = infoHeaderSize >> 24;
            
            rawdata[18] = m_Width;
            rawdata[19] = m_Width >> 8;
            rawdata[20] = m_Width >> 16;
            rawdata[21] = m_Width >> 24;
            
            rawdata[22] = m_Height;
            rawdata[23] = m_Height >> 8;
            rawdata[24] = m_Height >> 16;
            rawdata[25] = m_Height >> 24;

            rawdata[26] = 1;
            rawdata[28] = 24;
        }
        std::cout << "Size: " << fileSize << std::endl;

        // Putting Pixel Data
        unsigned int index = pixelDataOffset;
        for (int i = 0; i < m_Count; i++)
        {
            Pixel pixel = m_PixelData[i];
            rawdata[index++] = pixel.b;
            rawdata[index++] = pixel.g;
            rawdata[index++] = pixel.r;
            // rawdata[index++] = pixel.a;
        }

        // Writing DATA
        std::ofstream stream (a_FilePath, std::ios::binary);
        if (stream.is_open())
        {
            for (unsigned char value: rawdata)
            {
                stream << value;
            }
            stream.close();
        }
    }

    BitmapImage* BitmapImage::Read (const char* a_Filepath)
    {
        std::ifstream stream (a_Filepath, std::ios::in | std::ios::binary);
        if (!stream.is_open())
        {
            std::cout << "[ERROR] Unabled to read file at path: " << a_Filepath << std::endl;
            return nullptr;
        }


        unsigned char info[54];
        stream >> std::noskipws;
        for (int i=0; i<54; i++)
            stream >> info[i];

        if (info[0] != 'B' || info[1] != 'M')
        {
            std::cout << "Invalid BMP File [" << info[0] << info[1] << "]" << std::endl;
            stream.close();
            exit(0);
        }
        
        unsigned int fileSize = info[2] + (info[3] << 8) + (info[4] << 16) + (info[5] << 24);
        unsigned int pixelDataOffset = info[10] + (info[11] << 8) + (info[12] << 16) + (info[13] << 24);
        unsigned int width = info[18] + (info[19] << 8) + (info[20] << 16) + (info[21] << 24);
        unsigned int height = info[22] + (info[23] << 8) + (info[24] << 16) + (info[25] << 24);
        
        unsigned int index = 0;
        for (unsigned char garbage, index = pixelDataOffset - 54; 0 < index; index--)
            stream >> garbage;

        BitmapImage* image = new BitmapImage(width, height);
        for (; index < image->GetCount(); index++)
        {
            Pixel pixel;
            stream >> pixel.b;
            stream >> pixel.g;
            stream >> pixel.r;
            image->SetPixel(index, pixel);
        }

        stream.close();
        return image;
    }
}