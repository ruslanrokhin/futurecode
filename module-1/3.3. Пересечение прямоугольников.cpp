#include <iostream>
#include <cassert>
#include <string>

using namespace std;
struct Point
{
  Point() = default;
  Point(int x, int y)
  {
    x_ = x;
    y_ = y;
  }

  int x_ = 0, y_ = 0;
};

ostream &operator<<(ostream &out, Point &point)
{
  cout << point.x_ << " " << point.y_;
  return out;
}

inline int Max(int x1, int x2)
{
  return x1 > x2 ? x1 : x2;
}
inline int Min(int x1, int x2)
{
  return x1 < x2 ? x1 : x2;
}

struct Rect
{
  Point point1_, point2_;

  Rect() = default;
  Rect(Point point1, Point point2)
  {
    point1_ = point1;
    point2_ = point2;
  }
  bool True() const
  {
    return point1_.x_ <= point2_.x_ && point1_.y_ <= point2_.y_;
  }

  Rect Intersection(const Rect &rect2) const
  {
    Point point1, point2;
    point1.x_ = Max(point1_.x_, rect2.point1_.x_);
    point1.y_ = Max(point1_.y_, rect2.point1_.y_);
    point2.x_ = Min(point2_.x_, rect2.point2_.x_);
    point2.y_ = Min(point2_.y_, rect2.point2_.y_);
    Rect result(point1, point2);
    return result;
  }
};

istream &operator>>(istream &in, Rect &rect)
{
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  rect.point1_ = {x1, y1};
  rect.point2_ = {x2, y2};
  return in;
}
ostream &operator<<(ostream &out, Rect &rect)
{
  cout << rect.point1_ << " " << rect.point2_;
  return out;
}

Rect Intersection(const Rect &rect1, const Rect &rect2)
{
  Point point1, point2;
  point1.x_ = Max(rect1.point1_.x_, rect2.point1_.x_);
  point1.y_ = Max(rect1.point1_.y_, rect2.point1_.y_);
  point2.x_ = Min(rect1.point2_.x_, rect2.point2_.x_);
  point2.y_ = Min(rect1.point2_.y_, rect2.point2_.y_);
  Rect result(point1, point2);
  return result;
}

int main()
{
  int n;
  Rect rect;
  cin >> n;
  cin >> rect;
  for (unsigned i = 1; i < n; ++i)
  {
    Rect second_rect;
    cin >> second_rect;
    rect = Intersection(rect, second_rect);
    if (!rect.True())
    {
      cout << -1;
      return 0;
    }
  }
  cout << rect;
  return 0;
}