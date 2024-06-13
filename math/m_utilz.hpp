#pragma once

/* 

A couple math utilities like:
    Linear interpolation,
    Clamping,
    Random integer, 
    Smoothstep

*/

#include <cmath>
#include <random>

#define PI 3.1415926535897

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

            // Must call constuctor before calling this function
            static int32_t rand_i(int32_t min, int32_t max)
            {
                std::uniform_int_distribution<std::mt19937::result_type> res(min, max);

                return res(m_rng);
            }

            static float lerp(float start, float end, float t)
            { return start + (end - start) * t; }

            static float clampf(float min, float max, float val)
            {
                if (val < min) return min;
                if (val > max) return max;

                return val;
            }
            
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

            static float deg_2_rad(float angle)
            { return angle * PI/180; }

            static float rad_2_deg(float angle)
            { return angle * 180/PI; }

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

