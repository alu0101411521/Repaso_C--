cmake_minimum_required(VERSION 3.1)     
 
project(fichero)                  
 
include_directories(include)                    

file(GLOB SRC                      
  "src/*.cc"
)
 
add_executable(${PROJECT_NAME} ${SRC})                  
 
 
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -fsanitize=address -pedantic-errors -Wall -Wextra -DDEBUG -ggdb")        
set(CMAKE_CXX_FLAGS_RELEASE "-O3")