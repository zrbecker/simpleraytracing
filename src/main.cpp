//============================================================================
// Name        : RayTracing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Z3D.hpp"

#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace z3d;

class Context {
public:
    Context(uint32 width, uint32 height)
    : screen(width, height),
      eye_p(2, 4, 20), eye_u(1, 0, 0), eye_v(0, 1, 0), eye_w(0, 0, 1),
      frustum(-double(width) / height, double(width) / height, -1, 1, 4, 100) {

    }

    Ray CastRay(double x, double y) {
        double u = frustum.left + (frustum.right - frustum.left) * (x + 0.5) / screen.getWidth();
        double v = frustum.bottom + (frustum.top - frustum.bottom) * (y + 0.5) / screen.getHeight();

        return Ray(eye_p, -frustum.near * eye_w + u * eye_u + v * eye_v);
    }

    void Render() {
        uint32 width = screen.getWidth();
        uint32 height = screen.getHeight();

        vector<Shape *> shapes;
        shapes.push_back(new Sphere(Vector3d(-2, 4, 2), 1));
        shapes.push_back(new Sphere(Vector3d(0, 2, 0), 2));
        shapes.push_back(new Sphere(Vector3d(5, 5, -0.25), 0.5));
        shapes.push_back(new Plane(Vector3d(0, 1, 0), 0));
        shapes.push_back(new Plane(Vector3d(0, 0, 1), -10));
        shapes.push_back(new Plane(Vector3d(-1, 0, 0), -10));

        vector<Color> colors;
        colors.push_back(Color(120, 120, 255, 255));
        colors.push_back(Color(255, 120, 120, 255));
        colors.push_back(Color(255, 255, 120, 255));
        colors.push_back(Color(255, 255, 255, 255));
        colors.push_back(Color(255, 255, 255, 255));
        colors.push_back(Color(255, 255, 255, 255));

        Vector3d lightPos = Vector3d(-5, 5, 5);
        double intensity = 1;

        for (uint32 x = 0; x < width; ++x) {
            for (uint32 y = 0; y < height; ++y) {
                screen.setPixel(x, y, Color(0, 0, 0, 255));
                Ray ray = CastRay(x, y);

                bool hit = false;
                uint32 shape = 0;
                Intersection cur;
                for (uint32 i = 0; i < shapes.size(); ++i) {
                    Intersection next = ray.intersect(*shapes[i], frustum.near, frustum.far);
                    if (next.intersect) {
                        if (!cur.intersect || next.t < cur.t) {
                            hit = true;
                            shape = i;
                            cur = next;
                        }
                    }
                }

                if (hit) {
                    Vector3d light = lightPos - cur.intersection;
                    Ray shadowCheck(cur.intersection, light);
                    light = light / sqrt(dot(light, light));
                    double L = intensity * std::max(0.0, dot(cur.normal, light));

                    for (uint32 i = 0; i < shapes.size(); ++i) {
                        if (i == shape)
                            continue;
                        if (shadowCheck.intersect(*shapes[i], 0, 1).intersect) {
                            L *= 0.6;
                            break;
                        }
                    }

                    screen.setPixel(x, y, Color(L * colors[shape].r, L * colors[shape].g, L * colors[shape].b, 255));
                }
            }
        }
    }

public:
    Image screen;

    Vector3d eye_p;
    Vector3d eye_u, eye_v, eye_w;
    Frustum frustum;
};

int main() {
    unsigned int width = 800;
    unsigned int height = 500;

    Context cxt(width, height);
    cxt.Render();

    sf::RenderWindow window(sf::VideoMode(width, height), "Ray Tracing");
    sf::Texture texture;
    texture.create(width, height);
    texture.update(cxt.screen.getPixels());

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sf::Sprite(texture));
        window.display();
    }

    return 0;
}
