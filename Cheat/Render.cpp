#include "Includes.h"
GL3Draw* GL3Draw::m_pInstance;
GL3Draw::GL3Draw()
{
}

GL3Draw::~GL3Draw()
{
}
void GL3Draw::BeginScene()
{
	ImGuiIO& io = ImGui::GetIO();

	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0.0f, 0.0f });
	ImGui::PushStyleColor(ImGuiCol_WindowBg, { 0.0f, 0.0f, 0.0f, 0.0f });
	ImGui::Begin("##Backbuffer", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs);

	ImGui::SetWindowPos(ImVec2(0, 0), ImGuiCond_Always);
	ImGui::SetWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y), ImGuiCond_Always);
}
void GL3Draw::DrawScene()
{

	Misc::RunDraw();
	Visuals::RunDraw();
	Aimbot::RunDraw();

	if (Settings::Menu::drawdots && Globals::isopened)
		dot::dot_draw(Globals::width, Globals::height);

	if (Settings::Menu::watermark)
		MAKER->Show();

}
void GL3Draw::EndScene()
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	window->DrawList->PushClipRectFullScreen();

	ImGui::End();
	ImGui::PopStyleColor();
	ImGui::PopStyleVar(2);
}
void GL3Draw::AddImage(const ImVec2& position, const ImVec2& size, const ImTextureID pTexture, uint32_t color)
{
	auto window = ImGui::GetCurrentWindow();
	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;
	ImRect bb(position, ImVec2(position.x + size.x, position.y + size.y));

	window->DrawList->AddImage(pTexture, bb.Min, bb.Max, ImVec2(0.f, 0.f), ImVec2(1.f, 1.f), ImGui::GetColorU32({ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f }));
}
float GL3Draw::RenderText(ImFont* m_pFont, const std::string& text, const ImVec2& position, float size, uint32_t color, bool center)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;

	std::stringstream stream(text);
	std::string line;

	float y = 0.0f;
	int i = 0;

	while (std::getline(stream, line))
	{
		ImVec2 textSize = m_pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, line.c_str());

		if (center)
		{
			window->DrawList->AddText(m_pFont, size, { (position.x - textSize.x / 2.0f) + 1.0f, (position.y + textSize.y * i) + 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());
			window->DrawList->AddText(m_pFont, size, { (position.x - textSize.x / 2.0f) - 1.0f, (position.y + textSize.y * i) - 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());
			window->DrawList->AddText(m_pFont, size, { (position.x - textSize.x / 2.0f) + 1.0f, (position.y + textSize.y * i) - 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());
			window->DrawList->AddText(m_pFont, size, { (position.x - textSize.x / 2.0f) - 1.0f, (position.y + textSize.y * i) + 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());

			window->DrawList->AddText(m_pFont, size, { position.x - textSize.x / 2.0f, position.y + textSize.y * i }, ImGui::GetColorU32({ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f }), line.c_str());
		}
		else
		{
			window->DrawList->AddText(m_pFont, size, { (position.x) + 1.0f, (position.y + textSize.y * i) + 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());
			window->DrawList->AddText(m_pFont, size, { (position.x) - 1.0f, (position.y + textSize.y * i) - 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());
			window->DrawList->AddText(m_pFont, size, { (position.x) + 1.0f, (position.y + textSize.y * i) - 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());
			window->DrawList->AddText(m_pFont, size, { (position.x) - 1.0f, (position.y + textSize.y * i) + 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());

			window->DrawList->AddText(m_pFont, size, { position.x, position.y + textSize.y * i }, ImGui::GetColorU32({ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f }), line.c_str());
		}

		y = position.y + textSize.y * (i + 1);
		i++;
	}

	return y;
}
void GL3Draw::DrawShadowText(ImFont* m_pFont, const std::string& text, const ImVec2& position, float size, uint32_t color, bool center)
{
	RenderText(m_pFont, text, ImVec2(position.x - 1, position.y - 1), size, D3DXCOLOR(0.0, 0.0, 0.0, 1.0), center);
	RenderText(m_pFont, text, ImVec2(position.x + 1, position.y + 1), size, D3DXCOLOR(0.0, 0.0, 0.0, 1.0), center);
	RenderText(m_pFont, text, ImVec2(position.x, position.y), size, color, center);
}
void GL3Draw::RenderLine(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;

	window->DrawList->AddLine(from, to, ImGui::GetColorU32({ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f }), thickness);
}
void GL3Draw::RenderCircle(const ImVec2& position, float radius, uint32_t color, float thickness)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;

	window->DrawList->AddCircle(position, radius, ImGui::GetColorU32({ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f }), 0, thickness);
}
void GL3Draw::RenderCircleFilled(const ImVec2& position, float radius, uint32_t color)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;

	window->DrawList->AddCircleFilled(position, radius, ImGui::GetColorU32({ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f }), radius);
}
void GL3Draw::RenderRect(const ImVec2& from, const ImVec2& to, uint32_t color, float rounding, uint32_t roundingCornersFlags, float thickness)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float a = (color >> 24) & 0xFF;
	float r = (color >> 16) & 0xFF;
	float g = (color >> 8) & 0xFF;
	float b = (color) & 0xFF;

	window->DrawList->AddRect(from, to, ImGui::GetColorU32({ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f }), rounding, roundingCornersFlags, thickness);
}
void GL3Draw::RenderTriangle(const ImVec2& Pa, const ImVec2& Pb, const ImVec2& Pc, const uint32_t color, float thickness)
{
	auto window = ImGui::GetCurrentWindow();
	float a = (color >> 24) & 0xFF;
	float r = (color >> 16) & 0xFF;
	float g = (color >> 8) & 0xFF;
	float b = (color) & 0xFF;
	window->DrawList->AddTriangle(Pa, Pb, Pc, ImGui::GetColorU32(color));
}
void GL3Draw::RenderTriangleFilled(const ImVec2& Pa, const ImVec2& Pb, const ImVec2& Pc, uint32_t color)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	float a = (color >> 24) & 0xFF;
	float r = (color >> 16) & 0xFF;
	float g = (color >> 8) & 0xFF;
	float b = (color) & 0xFF;
	window->DrawList->AddTriangleFilled(Pa, Pb, Pc, ImGui::GetColorU32({ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f }));
}
void GL3Draw::RenderRectFilled(const ImVec2& from, const ImVec2& to, uint32_t color, float rounding, uint32_t roundingCornersFlags)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float a = (color >> 24) & 0xFF;
	float r = (color >> 16) & 0xFF;
	float g = (color >> 8) & 0xFF;
	float b = (color) & 0xFF;

	window->DrawList->AddRectFilled(from, to, ImGui::GetColorU32({ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f }), rounding, roundingCornersFlags);
}
void GL3Draw::HorizontalDrawHealth(int x, int y, int w, int h, float Health, float MaxHealth, D3DXCOLOR color1, D3DXCOLOR color2)
{
	if (Health <= 0)
		Health = 1;

	if (MaxHealth < Health)
		MaxHealth = 100;
	int size = (w * Health / (MaxHealth / 100)) / 100;
	DrawBox(x, y, w, h, D3DXCOLOR(0.f, 0.f, 0.f, 1.f), 1.f);
	this->DrawBoxFilled(x + 1, y + 1, w - 2, h - 2, color2);

	if (size == w)
		this->DrawBoxFilled(x + 1, y + 1, size - 2, h - 2, color1);
	else
		this->DrawBoxFilled(x + 1, y + 1, size, h - 2, color1);
}
void GL3Draw::VerticalHealthBar(int x, int y, int w, int h, float Health, float MaxHealth, D3DXCOLOR color1, D3DXCOLOR color2)
{
	if (Health <= 0)
		Health = 1;

	if (MaxHealth < Health)
		MaxHealth = 100;
	int size = (h * Health / (MaxHealth / 100)) / 100;

	this->DrawBox(x, y, w, h, D3DXCOLOR(0.f, 0.f, 0.f, 1.f), 1.f);
	this->DrawBoxFilled(x + 1, y + 1, w - 2, h - 2, color2);

	if (size == h)
		this->DrawBoxFilled(x + 1, y + 1 + h - size, w - 2, size - 2, color1);
	else
		this->DrawBoxFilled(x + 1, y + 1 + h - size, w - 2, size, color1);
}
void GL3Draw::DrawFillArea(float x, float y, float w, float h, D3DCOLOR color, float rounding)
{
	RenderRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), color, rounding);
}
void GL3Draw::DrawBox(float X, float Y, float W, float H, D3DCOLOR Color, float thickness)
{

	this->RenderRect(ImVec2(X + 1, Y + 1), ImVec2(((X + W) - 1), ((Y + H) - 1)), Color, 0.0f, 0xF, thickness);
	this->RenderRect(ImVec2(X, Y), ImVec2(X + W, Y + H), Color, 0.0f, 0xF, thickness);
}
void GL3Draw::DrawBoxFilled(float X, float Y, float W, float H, D3DCOLOR Color)
{

	this->RenderRectFilled(ImVec2(X + 1, Y + 1), ImVec2(((X + W) - 1), ((Y + H) - 1)), Color, 0.0f, 0xF);
	this->RenderRectFilled(ImVec2(X, Y), ImVec2(X + W, Y + H), Color, 0.0f, 0xF);
}
void GL3Draw::DrawOutlineBox(int x, int y, int w, int h, D3DCOLOR color, float thickness)
{
	this->DrawBox(x, y, w, h, D3DXCOLOR(0.f, 0.f, 0.f, 1.f), thickness);
	this->DrawBox(x + 1, y + 1, w - 2, h - 2, color, thickness);
	this->DrawBox(x + 2, y + 2, w - 4, h - 4, D3DXCOLOR(0.f, 0.f, 0.f, 1.f), thickness);
}
void GL3Draw::DrawCoalBox(int x, int y, int w, int h, D3DCOLOR color, float thickness)
{
	int iw = w / 4;
	int ih = h / 4;
	// top
	this->RenderLine(ImVec2(x, y), ImVec2(x + iw, y), color, thickness);					// left
	this->RenderLine(ImVec2(x + w - iw, y), ImVec2(x + w, y), color, thickness);			// right
	this->RenderLine(ImVec2(x, y), ImVec2(x, y + ih), color, thickness);					// top left
	this->RenderLine(ImVec2(x + w - 1, y), ImVec2(x + w - 1, y + ih), color, thickness);	// top right
	// bottom
	this->RenderLine(ImVec2(x, y + h), ImVec2(x + iw, y + h), color, thickness);			// left
	this->RenderLine(ImVec2(x + w - iw, y + h), ImVec2(x + w, y + h), color, thickness);	// right
	this->RenderLine(ImVec2(x, y + h - ih), ImVec2(x, y + h), color, thickness);			// bottom left
	this->RenderLine(ImVec2(x + w - 1, y + h - ih), ImVec2(x + w - 1, y + h), color, thickness);	// bottom right
}
void GL3Draw::DrawOutlineCoalBox(int x, int y, int w, int h, D3DCOLOR color, float thickness)
{
	int iw = w / 4;
	int ih = h / 4;

	DrawCoalBox(x, y, w, h, D3DXCOLOR(0.f, 0.f, 0.f, 1.f));

	// top left
	this->RenderLine(ImVec2(x + 1, y + 1), ImVec2(x + iw, y + 1), color, thickness);
	this->RenderLine(ImVec2(x + iw, y), ImVec2(x + iw, y + 2), D3DXCOLOR(0.f, 0.f, 0.f, 1.f), thickness);
	this->RenderLine(ImVec2(x + 1, y + 1), ImVec2(x + 1, y + ih), color);
	this->RenderLine(ImVec2(x, y + ih), ImVec2(x + 2, y + ih), D3DXCOLOR(0.f, 0.f, 0.f, 1.f), thickness);

	// top right
	this->RenderLine(ImVec2(x + w - iw, y + 1), ImVec2(x + w - 1, y + 1), color, thickness);
	this->RenderLine(ImVec2(x + w - iw - 1, y), ImVec2(x + w - iw, y + 2), D3DXCOLOR(0.f, 0.f, 0.f, 1.f), thickness);
	this->RenderLine(ImVec2(x + w - 2, y + 1), ImVec2(x + w - 2, y + ih), color, thickness);
	this->RenderLine(ImVec2(x + w - 2, y + ih), ImVec2(x + w, y + ih), D3DXCOLOR(0.f, 0.f, 0.f, 1.f), thickness);

	// bottom left
	this->RenderLine(ImVec2(x + 1, y + h - ih), ImVec2(x + 1, y + h), color, thickness);
	this->RenderLine(ImVec2(x, y + h - ih - 1), ImVec2(x + 2, y + h - ih - 1), D3DXCOLOR(0.f, 0.f, 0.f, 1.f), thickness);
	this->RenderLine(ImVec2(x + 1, y + h - 1), ImVec2(x + iw, y + h - 1), color, thickness);
	this->RenderLine(ImVec2(x + iw, y + h - 1), ImVec2(x + iw, y + h + 1), D3DXCOLOR(0.f, 0.f, 0.f, 1.f), thickness);

	// bottom right
	this->RenderLine(ImVec2(x + w - iw, y + h - 1), ImVec2(x + w - 1, y + h - 1), color, thickness);
	this->RenderLine(ImVec2(x + w - iw - 1, y + h - 1), ImVec2(x + w - iw, y + h + 1), D3DXCOLOR(0.f, 0.f, 0.f, 1.f), thickness);
	this->RenderLine(ImVec2(x + w - 2, y + h - ih), ImVec2(x + w - 2, y + h), color, thickness);
	this->RenderLine(ImVec2(x + w - 2, y + h - ih - 1), ImVec2(x + w, y + h - ih - 1), D3DXCOLOR(0.f, 0.f, 0.f, 1.f), thickness);

	this->DrawCoalBox(x + 2, y + 2, w - 4, h - 4, D3DXCOLOR(0.f, 0.f, 0.f, 1.f));
}
void GL3Draw::GenuineBox(int x, int y, int w, int h, D3DCOLOR color, float thickness)
{
	int iw = w / 4;
	int ih = h / 1;
	this->RenderLine(ImVec2(x, y), ImVec2(x + iw, y), color, thickness);
	this->RenderLine(ImVec2(x + w - iw, y), ImVec2(x + w, y), color, thickness);
	this->RenderLine(ImVec2(x, y), ImVec2(x, y + ih), color, thickness);
	this->RenderLine(ImVec2(x + w - 1, y), ImVec2(x + w - 1, y + ih), color, thickness);

	this->RenderLine(ImVec2(x, y + h), ImVec2(x + iw, y + h), color, thickness);
	this->RenderLine(ImVec2(x + w - iw, y + h), ImVec2(x + w, y + h), color, thickness);
	this->RenderLine(ImVec2(x, y + h - ih), ImVec2(x, y + h), color, thickness);
	this->RenderLine(ImVec2(x + w - 1, y + h - ih), ImVec2(x + w - 1, y + h), color, thickness);
}
void GL3Draw::GenuineOutlineBox(int x, int y, int w, int h, D3DCOLOR color, float thickness)
{
	int iw = w / 4;
	int ih = h / 1.001;

	GenuineBox(x, y, w, h, D3DXCOLOR(0, 0, 0, 1.f));

	this->RenderLine(ImVec2(x + 1, y + 1), ImVec2(x + iw, y + 1), color, thickness);
	this->RenderLine(ImVec2(x + iw, y), ImVec2(x + iw, y + 2), D3DXCOLOR(0, 0, 0, 1.f), thickness);
	this->RenderLine(ImVec2(x + 1, y + 1), ImVec2(x + 1, y + ih), color);
	this->RenderLine(ImVec2(x, y + ih), ImVec2(x + 2, y + ih), D3DXCOLOR(0, 0, 0, 1.f), thickness);

	this->RenderLine(ImVec2(x + w - iw, y + 1), ImVec2(x + w - 1, y + 1), color, thickness);
	this->RenderLine(ImVec2(x + w - iw - 1, y), ImVec2(x + w - iw, y + 2), D3DXCOLOR(0, 0, 0, 1.f), thickness);
	this->RenderLine(ImVec2(x + w - 2, y + 1), ImVec2(x + w - 2, y + ih), color, thickness);
	this->RenderLine(ImVec2(x + w - 2, y + ih), ImVec2(x + w, y + ih), D3DXCOLOR(0, 0, 0, 1.f), thickness);

	this->RenderLine(ImVec2(x + 1, y + h - ih), ImVec2(x + 1, y + h), color, thickness);
	this->RenderLine(ImVec2(x, y + h - ih - 1), ImVec2(x + 2, y + h - ih - 1), D3DXCOLOR(0, 0, 0, 1.f), thickness);
	this->RenderLine(ImVec2(x + 1, y + h - 1), ImVec2(x + iw, y + h - 1), color, thickness);
	this->RenderLine(ImVec2(x + iw, y + h - 1), ImVec2(x + iw, y + h + 1), D3DXCOLOR(0, 0, 0, 1.f), thickness);

	this->RenderLine(ImVec2(x + w - iw, y + h - 1), ImVec2(x + w - 1, y + h - 1), color, thickness);
	this->RenderLine(ImVec2(x + w - iw - 1, y + h - 1), ImVec2(x + w - iw, y + h + 1), D3DXCOLOR(0, 0, 0, 1.f), thickness);
	this->RenderLine(ImVec2(x + w - 2, y + h - ih), ImVec2(x + w - 2, y + h), color, thickness);
	this->RenderLine(ImVec2(x + w - 2, y + h - ih - 1), ImVec2(x + w, y + h - ih - 1), D3DXCOLOR(0, 0, 0, 1.f), thickness);

	GenuineBox(x + 2, y + 2, w - 4, h - 4, D3DXCOLOR(0, 0, 0, 1.f));
}
void GL3Draw::DrawOctagonBox(int x, int y, int w, int h, D3DCOLOR color, float thickness)
{
	int iw = w / 4;
	int ih = h / 4;


	this->RenderLine(ImVec2(x, y), ImVec2(x + w, y), color, thickness);
	this->RenderLine(ImVec2((x + w) + iw, y + ih), ImVec2(x + w, y), color, thickness);
	this->RenderLine(ImVec2(x - iw, y + ih), ImVec2(x, y), color, thickness);

	this->RenderLine(ImVec2(x - iw, y + h - ih), ImVec2(x - iw, y + ih), color, thickness);
	this->RenderLine(ImVec2((x + w) + iw, y + h - ih), ImVec2(x + w + iw, y + ih), color, thickness);

	this->RenderLine(ImVec2(x, y + h), ImVec2(x + w, y + h), color, thickness);
	this->RenderLine(ImVec2((x + w) + iw, (y + h) - ih), ImVec2(x + w, y + h), color, thickness);
	this->RenderLine(ImVec2(x - iw, (y + h) - ih), ImVec2(x, y + h), color, thickness);
}
void GL3Draw::DrawOctagonCoalBox(int x, int y, int w, int h, D3DCOLOR color, float thickness)
{
	int iw = w / 4;
	int ih = h / 4;

	float wh = w + h / 2;

	this->RenderLine(ImVec2(x, y), ImVec2(x + w, y), color, thickness);
	this->RenderLine(ImVec2((x + w) + iw, y + ih), ImVec2(x + w, y), color, thickness);
	this->RenderLine(ImVec2(x - iw, y + ih), ImVec2(x, y), color, thickness);

	this->RenderLine(ImVec2(x, y + h), ImVec2(x + w, y + h), color, thickness);
	this->RenderLine(ImVec2((x + w) + iw, (y + h) - ih), ImVec2(x + w, y + h), color, thickness);
	this->RenderLine(ImVec2(x - iw, (y + h) - ih), ImVec2(x, y + h), color, thickness);
}

void GL3Draw::DrawWindow(int x, int y, int w, int h, D3DCOLOR Border, D3DCOLOR Background)
{
	DrawBox(x, y, w, h, Border, 1.f);
	DrawBoxFilled(x + 1, y + 1, w - 2, h - 2, Background);
}
void GL3Draw::DrawCrosshair(CrosshairStyle style, float x, float y, float size, float stroke, D3DCOLOR color)
{
	if (style == CrosshairStyle::Dot)
	{
		this->RenderCircleFilled(ImVec2(x, y), size, color);
	}
	else if (style == CrosshairStyle::Plus)
	{
		this->RenderLine(ImVec2(x - size, y), ImVec2(x + size, y), color, stroke);
		this->RenderLine(ImVec2(x, y - size), ImVec2(x, y + size), color, stroke);
	}
	else if (style == CrosshairStyle::Cross)
	{
		this->RenderLine(ImVec2(x - size, y - size), ImVec2(x + size, y + size), color, stroke);
		this->RenderLine(ImVec2(x + size, y - size), ImVec2(x - size, y + size), color, stroke);
	}
	else if (style == CrosshairStyle::Gap)
	{
		this->RenderLine(ImVec2(x - size - stroke, y), ImVec2(x - stroke, y), color, stroke);
		this->RenderLine(ImVec2(x + size + stroke, y), ImVec2(x + stroke, y), color, stroke);
		this->RenderLine(ImVec2(x, y - size - stroke), ImVec2(x, y - stroke), color, stroke);
		this->RenderLine(ImVec2(x, y + size + stroke), ImVec2(x, y + stroke), color, stroke);
	}
	else if (style == CrosshairStyle::Diagonal)
	{
		this->RenderLine(ImVec2(x - size, y - size), ImVec2(x + size, y + size), color, stroke);
		this->RenderLine(ImVec2(x + size, y - size), ImVec2(x - size, y + size), color, stroke);
	}
	else if (style == CrosshairStyle::Swastika)
	{
		ImVec2 first = ImVec2(x - size, y);
		ImVec2 second = ImVec2(x + size, y);
		ImVec2 third = ImVec2(x, y - size);
		ImVec2 fourth = ImVec2(x, y + size);
		ImVec2 haken_1 = ImVec2(third.x + size, third.y);
		ImVec2 haken_2 = ImVec2(second.x, second.y + size);
		ImVec2 haken_3 = ImVec2(fourth.x - size, fourth.y);
		ImVec2 haken_4 = ImVec2(first.x, first.y - size);
		this->RenderLine(first, second, color, stroke);
		this->RenderLine(third, fourth, color, stroke);
		this->RenderLine(third, haken_1, color, stroke);
		this->RenderLine(second, haken_2, color, stroke);
		this->RenderLine(fourth, haken_3, color, stroke);
		this->RenderLine(first, haken_4, color, stroke);
	}
	else if (style == CrosshairStyle::HitMaker)
	{
		float flScreenPosCenter[2];
		flScreenPosCenter[0] = x;
		flScreenPosCenter[1] = y;

		const int iLineSize = size;

		this->RenderLine(ImVec2(flScreenPosCenter[0] - iLineSize, flScreenPosCenter[1] - iLineSize), ImVec2(flScreenPosCenter[0] - (iLineSize / 4), flScreenPosCenter[1] - (iLineSize / 4)), color, stroke);
		this->RenderLine(ImVec2(flScreenPosCenter[0] - iLineSize, flScreenPosCenter[1] + iLineSize), ImVec2(flScreenPosCenter[0] - (iLineSize / 4), flScreenPosCenter[1] + (iLineSize / 4)), color, stroke);
		this->RenderLine(ImVec2(flScreenPosCenter[0] + iLineSize, flScreenPosCenter[1] + iLineSize), ImVec2(flScreenPosCenter[0] + (iLineSize / 4), flScreenPosCenter[1] + (iLineSize / 4)), color, stroke);
		this->RenderLine(ImVec2(flScreenPosCenter[0] + iLineSize, flScreenPosCenter[1] - iLineSize), ImVec2(flScreenPosCenter[0] + (iLineSize / 4), flScreenPosCenter[1] - (iLineSize / 4)), color, stroke);

	}
}
void GL3Draw::DrawDot(int x, int y, const D3DCOLOR color)
{
	int Thickness;
	Thickness = (int)5;
	int thickness = Thickness - 1;

	DrawFillArea(x - thickness, y - thickness, Thickness, Thickness, color);
}
GL3Draw* GL3Draw::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new GL3Draw();

	return m_pInstance;
}

