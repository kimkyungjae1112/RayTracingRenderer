#ifndef __CONTEXT_H__
#define __CONTEXT_H__
#define _USE_MATH_DEFINES

#include <spdlog/spdlog.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory.h>
#include "../Math/Vector.h"
#include "../Math/Matrix.h"
#include "../Object/Sphere.h"
#include "Ray.h"

class Context
{

public:
    static std::unique_ptr<Context> Create();
    void Render();

private:
    Context() {}
    bool Init();

    struct FCameraInfo
    {
        Vector E{0.0, 0.0, 10.0 , 1.0};
        Vector D{0.0, 0.0, 0.0, 1.0};
        Vector Up{0.0, 1.0, 0.0};
    };
    FCameraInfo CameraInfo; 

    struct FWindowInfo
    {
        int ScreenWidth{WINDOW_WIDTH};
        int ScreenHeight{WINDOW_HEIGHT};

        double Fov = 90.0;
        double Aspect = ScreenWidth / ScreenHeight;
        double Near = 1.0;
        double Far = 200.0;
        double Distance{ScreenHeight / (2 * tan(Fov * M_PI / 360.0))};
    };
    FWindowInfo WindowInfo;
};

#endif // __CONTEXT_H__