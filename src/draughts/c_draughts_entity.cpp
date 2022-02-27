#include "c_draughts_entity.h"

namespace owd
{
    c_draughts_entity::c_draughts_entity()
    {
    }
    c_draughts_entity::~c_draughts_entity()
    {
    }

    void c_draughts_entity::move(float x_, float y_)
    {
    }

    void c_draughts_entity::add_textured(g_unit_textured_t& unit)
    {
        m_vec_textured.push_back(unit);
        m_batch_handler.add(unit);
    }

    void c_draughts_entity::add_coloured(g_unit_t& unit)
    {
        m_vec_coloured.push_back(unit);
        m_batch_handler.add(unit);
    }

    void c_draughts_entity::add_rect
    (float centre_x, float centre_y, float width, float height, 
        float red, float green, float blue, float alpha, uint16_t level)
    {
        vertices_t positions =
        {
            centre_x + -width / 2.0f, centre_y + -height / 2.0f,
            centre_x +  width / 2.0f, centre_y + -height / 2.0f,
            centre_x +  width / 2.0f, centre_y +  height / 2.0f,
            centre_x + -width / 2.0f, centre_y +  height / 2.0f
        };
        gl_indices_t indices = { 0, 1, 2, 2, 3, 0 };

        auto rect = std::make_shared<c_graphic_unit>(positions, indices, red, green, blue, alpha, level);
        add_coloured(rect);
    }
    void c_draughts_entity::add_circle(float centre_x, float centre_y, float radius, 
        float red, float green, float blue, float alpha, uint16_t level)
    {
        vertices_t positions{};
        gl_indices_t indices{};
        uint16_t triangles_count = 100;
        float angle_step = 360.0f / triangles_count;
        float angle = 90.0f + angle_step / 2.0f;

        positions.push_back(centre_x);
        positions.push_back(centre_y);

        for (uint16_t i = 0; i != triangles_count; ++i)
        {
            positions.push_back(centre_x + radius * cos_d(angle));
            positions.push_back(centre_y + radius * sin_d(angle));

            angle -= angle_step;
        }

        for (index_t i = 0; i < triangles_count; ++i)
        {
            indices.push_back(0);
            indices.push_back(i + 1);
            indices.push_back(i + 2);
        }
        indices.back() = 1;

        auto circle = std::make_shared<c_graphic_unit>(positions, indices, red, green, blue, alpha, level);
        add_coloured(circle);
    }
    void c_draughts_entity::add_textured(float centre_x, float centre_y, float width, float height, 
        texture_t& texture, uint16_t level)
    {
    }

}

