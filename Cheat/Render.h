#pragma once


class GL3Draw
{
public:
	static GL3Draw* GetInstance();
private:
	GL3Draw();
	~GL3Draw();
public:
	enum CrosshairStyle
	{
		Dot,
		Plus,
		Cross,
		Gap,
		Diagonal,
		Swastika,
		HitMaker
	};
	void BeginScene();
	void DrawScene();
	void EndScene();
	void AddImage(const ImVec2& position, const ImVec2& size, const ImTextureID pTexture, uint32_t color);
	float RenderText(ImFont* m_pFont, const std::string& text, const ImVec2& position, float size, uint32_t color, bool center = false);
	void DrawShadowText(ImFont* m_pFont, const std::string& text, const ImVec2& position, float size, uint32_t color, bool center = false);
	void RenderLine(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness = 1.0f);
	void RenderCircle(const ImVec2& position, float radius, uint32_t color, float thickness = 1.0f);
	void RenderCircleFilled(const ImVec2& position, float radius, uint32_t color);
	void RenderRect(const ImVec2& from, const ImVec2& to, uint32_t color, float rounding = 0.0f, uint32_t roundingCornersFlags = 0xF, float thickness = 1.0f);
	void RenderTriangle(const ImVec2& a, const ImVec2& b, const ImVec2& c, uint32_t color, float thickness = 1.0f);
	void RenderTriangleFilled(const ImVec2& Pa, const ImVec2& Pb, const ImVec2& Pc, uint32_t color);
	void RenderRectFilled(const ImVec2& from, const ImVec2& to, uint32_t color, float rounding = 0.0f, uint32_t roundingCornersFlags = 0xF);
	void HorizontalDrawHealth(int x, int y, int w, int h, float Health, float MaxHealth, D3DXCOLOR color1, D3DXCOLOR color2);
	void VerticalHealthBar(int x, int y, int w, int h, float Health, float MaxHealth, D3DXCOLOR color1, D3DXCOLOR color2);
	void DrawFillArea(float x, float y, float w, float h, D3DCOLOR color, float rounding = 0.f);
	void DrawBox(float X, float Y, float W, float H, D3DCOLOR Color, float thickness = 1.0f);
	void DrawBoxFilled(float X, float Y, float W, float H, D3DCOLOR Color);
	void DrawOutlineBox(int x, int y, int w, int h, D3DCOLOR color, float thickness = 1.0f);
	void DrawCoalBox(int x, int y, int w, int h, D3DCOLOR color, float thickness = 1.0f);
	void DrawOutlineCoalBox(int x, int y, int w, int h, D3DCOLOR color, float thickness = 1.0f);
	void GenuineBox(int x, int y, int w, int h, D3DCOLOR color, float thickness = 1.f);
	void GenuineOutlineBox(int x, int y, int w, int h, D3DCOLOR color, float thickness = 1.f);
	void DrawOctagonBox(int x, int y, int w, int h, D3DCOLOR color, float thickness = 1.f);
	void DrawOctagonCoalBox(int x, int y, int w, int h, D3DCOLOR color, float thickness = 1.f);
	void DrawWindow(int x, int y, int w, int h, D3DCOLOR Border, D3DCOLOR Background);
	void DrawCrosshair(CrosshairStyle style, float x, float y, float size, float stroke, D3DCOLOR color);
	void DrawDot(int x, int y, const D3DCOLOR color);

private:
	static GL3Draw* m_pInstance;
};




