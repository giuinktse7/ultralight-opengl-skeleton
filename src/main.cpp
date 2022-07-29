#include "app.h"

#include <spdlog/spdlog.h>

int main(int argc, char *argv[])
{
#ifdef _DEBUG
    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
#else
    spdlog::set_level(spdlog::level::info); // Set global log level to debug
#endif

    MainApp app;
    app.run();

    return 0;
}
