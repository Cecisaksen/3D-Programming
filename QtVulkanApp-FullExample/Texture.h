#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

///Simple class for creating textures from a bitmap file.
class Texture // : protected QOpenGLFunctions_4_1_Core
{
public:
    ///Makes a dummy texture
    Texture();  //calls makeDummyTexture()

    ///Reads bmp file given by filename - path is required
    Texture(const std::string &filename);

    ///Returns the id OpenGL gives this texture
    unsigned int id() const;

    ///Filename of the texture, with full path
    std::string textureFilename{};

    int textureSize() const { return mColumns * mRows * mBytesPrPixel; }

    unsigned char* getBitmap() { return mBitmap; }
    unsigned char* getPixels() { return pixels; }
    inline int width() const { return mColumns; }
    inline int height() const { return mRows; }
    bool hasAlpha() const { return mAlphaUsed; }

    inline int bytesPrPixel() const { return mBytesPrPixel;}

private:
    unsigned char pixels[16];     // For the standard texture from the no-parameter constructor
    unsigned int mId{0};          //Texture ID that OpenGL makes when glGenTextures is called

    ///Pointer to the pixels in the bitmap, starting at lower, left corner
    unsigned char *mBitmap{nullptr};
    ///The width of the image, in pixels
    int mColumns{};
    ///The height of the image, in pixels
    int mRows{};
    ///Number of bytes describing each pixel. Have to be 3 or 4 - RGB or RGBA
    int mBytesPrPixel{};
    ///Does this image use alpha channel?
    bool mAlphaUsed{false};

    ///Reads in the BMP file given in filename. Have to contain the path and filename.
    bool readBitmap(const std::string& filename);

    /**********************************/
    //This is put inside this class to avoid spamming the main namespace
    //with stuff that only is used inside this class

    //Quick fix to get rid of windows.h which contains
    //BITMAPINFOHEADER and BITMAPFILEHEADER.
    typedef unsigned short int OWORD;    //should be 16 bit
    typedef unsigned int ODWORD;         //should be 32 bit
    typedef int OLONG;                   //should be 32 bit

    //Bitmap file header
    struct OBITMAPFILEHEADER {
        OWORD  bfType;          //will contain ascii BM == 0x4D42 == 19778 decimal
        ODWORD bfSize;          //often set to 0, not to actual size
        OWORD  bfReserved1;
        OWORD  bfReserved2;
        ODWORD bfOffBits;       //often set to 0, not to offset
    };

    //DIB header (bitmap information header)
    struct OBITMAPINFOHEADER {
        ODWORD biSize;          //size of this header (in the file)
        OLONG  biWidth;
        OLONG  biHeight;
        OWORD  biPlanes;
        OWORD  biBitCount;
        ODWORD biCompression;   //most often set to 0 if no compression
        ODWORD biSizeImage;     //size of actual image
        OLONG  biXPelsPerMeter;
        OLONG  biYPelsPerMeter;
        ODWORD biClrUsed;
        ODWORD biClrImportant;
    };
    void makeDummyTexture();
};

#endif // TEXTURE_H
