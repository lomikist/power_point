#include "controller.hpp"
#include <memory>

int main (int argc, char *argv[])
{
    core::Controller& controller = core::Controller::get_instance();
    controller.start();
    return 0;
}
