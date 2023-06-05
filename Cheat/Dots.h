#pragma once

class dot
{
private:
    void update();
    void draw();

public:
    dot(FVector2D p, FVector2D v) {
        m_vel = v;
        m_pos = p;
    }
    static void dot_draw(int width, int height);
    static void dot_destroy();
    FVector2D m_pos, m_vel;
};

