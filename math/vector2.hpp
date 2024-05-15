/* SIMPLE VECTOR2 STRUCTS  
 *
 * Contains some math functions with the vectors, it was created with gamedev in mind  
 *
 * Functions: 
 *      Normalize
 *      Euclidean Distance
 *      Magnitude
 *      Linear Interpolation
 *      Dot Product
*/

#pragma once 

#include <cmath>
#include <string>

namespace utilz
{
    struct vector2
    {
        int x, y;

        vector2(int x, int y) : x(x), y(y) {}
        vector2() : x(0), y(0) {}
        vector2(float v) : x(v), y(v) {}

        float mag() 
        { return sqrt((x * x) + (y * y)); }

        void normalize()
        {
            float m = mag();

            if (m <= 0) return;

            x /= m;
            y /= m;
        }

        static vector2 normalize(vector2& vec)
        {
            float m = vec.mag();

            if (m <= 0) return vector2(0, 0);

            return vector2(vec.x / m, vec.y / m); 
        }

        static vector2 lerp(vector2 target, vector2 source, float speed)
        {
            vector2 res;
            res.x = source.x + ((target.x - source.x) * speed);
            res.y = source.y + ((target.y - source.y) * speed);

            return res;
        }

        float dot(vector2 t)
        { return (x * t.x) + (y * t.y); }

        static float dot(vector2 s, vector2 t)
        { return (s.x * t.x) + (s.y * t.y); }

        float eu_dist(vector2 t)
        { return sqrt(((x - t.x) * (x - t.x)) + ((y - t.y) * (y - t.y))); }

        static float eu_dist(vector2 s, vector2 t)
        { return sqrt(((s.x - t.x) * (s.x - t.x)) + ((s.y - t.y) * (s.y - t.y))); }

        vector2 vector2_zero() { return vector2(); }

        std::string to_string()
        { return std::string(std::to_string(x) + ", " + std::to_string(y)); }
    };

    struct vector2f
    {
        float x, y;

        vector2f(float x, float y) : x(x), y(y) {}
        vector2f() : x(0.0f), y(0.0f) {}
        vector2f(float v) : x(v), y(v) {}

        float mag() 
        { return sqrt((x * x) + (y * y)); }

        void normalize()
        {
            float m = mag();

            if (m <= 0) return;

            x /= m;
            y /= m;
        }

        static vector2f normalize(vector2f& vec)
        {
            float m = vec.mag();

            if (m <= 0) return vector2f(0.0f, 0.0f);

            return vector2f(vec.x / m, vec.y / m); 
        }

        static vector2f lerp(vector2 target, vector2 source, float speed)
        {
            vector2f res;
            res.x = source.x + ((target.x - source.x) * speed);
            res.y = source.y + ((target.y - source.y) * speed);

            return res;
        }

        float dot(vector2f t)
        { return (x * t.x) + (y * t.y); }

        static float dot(vector2f s, vector2f t)
        { return (s.x * t.x) + (s.y * t.y); }

        float eu_dist(vector2f t)
        { return sqrt(((x - t.x) * (x - t.x)) + ((y - t.y) * (y - t.y))); }

        static float eu_dist(vector2f s, vector2f t)
        { return sqrt(((s.x - t.x) * (s.x - t.x)) + ((s.y - t.y) * (s.y - t.y))); }

        vector2f vector2f_zero() { return vector2f(); }

        std::string to_string()
        { return std::string(std::to_string(x) + ", " + std::to_string(y)); }
    };
}

