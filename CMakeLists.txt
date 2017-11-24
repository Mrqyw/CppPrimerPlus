cmake_minimum_required(VERSION 3.8)
project(CppPrimerPlus)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp string/StringTest.cpp string/StringTest.h dynaticPtr/DynamicTest.cpp dynaticPtr/DynamicTest.h dynaticPtr/CircularReference.cpp dynaticPtr/CircularReference.h standardTemplateLibrary/Vec1.cpp standardTemplateLibrary/Vec1.h standardTemplateLibrary/Vec2.cpp standardTemplateLibrary/Vec2.h)
add_executable(CppPrimerPlus ${SOURCE_FILES})