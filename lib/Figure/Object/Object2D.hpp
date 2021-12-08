//
// Created by Remi Peyras on 19/09/2021.
//

#ifndef CLION_MODERN_OPENGL_OBJECT2D_HPP
#define CLION_MODERN_OPENGL_OBJECT2D_HPP

#include "IGLObject.hpp"
#include "Point/Point2D.hpp"

namespace Figure {
    class Object2D : public Figure::IGLObject {

    public:
        explicit Object2D(const std::string &name, std::vector<Point2D> listPoint);

        ~Object2D() = default;

        void translation(const float &x, const float &y);

        void translation(const glm::vec2 &vector = glm::vec2(0, 0));

        void rotation(const float &degrees);

        void scaling(const float &x = 1, const float &y = 1);

        void scaling(const glm::vec2 &vector = glm::vec2(1, 1));

        void shearing(const Matrix::Axis &axis, const float &shearing = 0);

        void reflexion(const Matrix::Axis &axis) override;

        void dump() override;

        void draw(const float &red, const float &green, const float &blue) override;

        void setListPoint(std::vector<Point2D> &listPoints);

        [[nodiscard]] std::vector<Point2D> getListPoints() const;

        friend std::ostream &operator<<(std::ostream &os, const Object2D &o);

    private:
        std::vector<Point2D> _listPoints;

    };

}

//    std::ostream &operator<<(std::ostream &os, const Figure::Object2D &o);


#endif //CLION_MODERN_OPENGL_OBJECT2D_HPP
