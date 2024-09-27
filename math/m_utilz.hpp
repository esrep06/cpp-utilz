#pragma once

/* 
A couple math utilities like:
    Linear interpolation,
    Clamping,
    Random integer, 
    Smoothstep

*/

#include "vector2.hpp"
#include <cmath>
#include <random>

#define UTILZ_PI 3.1415926535897

namespace utilz
{
    class m_utilz 
    {
        public:
            // Must call constructor before calling random functions
            m_utilz()
            { 
                // Starts random device 
                m_rng = std::mt19937(m_device()); 

                // Fills sin and cos tables
                for (int i = 0; i < 360; i++) 
                {
                    m_sin_table[i] = sin(deg_2_rad(i));
                    m_cos_table[i] = cos(deg_2_rad(i));
                }
            }

            // Returns a vector from an angle in degrees
            static vector2f deg_2_vec(float deg)
            {
                double rad = deg_2_rad(deg);
                return vector2f(cos(rad), sin(rad));
            }

            // Returns an angle in degrees from a vector
            static float vec_2_deg(vector2f vec)
            { return rad_2_deg(atan2(vec.y, vec.x)); }

            // Must call constuctor before calling this function
            static int32_t rand_i(int32_t min, int32_t max)
            {
                std::uniform_int_distribution<std::mt19937::result_type> res(min, max);

                return res(m_rng);
            }

            // Linearly interpolates between 2 floats
            static float lerp(float start, float end, float t)
            { return start + (end - start) * t; }

            // Clamps a float between two thresholds 
            static float clampf(float min, float max, float val)
            {
                if (val < min) return min;
                if (val > max) return max;

                return val;
            }
            
            // Clams an integer between 2 thresholds
            static int32_t clamp(int32_t min, int32_t max, int32_t val)
            {
                if (val < min) return min;
                if (val > max) return max;

                return val;
            }
           
            // t between 0 - 1
            static float smooth_step(float t)
            {
                float x = clampf(0.0f, 1.0f, t);

                return x * x * (3.0f - 2.0f * x);
            }

            // Converts from degrees to radians
            static float deg_2_rad(float angle)
            { return angle * (UTILZ_PI/180); }

            // Converts from radians to degrees
            static float rad_2_deg(float angle)
            { return angle * (180/UTILZ_PI); }

            // Costructor call needed before calling this function
            static float t_sin(int32_t x)
            {  return m_sin_table[clamp(0, 359, x)]; }

            // Costructor call needed before calling this function
            static float t_cos(int32_t x)
            { return m_cos_table[clamp(0, 359, x)]; }

        private:
            inline static std::random_device m_device;
            inline static std::mt19937 m_rng;
            inline static float m_sin_table[360];
            inline static float m_cos_table[360];
    };
}

