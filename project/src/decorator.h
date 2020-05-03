/**
 * @file decorator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_DECORATOR_H_
#define SRC_DECORATOR_H_

#include "src/bus.h"
#include "src/data_structs.h"

/**
 * @brief The abstract class to generate decorator for buses.
 *
 * Calls to \ref setColor function to give color to buses. It is a virtual function,
 * and it is override in BusDecorator class.
 * Calls to \ref setDensity function to give density of the color.It is a virtual function,
 * and it is override in BusDecorator class.
 */

class IBus{
 public:
/**
  * @brief pure virtual function.
  *
  * This function will be used for setColor purpose.
  *
  * @param[in] RGB value for red
  * @param[in] RGB value for bulue
  * @param[in] RGB value for green
  * @param[in] color intensity.
  *
  */
    virtual void setColor(int r, int g, int b, int a) = 0;

/**
  * @brief pure virtual function.
  *
  * This function will be used for setDensity purpose.
  *
  * @param[in] RGB value for red
  * @param[in] RGB value for bulue
  * @param[in] RGB value for green
  * @param[in] color intensity.
  *
  */
    virtual void setDensity(int a) = 0;
};

/**
 * @brief The sub class of IBus class. It override the virtual functions in IBus class.
 *
 * Calls to \ref setColor function to give color to buses.
 * Calls to \ref setDensity function to give density of the color.
 */

class BusDecorator : public IBus {
 protected:
    IBus *m_IBus;

 public:
/**
  * @brief Constructor of BusDecorator.
  *
  * This constructor will be used for simulation purposes.
  *
  * @param[in] IBus *
  *
  * @return IBus object with color.
  */
    explicit BusDecorator(IBus * baseBus):m_IBus(baseBus) {}

/**
  * @brief override function from IBus class.
  *
  * This function will be used for setColor purpose.
  *
  * @param[in] RGB value for red
  * @param[in] RGB value for bulue
  * @param[in] RGB value for green
  * @param[in] color intensity.
  *
  */

    void setColor(int r, int g, int b, int a) override {
        m_IBus ->setColor(r, g, b, a);
    }

/**
  * @brief override function from IBus class.
  *
  * This function will be used for setDensity purpose.
  *
  * @param[in] color intensity.
  *
  */
    void setDensity(int a) override {
        m_IBus -> setDensity(a);
    }
};

#endif  // SRC_DECORATOR_H_
