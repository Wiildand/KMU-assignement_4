//
// Created by Remi Peyras on 19/09/2021.
//

#ifndef CLION_MODERN_OPENGL_IGLOBJECT_HPP
#define CLION_MODERN_OPENGL_IGLOBJECT_HPP

/**
 * Lib OpenGl
 */
#include <glm/glm.hpp>
#include <GLUT/glut.h>
#include <GLFW/glfw3.h>


/**
 * Standart CPP
 */
#include <vector>
#include <iostream>
#include <string>
#include <utility>

#include "Axis.hpp"
//#include "Point/Point2D.hpp"
//#include "Point/Point3D.hpp"

namespace Figure {
    class IGLObject {
    public:
        explicit IGLObject(std::string name) : _name(std::move(name)) {}

        virtual void draw(const float &red, const float &green, const float &blue) = 0;

        virtual void reflexion(const Matrix::Axis &axis) = 0;

        virtual void dump() = 0;

        [[nodiscard]] std::string getName() const {
            return _name;
        }

        void setName(const std::string &name) {
            _name = name;
        }


    protected:
        std::string _name;
    };
};

#endif //CLION_MODERN_OPENGL_IGLOBJECT_HPP
