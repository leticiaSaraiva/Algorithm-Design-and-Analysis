#ifndef CLOSESTPOINTS_HPP
#define CLOSESTPOINTS_HPP

#include <QPointF>

#include <utility>
#include <vector>

class ClosestPointsSolver{
public:
    static std::pair<QPointF, QPointF> solveFor(std::vector<QPointF> points);
};

class ClosestPointsSolverREC{
public:
    static std::pair<QPointF, QPointF> solveFor(std::vector<QPointF> pointsX);
};

class dist{
public:
    static float solveFor(QPointF p1, QPointF p2);
};

class bruteForce{
public:
    static std::pair<QPointF, QPointF> solveFor(std::vector<QPointF> point, int n);

};

class min{
public:
    static float solveFor(float x, float y);
};

class stripClosest{
public:
    static std::pair<QPointF, QPointF> solveFor(std::vector<QPointF> strip, int size, float d);
};

class Xfunction{
public:
    static bool solveFor(QPointF i, QPointF j);
};

class Yfunction{
public:
    static bool solveFor(QPointF i, QPointF j);
};

#endif // CLOSESTPOINTS_HPP
