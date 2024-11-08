# CMake의 최소 버전을 설정합니다.
cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름과 C++ 표준을 설정합니다.
project(VectorTemplateProject)
set(CMAKE_CXX_STANDARD 17)

# 소스 파일을 지정합니다.
add_executable(vector_template vector_template.cc
							   main.cc)

