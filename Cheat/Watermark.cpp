#include "Includes.h"

void Watermark::Show()
{
    char timebuff[80];
    time_t now = time(0);
    struct tm  tstruct;
    tstruct = *localtime(&now);
    std::stringstream ss;
    std::stringstream ss2;
    std::stringstream ss3;
    strftime(timebuff, sizeof(timebuff), "%X", &tstruct);
    ss << "Nimrod";
    auto screen_size = ImGui::GetIO().DisplaySize;
    auto fps_text_size = ImGui::CalcTextSize("Nimrod");
    auto start_pos = ImVec2(screen_size.x / 2.f - 240.f, (screen_size.y - fps_text_size.y - 7.f));
    auto end_pos = ImVec2(screen_size.x / 2.f + 240.f, screen_size.y);

    ImU32 start_color = ImGui::GetColorU32(ImVec4(0.1f, 0.1f, 0.1f, 1.f));
    ImU32 end_color = ImGui::GetColorU32(ImVec4(0.1f, 0.1f, 0.1f, 1.f));
    GL3Draw::GetInstance()->RenderRectFilled(start_pos, ImVec2(start_pos.x + 240.f, end_pos.y), start_color);
    GL3Draw::GetInstance()->RenderRectFilled(ImVec2(start_pos.x + 240.f, start_pos.y), end_pos, end_color);

    ImVec2 txt_size;
    txt_size = ImGui::CalcTextSize(ss.str().c_str());
    auto text_pos = ImVec2(start_pos.x + (480.f / 2) - (txt_size.x / 2), end_pos.y - 2.f - txt_size.y);

    if (!Settings::Menu::chroma_menu)
        outlined_text(ss.str().c_str(), text_pos, ImGui::GetColorU32(ImVec4(255, 255, 255, 255)));
    else
        outlined_text(ss.str().c_str(), text_pos, ImU32(ImColor::HSV(Settings::Color::rainbow, 1.f, 1.f, 1.f)));

    ss2 << timebuff << "   FPS: " << Globals::FPS<<"   ";
    txt_size = ImGui::CalcTextSize(ss2.str().c_str());
    text_pos = ImVec2(start_pos.x + (480.f / 2) - (txt_size.x / 2) - txt_size.x - 2.f, end_pos.y - 2.f - txt_size.y);
    outlined_text(ss2.str().c_str(), text_pos, ImGui::GetColorU32(ImVec4(255, 255, 255, 255)));

    ss3 << "   Coder Sh3rlock#3042";
    txt_size = ImGui::CalcTextSize(ss3.str().c_str());
    text_pos = ImVec2(start_pos.x + (480.f / 2) - (txt_size.x / 2) + txt_size.x + 1.f, end_pos.y - 2.f - txt_size.y);
    outlined_text(ss3.str().c_str(), text_pos, ImGui::GetColorU32(ImVec4(255, 255, 255, 255)));

}

void Watermark::outlined_text(const char* text, const ImVec2& pos, const ImU32& color)
{
    outlined_text(text, pos, color, ImGui::GetColorU32(ImVec4(0.f, 0.f, 0.f, 1.f)));
}

void Watermark::outlined_text(const char* text, const ImVec2& pos, const ImU32& color, const ImU32& outlined_color)
{
    GL3Draw::GetInstance()->RenderText(m_FVisuals, text,ImVec2((pos.x) + 1.f, (pos.y) + 1.f),12,outlined_color);
    GL3Draw::GetInstance()->RenderText(m_FVisuals, text,ImVec2((pos.x) + 1.f, (pos.y) - 1.f),12, outlined_color);
    GL3Draw::GetInstance()->RenderText(m_FVisuals,text,pos, 12,color);
}
Watermark* MAKER;
