//
// Created by Remi Peyras on 15/09/2021.
//

#ifndef CLION_MODERN_OPENGL_POINT2D_HPP
#define CLION_MODERN_OPENGL_POINT2D_HPP

#include "IGLObject.hpp"

namespace Figure {

    class Point2D : public IGLObject {
    public:
        explicit Point2D(const std::string &name = "A", const float &x = 0, const float &y = 0, const float &s = 1);

        Point2D(const std::string &name, const glm::vec2 &vector, const float &s = 1);

        ~Point2D() = default;

        void translation(const float &x = 0, const float &y = 0);

        void translation(const glm::vec2 &vector = glm::vec2(0, 0));

        void rotation(const float &degrees);

        void scaling(const float &x = 1, const float &y = 1);

        void scaling(const glm::vec2 &vector = glm::vec2(1, 1));

        void reflexion(const Matrix::Axis &axis) override;

        void shearing(const Matrix::Axis &axis, const float &shearing = 0);

        void dump() override;

        void draw(const float &red, const float &green, const float &blue) override;

        [[nodiscard]] glm::vec3 getPoint() const;

        void setPoint(const float &x = 0, const float &y = 0, const float &s = 0);

        void setPoint(const glm::vec2 &vector = glm::vec2(0, 0), const float &s = 0);

        void setPoint(const glm::vec3 &vector = glm::vec3(0, 0, 0));

        friend std::ostream &operator<<(std::ostream &os, const Figure::Point2D &p);

    private:
        glm::vec3 _point;

        void _reflexionAxisX();

        void _reflexionAxisY();

        void _shearingAxisX(const float &shearing);

        void _shearingAxisY(const float &shearing);

    };
}


#endif //CLION_MODERN_OPENGL_POINT2D_HPP
