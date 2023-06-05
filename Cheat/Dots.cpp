#include "Includes.h"
std::vector<dot*> dots = { };

void dot::update() {
    auto opacity = 240 / 255.0f;

    m_pos += m_vel * (opacity);
}

void dot::draw() {
    int opacity = 55.0f * (240 / 255.0f);
    Color ColorDots = Color().FromHSB(Settings::Color::rainbow, 1.f, 1.f);
    if(!Settings::Menu::chroma_menu)
     GL3Draw::GetInstance()->RenderCircleFilled(ImVec2(m_pos.X - 2, m_pos.Y - 2), 3, D3DXCOLOR(Settings::Color::Menu::color[0], Settings::Color::Menu::color[1], Settings::Color::Menu::color[2], 1.f));
    else
    GL3Draw::GetInstance()->RenderCircleFilled(ImVec2( m_pos.X - 2, m_pos.Y - 2 ), 3, D3DXCOLOR(ColorDots.R, ColorDots.G, ColorDots.B, ColorDots.A));

    auto t = std::find(dots.begin(), dots.end(), this);
    if (t == dots.end()) {
        return;
    }

    for (auto i = t; i != dots.end(); i++) {
        if ((*i) == this) continue;

        auto dist = (m_pos - (*i)->m_pos).Size();

        if (dist < 128) {
            int alpha = opacity * (dist / 128);
            Color ColorLine = Color().FromHSB(Settings::Color::rainbow, 1.f, 1.f);
            if(!Settings::Menu::chroma_menu)
              GL3Draw::GetInstance()->RenderLine(ImVec2(m_pos.X - 1, m_pos.Y - 2), ImVec2((*i)->m_pos.X - 2, (*i)->m_pos.Y - 1), D3DXCOLOR(Settings::Color::Menu::color[0], Settings::Color::Menu::color[1], Settings::Color::Menu::color[2], 1.f));
            else
            GL3Draw::GetInstance()->RenderLine(ImVec2(m_pos.X - 1, m_pos.Y - 2 ), ImVec2((*i)->m_pos.X - 2, (*i)->m_pos.Y - 1 ), D3DXCOLOR(ColorLine.R, ColorLine.G, ColorLine.B, ColorLine.A));
        }
    }
}

void dot::dot_draw(int width, int height) {
    struct screen_size {
        int x, y;
    }; screen_size sc;

    sc.x = width, sc.y = height;
    GL3Draw::GetInstance()->RenderRectFilled(ImVec2(0,0), ImVec2(sc.x, sc.y),  D3DXCOLOR(0.f, 0.f, 0.f, 0.70f));

    int s = rand() % 24;

    if (s == 0) {
        dots.push_back(new dot(FVector2D(rand() % (int)sc.x, -16), FVector2D((rand() % 7) - 3, rand() % 3 + 1)));
    }
    else if (s == 1) {
        dots.push_back(new dot(FVector2D(rand() % (int)sc.x, (int)sc.y + 16), FVector2D((rand() % 7) - 3, -1 * (rand() % 3 + 1))));
    }
    else if (s == 2) {
        dots.push_back(new dot(FVector2D(-16, rand() % (int)sc.y), FVector2D(rand() % 3 + 1, (rand() % 7) - 3)));
    }
    else if (s == 3) {
        dots.push_back(new dot(FVector2D((int)sc.x + 16, rand() % (int)sc.y), FVector2D(-1 * (rand() % 3 + 1), (rand() % 7) - 3)));
    }

    auto alph = 135.0f * (240 / 255.0f);
    auto a_int = (int)(alph);

    GL3Draw::GetInstance()->RenderRectFilled(ImVec2( 0, 0 ), ImVec2((float)sc.x, (float)sc.y ), D3DXCOLOR(a_int, 0, 0, 0));

    for (auto i = dots.begin(); i < dots.end();) {
        if ((*i)->m_pos.Y < -20 || (*i)->m_pos.Y > sc.y + 20 || (*i)->m_pos.X < -20 || (*i)->m_pos.X > sc.x + 20) {
            delete (*i);
            i = dots.erase(i);
        }
        else {
            (*i)->update();
            i++;
        }
    }

    for (auto i = dots.begin(); i < dots.end(); i++) {
        (*i)->draw();
    }
}

void dot::dot_destroy() {
    for (auto i = dots.begin(); i < dots.end(); i++) {
        delete (*i);
    }

    dots.clear();
}