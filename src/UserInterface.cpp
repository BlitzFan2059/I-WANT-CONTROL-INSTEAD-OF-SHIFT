#include "UserInterface.hpp"
#include "imgui.h"
#include "rlImGui.h"
#include "Globals.hpp"
#include "inpctrl.hpp"
#include "Helper.hpp"

void initUI() {
    // Initialize rlImGui
    rlImGuiSetup(true);
    ImGuiStyle& style = ImGui::GetStyle();

    // Make all buttons red
    style.Colors[ImGuiCol_Button] = ImVec4(0.8f, 0.1f, 0.1f, 1.0f);       // normal
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.0f, 0.2f, 0.2f, 1.0f); // hover
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.7f, 0.0f, 0.0f, 1.0f);  // pressed

    // Tab colors (make them red like your buttons)
    style.Colors[ImGuiCol_Tab] = ImVec4(0.8f, 0.1f, 0.1f, 1.0f);              // inactive tab
    style.Colors[ImGuiCol_TabHovered] = ImVec4(1.0f, 0.2f, 0.2f, 1.0f);       // tab on hover
    style.Colors[ImGuiCol_TabActive] = ImVec4(1.0f, 0.3f, 0.3f, 1.0f);        // active/selected tab
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.6f, 0.1f, 0.1f, 1.0f);     // inactive when window unfocused
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.8f, 0.2f, 0.2f, 1.0f); // active when window unfocused

    // Make tabs square (remove rounding)
    style.TabRounding = 0.0f;
}

void UpdateUI() {
    // Fullscreen window
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(GetScreenWidth(), GetScreenHeight()));
    ImGui::Begin("3443's Roblox Utilities", nullptr,
                ImGuiWindowFlags_NoTitleBar |
                ImGuiWindowFlags_NoResize |
                ImGuiWindowFlags_NoMove |
                ImGuiWindowFlags_NoCollapse);
    ImGui::Text("3443's Roblox Utilities");
    ImGui::Separator();
    // Tab Bar
    if (ImGui::BeginTabBar("MainTabBar")) {
        
        // MACRO TAB
        if (ImGui::BeginTabItem("Macros")) {
            
            // ---------- LAYOUT ----------
            ImVec2 window_size = ImGui::GetContentRegionAvail();
            float left_width = 200.0f;
            
            // LEFT PANEL: scrollable buttons
            ImGui::BeginChild("Left Panel", ImVec2(left_width, window_size.y), true, ImGuiWindowFlags_AlwaysVerticalScrollbar);
            
            // Helper lambda for buttons with expandable frame
            auto DrawOptionButton = [&](const char* label) {
                if (ImGui::Button(label, ImVec2(-1, 20))) {
                    // Toggle panel visibility
                    if (current_option == label)
                        current_option = "";
                    else
                        current_option = label;
                }
                if (current_option == label) {
                    ImGui::BeginChild(std::string(label + std::string("_frame")).c_str(), ImVec2(0, 100), true);
                    ImGui::TextWrapped("Keybind: ");
                    // keybind settings inside frame
                    if (std::string(label) == "Freeze") {
                        ImGui::Text("Current keybind %s", input.getKeyName(Binds["Freeze"]).c_str());
                        if (ImGui::Button("Change", ImVec2(-1, 20.0f))) {
                            bindToMacro("Freeze");
                        }
                    } else if (std::string(label) == "Laugh Clip") {
                        ImGui::Text("Current keybind %s", input.getKeyName(Binds["Laugh"]).c_str());
                        if (ImGui::Button("Change", ImVec2(-1, 20.0f))) {
                            bindToMacro("Laugh");
                        }
                    } else if (std::string(label) == "Extended Dance Clip") {
                        ImGui::Text("Current keybind %s", input.getKeyName(Binds["E-Dance"]).c_str());
                        if (ImGui::Button("Change", ImVec2(-1, 20.0f))) {
                            bindToMacro("E-Dance");
                        }
                    }
                    ImGui::EndChild();
                }
            };
            
            // Draw buttons
            DrawOptionButton("Freeze");
            DrawOptionButton("Laugh Clip");
            DrawOptionButton("Extended Dance Clip");
            
            ImGui::EndChild();
            
            // RIGHT PANEL: Use 0,0 to auto-fill remaining space
            ImGui::SameLine();
            ImGui::BeginChild("Right Panel", ImVec2(0, 0), true);
            if (current_option == "Freeze") {
                ImGui::Text("Freeze information:");
                ImGui::TextWrapped("This macro freezes the roblox/sober process.\nIt allows for some pretty cool glitches.");
            } else if (current_option == "Laugh Clip") {
                ImGui::Text("Laugh Clip information:");
                ImGui::TextWrapped("This macro allows you to clip through walls of 1+ studs of thickness.");
            } else if (current_option == "Extended Dance Clip") {
                ImGui::Text("Extended Dance Clip information:");
                ImGui::TextWrapped("This macro allows you to clip through walls of 1+ studs of thickness.\nPlease set up the camera like below:"); 
            }
            ImGui::EndChild();
            
            ImGui::EndTabItem();
        }
        
        // Settings
        if (ImGui::BeginTabItem("Lag-switch")) {
            ImGui::Text("Settings content here");
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Setiings")) {
            ImGui::Text("Settings content here");
            ImGui::EndTabItem();
        }
        
        ImGui::EndTabBar();
    }
    
    ImGui::End();
}