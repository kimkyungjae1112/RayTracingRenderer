#include "Context.h"

std::unique_ptr<Context> Context::Create()
{
    std::unique_ptr<Context> context = std::unique_ptr<Context>(new Context());
    if(!context->Init()) return nullptr;
    return std::move(context);
}

void Context::Render()
{
    // === 카메라 기준 벡터 설정 ===
    Vector W = -CameraInfo.Target.Normalization(); // 뒤쪽 방향
    Vector U = (CameraInfo.Target * CameraInfo.Up).Normalization(); // 오른쪽
    Vector V = (U * CameraInfo.Target).Normalization(); // 위쪽
    std::cout << W << U << V << std::endl;

    Matrix Mat4;
    Mat4.ViewingTransformationMat({W,U,V, CameraInfo.E}); 
    std::cout << Mat4 << std::endl;

    // nx = 960, ny = 540
    // 해상도 정보
    int nx = WindowInfo.ScreenWidth;
    int ny = WindowInfo.ScreenHeight;
    double d = -WindowInfo.Distance; // 스크린까지 거리

    glPointSize(1.0f);
    glBegin(GL_POINTS);  // 점 단위로 그리기 시작

    for (int j = 0; j < ny; ++j)
    {
        for (int i = 0; i < nx; ++i)
        {
            double px = (i - nx / 2.0 + 0.5);
            double py = (ny / 2.0 - j - 0.5);
            Vector pixelScreenSpace = {px, py, d, 1};
            Vector pixelWorld = Mat4 * pixelScreenSpace;
            Vector rayDir = (pixelWorld - CameraInfo.E).Normalization();

            if (j > ny / 2 == 0) glColor3ub(0, 255, 0);
            else glColor3ub(255, 0, 0);

            std::cout << "Screen Space Pos: " << pixelScreenSpace << std::endl;
            std::cout << "World Pos       : " << pixelWorld << std::endl;
            std::cout << "Ray Direction   : " << rayDir << std::endl;

            // 정규화된 위치로 바꿔서 점 찍기 (OpenGL 좌표는 [-1,1])
            float x = (2.0f * i) / (float)(nx - 1) - 1.0f;
            float y = 1.0f - (2.0f * j) / (float)(ny - 1);
            glVertex2f(x, y);
        }
    }
    glEnd();
}

bool Context::Init()
{
    return true;
}
