//
// Created by Remi Peyras on 19/09/2021.
//

#include "Object3D.hpp"

using namespace Figure;

Object3D::Object3D(const std::string &name, std::vector<Point3D> listPoint) :
        IGLObject(name), _listPoints(std::move(listPoint)) {}

void Object3D::translation(const float &x, const float &y, const float &z) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [x, y, z](Point3D point) {
        point.translation(x, y, z);
    });
}

void Object3D::translation(const glm::vec3 &vector) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [vector](Point3D &point) {
        point.translation(vector);
    });
}

void Object3D::rotation(const Matrix::Axis &axis, const float &degrees) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [axis, degrees](Point3D &point) {
        point.rotation(axis, degrees);
    });
}

void Object3D::scaling(const float &x, const float &y, const float &z) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [x, y, z](Point3D &point) {
        point.scaling(x, y, z);
    });
}

void Object3D::scaling(const glm::vec3 &vector) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [vector](Point3D &point) {
        point.scaling(vector);
    });
}

void Object3D::reflexion(const Matrix::Axis &axis) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [axis](Point3D &point) {
        point.reflexion(axis);
    });
}

void Object3D::shearing(const Matrix::Axis &axis, const float &x, const float &y) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [axis, x, y](Point3D &point) {
        point.shearing(axis, x, y);
    });
}

/**
 * Method to do the shearing transformation
 * @param axis (Axis enabled X, Y, Z)
 * @param vector (X, Y)
 */
void Object3D::shearing(const Matrix::Axis &axis, const glm::vec2 &vector) {
    std::for_each(_listPoints.begin(), _listPoints.end(), [axis, vector](Point3D &point) {
        point.shearing(axis, vector);
    });
}

void Object3D::dump() {
    std::cout << "Name : " << _name << std::endl;
    std::for_each(_listPoints.begin(), _listPoints.end(), [](Point3D &point) {
        std::cout << point << std::endl;
    });
}

void Object3D::draw(const float &red, const float &green, const float &blue) {
    glColor3f(red, green, blue);
    glBegin(GL_LINE_LOOP);
    std::for_each(_listPoints.begin(), _listPoints.end(), [](Point3D &point) {
        glVertex3f(point.getPoint().x / 2, point.getPoint().y / 2, point.getPoint().z / 2);
    });
    glEnd();
}


void Object3D::setListPoint(std::vector<Point3D> &listPoints) {
    _listPoints = std::move(listPoints);
}

std::vector<Point3D> Object3D::getListPoints() const {
    return _listPoints;
}

std::ostream &operator<<(std::ostream &os, const Object3D &o) {
    std::vector<Point3D> listPoints = o.getListPoints();

    os << "Name : " << o.getName() << std::endl;
    std::for_each(listPoints.begin(), listPoints.end(), [&os](Point3D &point) {
        os << point << std::endl;
    });
    return os;
}
