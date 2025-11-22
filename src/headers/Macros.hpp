#pragma once
#include "Globals.hpp"
#include "Helper.hpp"

inline void freezeMacro() {
    bool key_pressed = input.isKeyPressed(Binds["Freeze"]);

    if (key_pressed && !events[0]) {
        log("Freeze triggered for " + roblox_process_name);
        procctrl::suspend_processes_by_name(roblox_process_name);
    }

    if (!key_pressed && events[0]) {
        log("Unfreeze triggered for " + roblox_process_name);
        procctrl::resume_processes_by_name(roblox_process_name);
    }
    events[0] = key_pressed;
}

inline void laughClip() {
    bool key_pressed = input.isKeyPressed(Binds["Laugh"]);
    if (key_pressed && !events[1]) {
        events[1] = true;
        log("Laugh clip triggered");

        input.pressKey(CrossInput::Key::Slash);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        if (kb_layout == 1) {
            typeSlash();
            input.typeText("e lqugh");
            input.pressKey(CrossInput::Key::Enter);
        } else {
            input.typeText("/e laugh");
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(248));
        input.holdKey(CrossInput::Key::S);
        procctrl::suspend_processes_by_name(roblox_process_name);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        procctrl::resume_processes_by_name(roblox_process_name);

        input.holdKey(CrossInput::Key::Space);
        input.holdKey(CrossInput::Key::LShift);

        std::this_thread::sleep_for(std::chrono::milliseconds(35));

        input.releaseKey(CrossInput::Key::Space);
        input.releaseKey(CrossInput::Key::LShift);
        
        std::this_thread::sleep_for(std::chrono::milliseconds(40));

        input.releaseKey(CrossInput::Key::S);

        events[1] = false;
        log("Laugh clip finished");
    }
}

inline void extendedDanceClip() {
    bool key_pressed = input.isKeyPressed(Binds["E-Dance"]);
    if (key_pressed && !events[2]) {
        events[2] = true;
        log("Extended Dance clip triggered");

        input.pressKey(CrossInput::Key::Slash);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        if (kb_layout == 1) {
            typeSlash();
            input.typeText("e dqnce");
            input.holdKey(CrossInput::Key::LShift);
            input.pressKey(CrossInput::Key::Num2);
            input.releaseKey(CrossInput::Key::LShift);
            std::this_thread::sleep_for(std::chrono::milliseconds(30));
            input.pressKey(CrossInput::Key::Enter);
        } else {
            input.typeText("/e dance2");
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(815));

        input.holdKey(CrossInput::Key::D);
        procctrl::suspend_processes_by_name(roblox_process_name);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        procctrl::resume_processes_by_name(roblox_process_name);

        input.pressKey(CrossInput::Key::LShift);

        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        input.releaseKey(CrossInput::Key::D);

        events[2] = false;
        log("Extended Dance clip finished");
    }
}