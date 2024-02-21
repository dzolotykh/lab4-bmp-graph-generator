#include "BMP.h"

BMP::BMP(size_t _width, size_t _height)
    : width(_width), height(_height), pixels(_width * _height * 3) {
    std::fill(pixels.begin(), pixels.end(), 255);
}

void BMP::save(const std::string& path) const noexcept {
    std::ofstream outputFile(path, std::ios::binary);
    for (auto i : Header(width, height).get_bytes()) {
        outputFile.write(i.first, i.second);
    }
    outputFile.write(reinterpret_cast<const char*>(pixels.data()), Header(width, height).data_size);
    outputFile.close();
};

void BMP::draw_pixel(size_t x, size_t y, u_char r, u_char g, u_char b) noexcept {
    if (get_pos(x, y) + 2 >= pixels.size())
        return;
    pixels[get_pos(x, y)] = r;
    pixels[get_pos(x, y) + 1] = g;
    pixels[get_pos(x, y) + 2] = b;
}

void BMP::draw_segment(int x1, int y1, int x2, int y2) noexcept {
    int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
    dx = x2 - x1;
    dy = y2 - y1;
    dx1 = std::abs(dx);
    dy1 = std::abs(dy);
    px = 2 * dy1 - dx1;
    py = 2 * dx1 - dy1;
    if (dy1 <= dx1) {
        if (dx >= 0) {
            x = x1;
            y = y1;
            xe = x2;
        } else {
            x = x2;
            y = y2;
            xe = x1;
        }
        draw_pixel(x, y);
        for (i = 0; x < xe; i++) {
            x = x + 1;
            if (px < 0) {
                px = px + 2 * dy1;
            } else {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
                    y = y + 1;
                } else {
                    y = y - 1;
                }
                px = px + 2 * (dy1 - dx1);
            }
            draw_pixel(x, y);
        }
    } else {
        if (dy >= 0) {
            x = x1;
            y = y1;
            ye = y2;
        } else {
            x = x2;
            y = y2;
            ye = y1;
        }
        draw_pixel(x, y);
        for (i = 0; y < ye; i++) {
            y = y + 1;
            if (py <= 0) {
                py = py + 2 * dx1;
            } else {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
                    x = x + 1;
                } else {
                    x = x - 1;
                }
                py = py + 2 * (dx1 - dy1);
            }
            draw_pixel(x, y);
        }
    }
}

void BMP::draw_circle(int x1, int y1, int r) noexcept {
    for (int x = x1 - r; x <= x1 + r; x++) {
        for (int y = y1 - r; y <= y1 + r; y++) {
            if ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) < r * r) {
                draw_pixel(x, y);
            }
        }
    }
}
