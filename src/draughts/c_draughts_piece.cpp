#include "c_draughts_piece.h"

namespace owd
{
    float    c_draughts_piece::m_radius         = 0.0f;
    float    c_draughts_piece::m_king_radius_2  = 0.0f;
    float	 c_draughts_piece::m_square_width   = 0.0f;
    float	 c_draughts_piece::m_square_height  = 0.0f;
    uint16_t c_draughts_piece::m_square_count_x = 0;
    uint16_t c_draughts_piece::m_square_count_y = 0;

    float c_draughts_piece::m_red_2   = 0.5f;
    float c_draughts_piece::m_green_2 = 0.5f;
    float c_draughts_piece::m_blue_2  = 0.5f;

    c_draughts_field* c_draughts_piece::m_field_ptr = c_draughts_field::get_instance();
    c_draughts_piece c_draughts_piece::m_default{};

   // c_draughts_man c_draughts_man::m_empty{};

    c_draughts_piece::c_draughts_piece()
        :c_draughts_piece(get_default_square(), draughts_white, draughts_man)
    {
        
    }

    c_draughts_piece::c_draughts_piece(float x, float y, enm_draughts_colour colour, enm_draughts_piece type)
        :
        m_x(x),
        m_y(y),
        m_x_int(x),
        m_y_int(y),
        m_colour(colour),
        m_type(type)
    {
        if (is_black())
        {
            m_red_1 = 0.0f;
            m_green_1 = 0.6f;
            m_blue_1 = 0.0f;
        }
        else
        {
            m_red_1 = 1.0f;
            m_green_1 = 1.0f;
            m_blue_1 = 1.0f;
        }
        if (is_king())
        {

        }
        else
        {
            add_circle(m_x, m_y, m_radius, m_red_1, m_green_1, m_blue_1, 1.0f, 3);
        }

    }

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
    void c_draughts_piece::move(const c_draughts_square& square_)
    {
        auto x = square_.x;
        auto y = square_.y;

        for (index_t i = 0; i != m_vec_coloured.size(); ++i)
        {
            m_vec_coloured[i]->set_position(x, y);
        }
        m_x = x;
        m_y = y;

    }
    //c_draughts_piece::c_draughts_piece(uint16_t x, uint16_t y, enm_draughts_colour colour, enm_draughts_piece type)
    //    :
    //    m_x_int(x),
    //    m_y_int(y),
    //    m_colour(colour),
    //    m_type(type)
    //{
    //    m_x = 0.0f - (m_square_width  / 2.0f) - m_square_width  * static_cast<float>(m_square_count_x / 2 - 1);
    //    m_x += m_square_width * m_x_int;

    //    m_y = 0.0f - (m_square_height / 2.0f) - m_square_height * static_cast<float>(m_square_count_y / 2 - 1);
    //    m_y += m_square_height * m_y_int;

    //    if (is_black())
    //    {
    //        m_red_1   = 0.0f;
    //        m_green_1 = 0.6f;
    //        m_blue_1  = 0.0f;
    //    }
    //    else
    //    {
    //        m_red_1   = 1.0f;
    //        m_green_1 = 1.0f;
    //        m_blue_1  = 1.0f;
    //    }
    //}
    c_draughts_piece::c_draughts_piece
    (const c_draughts_square& square_, enm_draughts_colour colour, enm_draughts_piece type)
        :
        m_x(square_.x),
        m_y(square_.y),
        m_x_int(square_.x_int),
        m_y_int(square_.y_int),
        m_colour(colour),
        m_type(type)
    {
        if (is_black())
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
        if (is_king())
        {

        }
        else
        {
            add_circle(m_x, m_y, m_radius, m_red_1, m_green_1, m_blue_1, 1.0f, 3);
        }

    }
  //  c_draughts_piece::c_draughts_piece(const c_draughts_piece& other)
  //      :
  //      m_x      (other. m_x     ), 
		//m_y      (other.m_y      ),
		//m_x_int  (other.m_x_int  ),
		//m_y_int  (other.m_y_int  ),
  //      m_colour (other.m_colour),
  //      m_type   (other.m_type),
		//m_red_1  (other.m_red_1  ),
		//m_green_1(other.m_green_1),
		//m_blue_1 (other.m_blue_1 ),
  //  {
  //  }
  //  c_draughts_piece& c_draughts_piece::operator=(const c_draughts_piece& other)
  //  {
  //      if (this != &other)
  //      {
  //          m_x       = other.m_x      ;
  //          m_y       = other.m_y      ;
  //          m_x_int   = other.m_x_int  ;
  //          m_y_int   = other.m_y_int  ;
  //          m_colour  = other.m_colour ;
  //          m_type    = other.m_type   ;
  //          m_red_1   = other.m_red_1  ;
  //          m_green_1 = other.m_green_1;
  //          m_blue_1  = other.m_blue_1 ;
  //      }
  //      return *this;
  //  }
}

