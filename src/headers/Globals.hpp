#pragma once
#include <string>
#include <map>
#include "inpctrl.hpp"

inline std::string roblox_process_name;
inline unsigned short kb_layout;
inline CrossInput input;

// Debounces
inline bool events[4] {
    false, // Freeze
    false, // Laugh clip
    false, // E-Dance clip
    false, // For binding/changing keys
};

inline std::map<std::string, CrossInput::Key> Binds = {
    {"Freeze", CrossInput::Key::F1}, // Freeze
    {"Laugh", CrossInput::Key::F2}, // Laugh clip
    {"E-Dance", CrossInput::Key::F3} // Extended Dance
};