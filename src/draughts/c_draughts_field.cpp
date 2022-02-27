#include "c_draughts_field.h"

namespace owd
{
    c_draughts_field* c_draughts_field::m_singleton = nullptr;

    c_draughts_field::c_draughts_field()
    {
        add_rect(0.0f, 0.0f, m_width, m_height, 0.9f, 0.9f, 0.9f, 1.0f, 0);

        enm_draughts_colour colour_ = draughts_black;

        float square_width  = m_width  / static_cast<float>(m_width_int  + 1);
        float square_height = m_height / static_cast<float>(m_height_int + 1);

        add_rect(0.0f, 0.0f, square_width * m_width_int * 1.01f, square_height * m_height_int * 1.01f, 
            0.0f, 0.0f, 0.0f, 1.0f, 1);

        float square_x_{};
        float square_y_ = 0.0f - (square_height / 2.0f) - square_height * static_cast<float>(m_height_int / 2 - 1);

        for (uint16_t y = 0; y != m_width_int; ++y)
        {
            square_x_ = 0.0f - (square_width / 2.0f) - square_width * static_cast<float>(m_width_int / 2 - 1);
            
            for (uint16_t x = 0; x != m_height_int; ++x)
            {
                m_squares[y][x] = c_draughts_square
                (
                    square_x_,
                    square_y_,
                    x,
                    y,
                    square_width,
                    square_height,
                    colour_
                );

                square_x_ += square_width;
                if (colour_ == draughts_white)
                {
                    colour_ = draughts_black;
                }
                else
                {
                    colour_ = draughts_white;
                }
                add_coloured(m_squares[y][x].g_square());
            }
            if (colour_ == draughts_white)
            {
                colour_ = draughts_black;
            }
            else
            {
                colour_ = draughts_white;
            }
            square_y_ += square_height;
        }
        bool vertical = true;
        wchar_t symbol_previous = L'\0';
        wchar_t symbol = L'A';
        uint8_t position = 0;
        float mark_height = square_height / 2.0f;
        float mark_width = square_width / 4.0f;

        float mark_x = 0.0f;
        float mark_y = 0.0f;
        mark_x = m_squares[0][0].x - square_width / 1.25f;
        std::wstring texture_path_0{ L"rsc/textures/numbers/centred/[replace].png" };
        std::wstring texture_path{ L"rsc/textures/numbers/centred/[replace].png" };

        c_files_in_directory files_in_directory{};

        auto& mark_texture_filepath = files_in_directory(L"rsc/textures/draughts/marks/vertical/");

        for (index_t i = 0; i != m_height_int; ++i)
        {
            mark_y = m_squares[i][0].y;
            m_texture_bank->load(mark_texture_filepath[i]);
            auto texture_ = m_texture_bank->by_filepath(mark_texture_filepath[i]);
            //auto& texture_ = m_texture_bank->last();
            auto g_mark = std::make_shared<c_graphic_unit_textured>
                (mark_x, mark_y, mark_width, mark_height, texture_, 2);
            ++symbol;
            add_textured(g_mark);
        }
        mark_texture_filepath = files_in_directory(L"rsc/textures/draughts/marks/horizontal/");
        mark_y = m_squares[0][0].y - square_height / 1.25f;
        symbol = L'0';

        mark_height /= 1.1f;
        mark_width  /= 1.1f;

        for (index_t i = 0; i != m_width_int; ++i)
        {
            mark_x = m_squares[0][i].x;
            m_texture_bank->load(mark_texture_filepath[i]);
            auto texture_ = m_texture_bank->by_filepath(mark_texture_filepath[i]);
            auto g_mark = std::make_shared<c_graphic_unit_textured>
                (mark_x, mark_y, mark_width, mark_height, texture_, 2);
            ++symbol;
            add_textured(g_mark);
        }
    }
    c_draughts_field::~c_draughts_field()
    {
    }
    c_draughts_square::c_draughts_square()
    {
    }
    c_draughts_square::c_draughts_square
    (float x_, float y_, uint16_t x_int_, uint16_t y_int_, float width_, float height_,
        enm_draughts_colour colour_)
        :
        x(x_),
        y(y_),
        x_int(x_int_),
        y_int(y_int_),
        width(width_),
        height(height_),
        colour(colour_)
    {
        if (is_black())
        {
            red   = 0.30f;
            green = 0.30f;
            blue  = 0.35f;
        }
        else
        {
            red   = 0.95f;
            green = 0.95f;
            blue  = 0.95f;
        }
        vertices_t positions =
        {
            x + -width / 2.0f, y + -height / 2.0f,
            x +  width / 2.0f, y + -height / 2.0f,
            x +  width / 2.0f, y +  height / 2.0f,
            x + -width / 2.0f, y +  height / 2.0f
        };
        gl_indices_t indices = { 0, 1, 2, 2, 3, 0 };
        m_g_square = std::make_shared<c_graphic_unit>(positions, indices, red, green, blue, 1.0f, 2);
    }
    c_draughts_field* owd::c_draughts_field::get_instance()
    {
        if (m_singleton == nullptr)
        {
            m_singleton = new c_draughts_field();
        }

        return m_singleton;
    }
    void c_draughts_field::terminate()
    {
        if (m_singleton == nullptr)
        {

        }
        else
        {
            delete m_singleton;
            m_singleton = nullptr;
        }
    }

}

