cmake_minimum_required(VERSION 3.10)

project(tic-tac-toe)




add_executable(tic-tac-toe tris.c++)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(tic-tac-toe ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )