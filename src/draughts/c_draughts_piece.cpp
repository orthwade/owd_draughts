#include "c_draughts_piece.h"

namespace owd
{
    float    c_draughts_piece::m_radius         = 0.0f;
    float    c_draughts_piece::m_king_radius_2  = 0.0f;
    float	 c_draughts_piece::m_square_width   = 0.0f;
    float	 c_draughts_piece::m_square_height  = 0.0f;
    uint16_t c_draughts_piece::m_square_count_x = 0;
    uint16_t c_draughts_piece::m_square_count_y = 0;

    float c_draughts_king::m_red_2   = 0.5f;
    float c_draughts_king::m_green_2 = 0.5f;
    float c_draughts_king::m_blue_2  = 0.5f;

    void c_draughts_piece::set_field_parameters
    (float square_width, float square_height, uint16_t square_count_x, uint16_t square_count_y)
    {
        m_square_width   = square_width;
        m_square_height  = square_height;
        m_square_count_x = square_count_x;
        m_square_count_y = square_count_y;
        m_radius         = m_square_width / 2.0f / 1.3f;
        m_king_radius_2 /= 3.0f;
    }
    c_draughts_piece::c_draughts_piece(uint16_t x, uint16_t y, bool black)
        :
        m_x_int(x),
        m_y_int(y),
        m_black(black)
    {
        m_x = 0.0f - (m_square_width  / 2.0f) - m_square_width  * static_cast<float>(m_square_count_x / 2 - 1);
        m_x += m_square_width * m_x_int;

        m_y = 0.0f - (m_square_height / 2.0f) - m_square_height * static_cast<float>(m_square_count_y / 2 - 1);
        m_y += m_square_height * m_y_int;

        if (m_black)
        {
            m_red_1   = 0.0f;
            m_green_1 = 0.6f;
            m_blue_1  = 0.0f;
        }
        else
        {
            m_red_1   = 1.0f;
            m_green_1 = 1.0f;
            m_blue_1  = 1.0f;
        }
    }
    c_draughts_piece::c_draughts_piece(const c_draughts_square& square_, bool black_)
        :
        m_x(square_.x),
        m_y(square_.y),
        m_x_int(square_.x_int),
        m_y_int(square_.y_int),
        m_black(black_)
    {
        if (m_black)
        {
            m_red_1   = 0.0f;
            m_green_1 = 0.6f;
            m_blue_1  = 0.0f;
        }
        else
        {
            m_red_1   = 1.0f;
            m_green_1 = 1.0f;
            m_blue_1  = 1.0f;
        }
    }
    c_draughts_king::c_draughts_king(uint16_t x, uint16_t y, bool black)
        : c_draughts_piece(x, y, black)
    {
        //add_circle(m_x, m_y, m_radius       , m_red_1, m_green_1, m_blue_1, 1.0f);
        //add_circle(m_x, m_y, m_king_radius_2, m_red_2, m_green_2, m_blue_2, 1.0f);
    }
}

