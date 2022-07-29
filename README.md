# ultralight-opengl-skeleton

## Create build files

Run from root:

```bash
cmake -B ./build/ -S . -DCMAKE_TOOLCHAIN_FILE=${vcpkg_install_path}/scripts/buildsystems/vcpkg.cmake -G "Visual Studio 17 2022" -A x64
```

## Dependencies

-   [glfw](https://github.com/glfw/glfw)
-   [glad](https://github.com/Dav1dde/glad)
-   [glm](https://github.com/g-truc/glm)
-   [spdlog](https://github.com/gabime/spdlog)
