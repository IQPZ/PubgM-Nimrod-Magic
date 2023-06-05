#pragma once

namespace ImGui {

    bool ToggleButton(const char* label, bool* v, int type, const ImVec2& size_arg = ImVec2(0, 0));
    // Combo box helper allowing to pass an array of strings.
    bool Combo(const char* label, int* currIndex, std::vector<std::string>& values);
    bool BeginGroupBox(const char* name, const ImVec2& size_arg = ImVec2(0, 0));
    void EndGroupBox();
    void Hotkey(int* k, const ImVec2& size_arg = ImVec2(0,0));
    bool ListBox(const char* label, int* current_item, std::string items[], int items_count, int height_items);
    bool ListBox(const char* label, int* current_item, std::function<const char* (int)> lambda, int items_count, int height_in_items);
    bool Combo(const char* label, int* current_item, std::function<const char* (int)> lambda, int items_count, int height_in_items);
    bool ComboBoxArray(const char* label, int* currIndex, std::vector<std::string>& values);

}

