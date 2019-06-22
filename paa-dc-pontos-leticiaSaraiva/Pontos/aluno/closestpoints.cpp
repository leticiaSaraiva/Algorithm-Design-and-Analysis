#include "closestpoints.hpp"
#include <cfloat>
#include <iostream>
#include <vector>

bool Xfunction (QPointF i, QPointF j) { return (i.x() < j.x()); }
bool Yfunction (QPointF i, QPointF j) { return (i.y() < j.y()); }

std::pair<QPointF, QPointF> ClosestPointsSolver::solveFor(std::vector<QPointF> points) {
    // TODO Implementar usando **Divisão e Conquista**
    // OBS Garantido ser chamado com pelo menos dois pontos.

    std::sort(points.begin(), points.end(), Xfunction);

    std::pair<QPointF, QPointF> pontos = ClosestPointsSolverREC::solveFor(std::move (points));

    return {pontos};

}

float dist(QPointF p1, QPointF p2) {
    return sqrt((p1.x() - p2.x())*(p1.x() - p2.x()) + (p1.y() - p2.y())*(p1.y() - p2.y()));
}

std::pair<QPointF, QPointF> bruteForce(std::vector<QPointF> point, int n){
    float min = FLT_MAX;
    std::pair<QPointF, QPointF> parMin;
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            if (dist(point[i], point[j]) < min){
                min = dist(point[i], point[j]);
                parMin.first = point[i];
                parMin.second = point[j];
            }
        }
    }
    return parMin;
}

float min(float x, float y){
    return (x < y)? x : y;
}

std::pair<QPointF, QPointF> stripClosest( std::vector<QPointF> strip, int size, float d){
    float min = d;

    std::sort(strip.begin(), strip.end(), Yfunction);
    std::pair<QPointF, QPointF> parMin;

    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y() - strip[i].y()) < min; ++j)
            if (dist(strip[i], strip[j]) < min) {
                min = dist(strip[i], strip[j]);
                parMin.first = strip[i];
                parMin.second = strip[j];
            }
    return parMin;
}

std::pair<QPointF, QPointF> ClosestPointsSolverREC::solveFor(std::vector<QPointF> pointsX){
    int n = pointsX.size();

    if(n <= 3){
        return bruteForce(pointsX, n);

    }else{
        int mid = floor(n/2);

        std::vector<QPointF> Q (pointsX.begin(), pointsX.begin() +  mid);
        std::vector<QPointF> R (pointsX.begin()+ mid, pointsX.end());


        std::vector<QPointF> RX = R;        
        std::vector<QPointF> QX = Q;

        std::pair<QPointF, QPointF> pontos1 = ClosestPointsSolverREC::solveFor(std::move (QX));
        std::pair<QPointF, QPointF> pontos2 = ClosestPointsSolverREC::solveFor(std::move (RX));

        float dQ = dist(pontos1.first, pontos1.second);
        float dR = dist(pontos2.first, pontos2.second);

        float d = min(dQ, dR);

        QPointF L = Q.back();

        std::vector<QPointF> strip;
        strip.reserve(n);

        int j = 0;
        for (int i = 0; i < n; i++){
            if (abs(pointsX[i].x() - L.x()) < d){
                strip.push_back(pointsX[i]);
                j++;
            }
        }

        std::pair<QPointF, QPointF> parMin;
        parMin = stripClosest(strip,j,d);

        float minimum = dist(parMin.first,parMin.second);

        if (minimum < d && minimum!= 0){
            return (parMin);
        }else if (dQ < dR){
            return (pontos1);
        }else{
            return (pontos2);
        }
    }
}
