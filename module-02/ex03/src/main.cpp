#include <cstdlib>

#include "Point.hpp"

// Function calculates the area of a triangle
static float get_area_triangle(float side1, float side2, float side3) {
  float s = (side1 + side2 + side3) / 2;
  return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

// Triangle (a, b, c) = Triangle (point, a, c) + Triangle (point, b, c) + Triangle (point, a, b)
// 1. first calculate the area of all the triangles
static bool bsp(Point const a, Point const b, Point const c, Point const point) {
  float area_triangle_main = get_area_triangle(point.getX() - a.getX(), point.getY() - a.getY(), c.getX() - a.getX());
  float area_triangle_a    = get_area_triangle(point.getX() - a.getX(), point.getY() - a.getY(), b.getX() - a.getX());
  float area_triangle_b    = get_area_triangle(point.getX() - b.getX(), point.getY() - b.getY(), c.getX() - b.getX());
  float area_triangle_c    = get_area_triangle(point.getX() - c.getX(), point.getY() - c.getY(), a.getX() - c.getX());
  // 2. if the area of all the triangles is equal to the area of the main triangle, then the point is inside the
  // triangle
  return (area_triangle_main == area_triangle_a + area_triangle_b + area_triangle_c);
}

int main(void) {
  Point a(0, 0);
  Point b(0, 1);
  Point c(1, 0);
  Point point(0.5, 0.5);
  Point point2(2.0, 2.0);

  if (bsp(a, b, c, point)) {
    std::cout << "The first point is inside the triangle" << std::endl;
  } else {
    std::cout << "The first point is outside the triangle" << std::endl;
  }

  if (bsp(a, b, c, point2)) {
    std::cout << "The second point is inside the triangle" << std::endl;
  } else {
    std::cout << "The second point is outside the triangle" << std::endl;
  }
  return EXIT_SUCCESS;
}
