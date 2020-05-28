# SimpleMath

This is math library for Simple engine.

# How to use it

In your project directory create folder for git submodule

```console

mkdir modules
cd modules
git submodule add https://github.com/2dev2fun/SimpleMath.git

```

And attach SimpleMath library to your project in CMake.

```cmake
include_directories(modules/SimpleMath/source)
add_subdirectory(modules/SimpleMath)
target_link_libraries(${PROJECT_NAME} SimpleMath)
```
