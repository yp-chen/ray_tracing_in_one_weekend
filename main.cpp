#define UNICODE
#define _UNICODE
#include <conio.h>
#include "device.h"
#include "vec3.h"
int main() {
    constexpr int ScreenWidth = 640;
    constexpr int ScreenHeight = 480;
    const Device Graphics (ScreenWidth, ScreenHeight);
    for (int i = 0; i < ScreenHeight ; ++i) {
        Color writecolor;
        std::clog << "\rThere are still left:" << ( ScreenHeight - i) << "scanlines to be rendered" << std::flush;
        writecolor[0] = static_cast<double>(i) / (ScreenHeight - 1) * 255.999;
        for (int j = 0; j < ScreenWidth; ++j) {
            writecolor[1] = static_cast<double>(j) / (ScreenWidth - 1) * 255.999;
            Graphics.At(j, i) = colorToDWORD(writecolor);
        }
    }
    std::clog << "\rrendered finish" << std::endl;
    Device::Flush();
    _getch();
    return 0;
}