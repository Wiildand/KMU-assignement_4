//
// Created by Remi Peyras on 19/09/2021.
//

#include "Object2D.hpp"

using namespace Figure;


Object2D::Object2D(const std::string &name, std::vector<Point2D> listPoint) :
        IGLObject(name), _listPoints(std::move(listPoint)) {}


void Object2D::translation(const float &x, const float &y) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [x, y](Point2D &point) {
        point.translation(x, y);
    });
}

void Object2D::translation(const glm::vec2 &vector) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [vector](Point2D &point) {
        point.translation(vector);
    });
}

void Object2D::rotation(const float &degrees) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [degrees](Point2D &point) {
        point.rotation(degrees);
    });
}

void Object2D::scaling(const float &x, const float &y) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [x, y](Point2D &point) {
        point.scaling(x, y);
    });
}

void Object2D::scaling(const glm::vec2 &vector) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [vector](Point2D &point) {
        point.scaling(vector);
    });
}

void Object2D::reflexion(const Matrix::Axis &axis) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [axis](Point2D &point) {
        point.reflexion(axis);
    });
}

void Object2D::shearing(const Matrix::Axis &axis, const float &shearing) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [axis, shearing](Point2D &point) {
        point.shearing(axis, shearing);
    });
}

void Object2D::dump() {
    std::cout << "Name : " << _name << std::endl;
    std::for_each(_listPoints.begin(), _listPoints.end(), [](Point2D &point) {
        std::cout << point << std::endl;
    });
}

void Object2D::draw(const float &red, const float &green, const float &blue) {
    glBegin(GL_POINTS);
    glColor3f(red, green, blue);
    std::for_each(_listPoints.begin(), _listPoints.end(), [](Point2D &point) {
        glVertex2f(point.getPoint().x / 2, point.getPoint().y / 2);
    });
    glEnd();
    glFlush();
}

void Object2D::setListPoint(std::vector<Point2D> &listPoints) {
    _listPoints = std::move(listPoints);
}

std::vector<Point2D> Object2D::getListPoints() const {
    return _listPoints;
}

std::ostream &Figure::operator<<(std::ostream &os, const Object2D &o) {
    std::vector<Point2D> listPoints = o.getListPoints();

    os << "Name : " << o.getName() << std::endl;
    std::for_each(listPoints.begin(), listPoints.end(), [&os](Point2D &point) {
        os << point << std::endl;
    });
    return os;
}




