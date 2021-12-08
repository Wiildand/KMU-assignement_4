//
// Created by Remi Peyras on 15/09/2021.
//

#include "Point2D.hpp"

using namespace Figure;

Point2D::Point2D(const std::string &name, const float &x, const float &y, const float &s) :
        IGLObject(name), _point(x, y, s) {}

Point2D::Point2D(const std::string &name, const glm::vec2 &vector, const float &s) :
        IGLObject(name), _point(vector.x, vector.y, s) {}

void Point2D::translation(const float &x, const float &y) {
    glm::mat3x3 matrix = glm::mat3x3(
            1, 0, x,
            0, 1, y,
            0, 0, 1
    );
    _point = matrix * _point;
}

void Point2D::translation(const glm::vec2 &vector) {
    translation(vector.x, vector.y);
}

void Point2D::rotation(const float &degrees) {
    glm::mat3x3 matrix = glm::mat3x3(
            glm::cos(glm::radians(degrees)), glm::sin(glm::radians(degrees)), 0,
            -glm::sin(glm::radians(degrees)), glm::cos(glm::radians(degrees)), 0,
            0, 0, 1
    );
    _point = matrix * _point;
}

void Point2D::scaling(const float &x, const float &y) {
    glm::mat3x3 matrix = glm::mat3x3(
            x, 0, 0,
            0, y, 0,
            0, 0, 1
    );
    _point = matrix * _point;
}

void Point2D::scaling(const glm::vec2 &vector) {
    scaling(vector.x, vector.y);
}

/**
 * Method to do a reflexion on AXIS
 * @param axis (Value enable : X, Y)
 */
void Point2D::reflexion(const Matrix::Axis &axis) {
    switch (axis) {
        case Matrix::Axis::X:
            _reflexionAxisX();
            break;
        case Matrix::Axis::Y:
            _reflexionAxisY();
            break;
        default:
            throw "Can't rotate on Axis Z";
    }
}

void Point2D::_reflexionAxisX() {
    glm::mat3x3 matrix = glm::mat3x3(
            1, 0, 0,
            0, -1, 0,
            0, 0, 1
    );
    _point = matrix * _point;
}

void Point2D::_reflexionAxisY() {
    glm::mat3x3 matrix = glm::mat3x3(
            1, 0, 0,
            0, -1, 0,
            0, 0, 1
    );
    _point = matrix * _point;
}

void Point2D::shearing(const Matrix::Axis &axis, const float &shearing) {
    switch (axis) {
        case Matrix::Axis::X:
            _shearingAxisX(shearing);
            break;
        case Matrix::Axis::Y:
            _shearingAxisY(shearing);
            break;
        default:
            throw "Can't shearing";
    }
}

void Point2D::_shearingAxisX(const float &shearing) {
    glm::mat3x3 matrix = glm::mat3x3(
            1, 0, 0,
            shearing, 1, 0,
            0, 0, 1
    );
    _point = matrix * _point;
}

void Point2D::_shearingAxisY(const float &shearing) {
    glm::mat3x3 matrix = glm::mat3x3(
            1, shearing, 0,
            0, 1, 0,
            0, 0, 1
    );
    _point = matrix * _point;
}

void Point2D::dump() {
    std::cout << _name << " ["
              << _point.x << ", "
              << _point.y << ", "
              << _point.s << "]"
              << std::endl;
}


glm::vec3 Point2D::getPoint() const {
    return _point;
}

void Point2D::setPoint(const float &x, const float &y, const float &s) {
    _point = glm::vec3(x, y, s);
}

void Point2D::setPoint(const glm::vec2 &vector, const float &s) {
    setPoint(vector.x, vector.y, s);
}

void Point2D::setPoint(const glm::vec3 &vector) {
    setPoint(vector.x, vector.y, vector.s);

}

void Point2D::draw(const float &red, const float &green, const float &blue) {
    return;
}

std::ostream &Figure::operator<<(std::ostream &os, const Point2D &p) {
    os << p.getName() << " [" << std::ceil(p.getPoint().x) << ", " << std::ceil(p.getPoint().y) << "]";
    return os;
}
