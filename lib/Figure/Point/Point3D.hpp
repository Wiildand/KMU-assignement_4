//
// Created by Remi Peyras on 15/09/2021.
//

#ifndef CLION_MODERN_OPENGL_POINT3D_HPP
#define CLION_MODERN_OPENGL_POINT3D_HPP

#include "IGLObject.hpp"

namespace Figure {

    class Point3D : public IGLObject {
    public:
        explicit Point3D(const std::string &name = "A", const float &x = 0, const float &y = 0, const float &z = 0,
                         const float &s = 1);

        Point3D(const std::string &name, const glm::vec3 &vector, const float &s);

        Point3D(const std::string &name, const glm::vec4 &vector);

        ~Point3D() = default;

        void translation(const float &x = 0, const float &y = 0, const float &z = 0);

        void translation(const glm::vec3 &vector = glm::vec3(0, 0, 0));

        void rotation(const Matrix::Axis &axis, const float &degrees = 90);

        void scaling(const float &x = 1, const float &y = 1, const float &z = 1);

        void scaling(const glm::vec3 &vector = glm::vec3(1, 1, 1));

        void reflexion(const Matrix::Axis &axis) override;

        void shearing(const Matrix::Axis &axis, const float &x = 0, const float &y = 0);

        void shearing(const Matrix::Axis &axis, const glm::vec2 &vector = glm::vec2(0, 0));

        void dump() override;

        virtual void draw(const float &red, const float &green, const float &blue) override;

        [[nodiscard]] glm::vec4 getPoint() const;

        void setPoint(const float &x = 0, const float &y = 0, const float &z = 0, const float &s = 1);

        void setPoint(const glm::vec3 &vector = glm::vec3(0, 0, 0), const float &s = 1);

        void setPoint(const glm::vec4 &vector = glm::vec4(0, 0, 0, 1));

        friend std::ostream &operator<<(std::ostream &os, const Figure::Point3D &p);

    private:
        glm::vec4 _point;

        void _rotateAxisX(const float &degrees);

        void _rotateAxisY(const float &degrees);

        void _rotateAxisZ(const float &degrees);

        void _reflectionXToY();

        void _reflectionYToZ();

        void _reflectionXToZ();

        void _shearingAxisX(const float &x, const float &y);

        void _shearingAxisY(const float &x, const float &y);

        void _shearingAxisZ(const float &x, const float &y);
    };
}

#endif //CLION_MODERN_OPENGL_POINT3D_HPP
