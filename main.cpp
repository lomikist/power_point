#include "controller.hpp"
#include <memory>

int main (int argc, char *argv[])
{
    std::shared_ptr<core::Controller> controller= std::make_shared<core::Controller>();
    controller->start();
    return 0;
}
