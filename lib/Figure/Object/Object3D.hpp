//
// Created by Remi Peyras on 19/09/2021.
//

#ifndef CLION_MODERN_OPENGL_OBJECT3D_HPP
#define CLION_MODERN_OPENGL_OBJECT3D_HPP

#include "IGLObject.hpp"
#include "Point/Point3D.hpp"

namespace Figure {

    class Object3D : public Figure::IGLObject {

    public:
        explicit Object3D(const std::string &name, std::vector<Point3D> listPoint);

        ~Object3D() = default;

        void translation(const float &x = 0, const float &y = 0, const float &z = 0);

        void translation(const glm::vec3 &vector = glm::vec3(0, 0, 0));

        void rotation(const Matrix::Axis &axis, const float &degrees = 90);

        void scaling(const float &x = 1, const float &y = 1, const float &z = 1);

        void scaling(const glm::vec3 &vector = glm::vec3(1, 1, 1));

        void shearing(const Matrix::Axis &axis, const float &x = 0, const float &y = 0);

        void shearing(const Matrix::Axis &axis, const glm::vec2 &vector = glm::vec2(0, 0));

        void reflexion(const Matrix::Axis &axis) override;

        void dump() override;

        void draw(const float &red, const float &green, const float &blue) override;

        void setListPoint(std::vector<Point3D> &listPoints);

        [[nodiscard]] std::vector<Point3D> getListPoints() const;

    private:
        std::vector<Figure::Point3D> _listPoints;
    };
}

std::ostream &operator<<(std::ostream &os, const Figure::Object3D &o);


#endif //CLION_MODERN_OPENGL_OBJECT3D_HPP
