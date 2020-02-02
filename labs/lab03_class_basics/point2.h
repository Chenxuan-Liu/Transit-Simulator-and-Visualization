class Point2{
public:
    Point2(float x = 0, float y = 0);
    float DistanceBetween(Point2 _Point2);
    int Quadrant();
    void Print();

private:
    float x;
    float y;
};