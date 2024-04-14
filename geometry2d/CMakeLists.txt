
add_library(geometry2d
src/angle.cpp
src/geo_compare.cpp
src/line.cpp
src/point.cpp
src/pose.cpp
src/circle.cpp
)

target_link_libraries(geometry2d PUBLIC util)
target_include_directories(geometry2d PUBLIC include)
