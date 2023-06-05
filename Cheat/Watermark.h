#pragma once

class Watermark
{
public:
    void Show();
private:
    void outlined_text(const char* text, const ImVec2& pos, const ImU32& color);
    void outlined_text(const char* text, const ImVec2& pos, const ImU32& color, const ImU32& outlined_color);

};
extern Watermark* MAKER;

