set(PROJECT_NAME ArithmeticExpressionMain)
project(${PROJECT_NAME})
file(GLOB_RECURSE SOURCES *cpp *h)
add_executable(${PROJECT_NAME} ${SOURCES})