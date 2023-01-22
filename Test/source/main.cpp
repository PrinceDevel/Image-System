#include <ImageSystem/BitmapImage.hpp>
#include <memory>

int main()
{
    const static ImageSystem::Color32 BLACK           (0, 0, 0);
    const static ImageSystem::Color32 WHITE           (255, 255, 255);
    const static ImageSystem::Color32 RED             (255, 0, 0);
    const static ImageSystem::Color32 BLUE_GREEN      (0, 255, 89);
    const static ImageSystem::Color32 BACKGROUND      (190, 190, 190);
    const static ImageSystem::Color32 SKIN            (234, 192, 154);
    const static ImageSystem::Color32 SHADOW          (211, 161, 118);
    const char* path1 = "resource/SantaPixel8x8.bmp";
    const char* path2 = "resource/SantaClause.bmp";

    // Creating an image
    ImageSystem::BitmapImage<ImageSystem::Color32> image (8, 8);

    image.SetPixel(0, 0, BLACK);
    image.SetPixel(1, 0, BLACK);
    image.SetPixel(2, 0, BLACK);
    image.SetPixel(3, 0, BACKGROUND);
    image.SetPixel(4, 0, BACKGROUND);
    image.SetPixel(5, 0, BLACK);
    image.SetPixel(6, 0, BLACK);
    image.SetPixel(7, 0, BLACK);

    image.SetPixel(0, 1, BACKGROUND);
    image.SetPixel(1, 1, SKIN);
    image.SetPixel(2, 1, RED);
    image.SetPixel(3, 1, RED);
    image.SetPixel(4, 1, RED);
    image.SetPixel(5, 1, RED);
    image.SetPixel(6, 1, SKIN);
    image.SetPixel(7, 1, BACKGROUND);
    
    image.SetPixel(0, 2, BACKGROUND);
    image.SetPixel(1, 2, BLUE_GREEN);
    image.SetPixel(2, 2, RED);
    image.SetPixel(3, 2, RED);
    image.SetPixel(4, 2, RED);
    image.SetPixel(5, 2, RED);
    image.SetPixel(6, 2, BLUE_GREEN);
    image.SetPixel(7, 2, BACKGROUND);
    
    image.SetPixel(0, 3, BACKGROUND);
    image.SetPixel(1, 3, BLUE_GREEN);
    image.SetPixel(2, 3, RED);
    image.SetPixel(3, 3, RED);
    image.SetPixel(4, 3, RED);
    image.SetPixel(5, 3, RED);
    image.SetPixel(6, 3, BLUE_GREEN);
    image.SetPixel(7, 3, BACKGROUND);
    
    image.SetPixel(0, 4, BACKGROUND);
    image.SetPixel(1, 4, BACKGROUND);
    image.SetPixel(2, 4, SHADOW);
    image.SetPixel(3, 4, SKIN);
    image.SetPixel(4, 4, SKIN);
    image.SetPixel(5, 4, SKIN);
    image.SetPixel(6, 4, BACKGROUND);
    image.SetPixel(7, 4, BACKGROUND);
    
    image.SetPixel(0, 5, BACKGROUND);
    image.SetPixel(1, 5, BACKGROUND);
    image.SetPixel(2, 5, SHADOW);
    image.SetPixel(3, 5, BLACK);
    image.SetPixel(4, 5, SKIN);
    image.SetPixel(5, 5, BLACK);
    image.SetPixel(6, 5, BACKGROUND);
    image.SetPixel(7, 5, BACKGROUND);
    
    image.SetPixel(0, 6, WHITE);
    image.SetPixel(1, 6, BACKGROUND);
    image.SetPixel(2, 6, WHITE);
    image.SetPixel(3, 6, WHITE);
    image.SetPixel(4, 6, WHITE);
    image.SetPixel(5, 6, WHITE);
    image.SetPixel(6, 6, BACKGROUND);
    image.SetPixel(7, 6, BACKGROUND);
    
    image.SetPixel(0, 7, BACKGROUND);
    image.SetPixel(1, 7, RED);
    image.SetPixel(2, 7, RED);
    image.SetPixel(3, 7, RED);
    image.SetPixel(4, 7, RED);
    image.SetPixel(5, 7, RED);
    image.SetPixel(6, 7, BACKGROUND);
    image.SetPixel(7, 7, BACKGROUND);
    
    image.Save(path1);

    std::unique_ptr<ImageSystem::BitmapImage<ImageSystem::Color32>> img;
    img.reset(ImageSystem::BitmapImage<ImageSystem::Color32>::Load(path1));
    img->Save(path2);

    return 0;
}