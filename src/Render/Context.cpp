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
    Vector AT = CameraInfo.D - CameraInfo.E;
    Vector U = AT * CameraInfo.Up;
	Vector V = U * AT;
	Vector W = -AT;
    std::cout << "U : " << U.Normalization() 
              << "V : " << V.Normalization() 
              << "W : " << W.Normalization() 
              << "E : " << CameraInfo.E 
              << std::endl;

    Matrix Mat4;
    Mat4.ViewingTransformationMat({U, V, W, CameraInfo.E}); 
    std::cout << Mat4 << std::endl;

    // 해상도 정보
    int nx = WindowInfo.ScreenWidth;
    int ny = WindowInfo.ScreenHeight;
    double d = -WindowInfo.Distance; // 스크린까지 거리

    glPointSize(1.0f);
    glBegin(GL_POINTS);  // 점 단위로 그리기 시작
    Sphere sphere{Vector(0, 0, 0), 2.0};    
    for (int j = 0; j < ny; ++j)
    {
        for (int i = 0; i < nx; ++i)
        {
            double px = (i - nx / 2.0 + 0.5);
            double py = (ny / 2.0 - j - 0.5);
            Vector pixelScreenSpace = {px, py, d, 1};
            Vector pixelWorld = Mat4 * pixelScreenSpace;
            Vector RayDir = (pixelWorld - CameraInfo.E).Normalization();
            Ray ray{CameraInfo.E, RayDir};
           
            // double a = RayDir.DotProduct(RayDir);
            // std::cout << "[" << i << "," << j << "] ray.Direction: " << RayDir << ", dot: " << a << std::endl;

            double t;
            if (sphere.Intersect(ray, t))
            {
                glColor3ub(0, 0, 255); // 교차: 파랑
            }
            else
            {
                glColor3ub(255, 0, 0); // 미교차: 빨강
            }
            if (i == nx / 2 && j == ny / 2) 
            {
                std::cout << "[중앙 픽셀]" << std::endl;
                std::cout << "pixelScreenSpace: " << pixelScreenSpace << std::endl;
                std::cout << "pixelWorld      : " << pixelWorld << std::endl;
                std::cout << "rayDir          : " << RayDir << std::endl;
                std::cout << "E               : " << CameraInfo.E << std::endl;
                if (sphere.Intersect(ray, t)) 
                {
                    std::cout << "✅ HIT!" << std::endl;
                } 
                else 
                {
                    std::cout << "❌ MISS" << std::endl;
                }
            }
            
            // std::cout << "Screen Space Pos: " << pixelScreenSpace << std::endl;
            // std::cout << "World Pos       : " << pixelWorld << std::endl;
            // std::cout << "Ray Direction   : " << RayDir << std::endl;

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
