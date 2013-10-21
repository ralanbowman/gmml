#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include <ostream>
#include <iomanip>

namespace Geometry
{
    class Coordinate
    {
        public:
            //////////////////////////////////////////////////////////
            //                       Constructor                    //
            //////////////////////////////////////////////////////////
            /*! \fn
              * Default constructor
              */
            Coordinate();
            /*! \fn
              * Constructor with given three double values
              * @param x A double value on X axis in cartesian coordinate
              * @param y A double value on Y axis in cartesian coordinate
              * @param z A double value on Z axis in cartesian coordinate
              */
            Coordinate(double x, double y, double z);
            /*! \fn
              * Copy constructor
              * @param coordinate A coordinate to be copied to another instance
              */
            Coordinate(const Coordinate& coordinate);            

            //////////////////////////////////////////////////////////
            //                         FUNCTIONS                    //
            //////////////////////////////////////////////////////////
            /*! \fn
              * Translate a coordinate with respect to given coordinate by x, y and z
              * @param x A double value on X axis for the origin of translation
              * @param y A double value on Y axis for the origin of translation
              * @param z A double value on Z axis for the origin of translation
              */
            void Translate(double x, double y, double z);

            //////////////////////////////////////////////////////////
            //                     DISPLAY FUNCTIONS                //
            //////////////////////////////////////////////////////////
            /*! \fn
              * A function to print out a coordinate
              * Print out the current coordinate in a defined structure
              * @param out An output stream, the print result will be written in the given output stream
              */
            void Print(std::ostream& out = std::out);

            //////////////////////////////////////////////////////////
            //                         ATTRIBUTES                   //
            //////////////////////////////////////////////////////////
            double x_;          /*!< x */
            double y_;          /*!< y */
            double z_;          /*!< z */
    };
}

#endif // COORDINATE_HPP