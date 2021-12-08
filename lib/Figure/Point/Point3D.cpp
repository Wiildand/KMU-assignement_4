//
// Created by Remi Peyras on 15/09/2021.
//

#include "Point3D.hpp"

using namespace Figure;

Point3D::Point3D(const std::string &name, const float &x, const float &y, const float &z, const float &s) :
        IGLObject(name), _point(x, y, z, s) {}

Point3D::Point3D(const std::string &name, const glm::vec3 &vector, const float &s) :
        IGLObject(name), _point(vector.x, vector.y, vector.z, s) {}

Point3D::Point3D(const std::string &name, const glm::vec4 &vector) :
        IGLObject(name), _point(vector.x, vector.y, vector.z, vector.s) {}

void Point3D::translation(const float &x, const float &y, const float &z) {
    glm::mat4x4 matrix = glm::mat4x4(
            1, 0, 0, x,
            0, 1, 0, y,
            0, 0, 1, z,
            0, 0, 0, 1
    );
    _point = matrix * _point;
}

void Point3D::translation(const glm::vec3 &vector) {
    translation(vector.x, vector.y, vector.z);
}

void Point3D::rotation(const Matrix::Axis &axis, const float &degrees) {
    switch (axis) {
        case Matrix::Axis::X:
            _rotateAxisX(degrees);
            break;
        case Matrix::Axis::Y:
            _rotateAxisY(degrees);
            break;
        case Matrix::Axis::Z:
            _rotateAxisZ(degrees);
            break;
        default:
            throw "Can't make rotation";
    }
}

void Point3D::_rotateAxisX(const float &degrees) {
    glm::mat4x4 matrix = glm::mat4x4(
            1, 0, 0, 0,
            0, glm::cos(glm::radians(degrees)), -glm::sin(glm::radians(degrees)), 0,
            0, -1 * glm::sin(glm::radians(degrees)), glm::cos(glm::radians(degrees)), 0,
            0, 0, 0, 1
    );
    _point = matrix * _point;
}

void Point3D::_rotateAxisY(const float &degrees) {
    glm::mat4x4 matrix = glm::mat4x4(
            glm::cos(glm::radians(degrees)), 0, -1 * glm::sin(glm::radians(degrees)), 0,
            0, 1, 0, 0,
            glm::sin(glm::radians(degrees)), 0, glm::cos(glm::radians(degrees)), 0,
            0, 0, 0, 1
    );
    _point = matrix * _point;
}

void Point3D::_rotateAxisZ(const float &degrees) {
    glm::mat4x4 matrix = glm::mat4x4(
            glm::cos(glm::radians(degrees)), glm::sin(glm::radians(degrees)), 0, 0,
            -1 * glm::sin(glm::radians(degrees)), glm::cos(glm::radians(degrees)), 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
    );
    _point = matrix * _point;
}

void Point3D::scaling(const float &x, const float &y, const float &z) {
    glm::mat4x4 matrix = glm::mat4x4(
            x, 0, 0, 0,
            0, y, 0, 0,
            0, 0, z, 0,
            0, 0, 0, 1
    );
    _point = matrix * _point;
}

void Point3D::scaling(const glm::vec3 &vector) {
    scaling(vector.x, vector.y, vector.z);
}

void Point3D::reflexion(const Matrix::Axis &axis) {
    switch (axis) {
        case Matrix::Axis::XY:
            _reflectionXToY();
            break;
        case Matrix::Axis::YZ:
            _reflectionYToZ();
            break;
        case Matrix::Axis::XZ:
            _reflectionXToZ();
            break;
        default:
            throw "Can't make reflexion";
    }
}

void Point3D::_reflectionXToY() {
    glm::mat4x4 matrix = glm::mat4x4(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, -1, 0,
            0, 0, 0, 1
    );
    _point = matrix * _point;
}

void Point3D::_reflectionYToZ() {
    glm::mat4x4 matrix = glm::mat4x4(
            -1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
    );
    _point = matrix * _point;
}

void Point3D::_reflectionXToZ() {
    glm::mat4x4 matrix = glm::mat4x4(
            1, 0, 0, 0,
            0, -1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
    );
    _point = matrix * _point;
}

void Point3D::shearing(const Matrix::Axis &axis, const float &x, const float &y) {
    switch (axis) {
        case Matrix::Axis::X:
            _shearingAxisX(x, y);
            break;
        case Matrix::Axis::Y:
            _shearingAxisY(x, y);
            break;
        case Matrix::Axis::Z:
            _shearingAxisZ(x, y);
            break;
        default:
            throw "Can't make reflexion";
    }
}

void Point3D::shearing(const Matrix::Axis &axis, const glm::vec2 &vector) {
    shearing(axis, vector.x, vector.y);
}

void Point3D::_shearingAxisX(const float &x, const float &y) {
    glm::mat4x4 matrix = glm::mat4x4(
            1, 0, 0, 0,
            x, 1, 0, 0,
            y, 0, 1, 0,
            0, 0, 0, 1
    );
    _point = matrix * _point;
}

void Point3D::_shearingAxisY(const float &x, const float &y) {
    glm::mat4x4 matrix = glm::mat4x4(
            1, x, 0, 0,
            0, 1, 0, 0,
            0, y, 1, 0,
            0, 0, 0, 1
    );
    _point = matrix * _point;
}

void Point3D::_shearingAxisZ(const float &x, const float &y) {
    glm::mat4x4 matrix = glm::mat4x4(
            1, 0, x, 0,
            0, 1, y, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
    );
    _point = matrix * _point;
}

void Point3D::dump() {
    std::cout << _name << " ["
              << _point.x << ", "
              << _point.y << ", "
              << _point.z << ", "
              << _point.s << "]"
              << std::endl;
}

glm::vec4 Point3D::getPoint() const {
    return _point;
}

void Point3D::setPoint(const float &x, const float &y, const float &z, const float &s) {
    _point = glm::vec4(x, y, z, s);
}

void Point3D::setPoint(const glm::vec3 &vector, const float &s) {
    setPoint(vector.x, vector.y, vector.z, s);
}

void Point3D::setPoint(const glm::vec4 &vector) {
    setPoint(vector.x, vector.y, vector.z, vector.s);

}

void Point3D::draw(const float &red, const float &green, const float &blue) {
    return;
}

std::ostream &Figure::operator<<(std::ostream &os, const Point3D &p) {
    os << p.getName() << " [" << std::ceil(p.getPoint().x) << ", " << std::ceil(p.getPoint().y) << ", "
       << std::ceil(p.getPoint().z) << "]";
    return os;
}
