cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME Graphics)
set(CMAKE_CXX_STANDARD 17)

set(WINDOW_NAME "Ray Tracing")
set(WINDOW_WIDTH 500)
set(WINDOW_HEIGHT 500)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/Math/Vector.cpp src/Math/Vector.h
    src/Math/Matrix.cpp src/Math/Matrix.h
    src/Render/Context.cpp src/Render/Context.h
)

include(Dependency.cmake)

target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})

target_compile_definitions(${PROJECT_NAME} PUBLIC
    WINDOW_NAME="${WINDOW_NAME}"
    WINDOW_WIDTH=${WINDOW_WIDTH}
    WINDOW_HEIGHT=${WINDOW_HEIGHT}
    )

add_dependencies(${PROJECT_NAME} ${DEP_LIST})    