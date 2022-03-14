#pragma once
#include "window_manager.h"

int main()
{
    rend_eng::WindowManager manager;
    manager.init(800, 800);
    manager.update();
    
}