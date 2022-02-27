#pragma once
#include "../graphics/c_graphic_engine.h"
#include "c_draughts_controls.h"

namespace owd
{
	enum class enm_draughts_colour { white, black };
	constexpr enm_draughts_colour draughts_white = enm_draughts_colour::white;
	constexpr enm_draughts_colour draughts_black = enm_draughts_colour::black;
}

namespace owd
{
	class c_draughts_entity
	{
	public:
		c_draughts_entity();
		~c_draughts_entity();

		void move(float x_, float y_);

	protected:
		float m_x = 0.0f;
		float m_y = 0.0f;

		float m_size = 1.0f;

		c_graphic_engine* m_graphic_engine = c_graphic_engine::get_instance();
		//std::function<float(float)> m_norm_x = std::bind(&c_entity::m_norm_x);

		c_batch_handler* m_batch_handler_ptr = c_batch_handler::get_instance();
		c_batch_handler& m_batch_handler     = *m_batch_handler_ptr;

		std::vector<g_unit_textured_t> m_vec_textured  {};
		std::vector<g_unit_t> m_vec_coloured  {};
		
		void add_textured(g_unit_textured_t& rect);
		void add_coloured(g_unit_t& circle);

		void add_rect		(float centre_x, float centre_y, float width, float height,
			float red, float green, float blue, float alpha, uint16_t level);
		void add_circle		(float centre_x, float centre_y, float radius,
			float red, float green, float blue, float alpha, uint16_t level);
		void add_textured	(float centre_x, float centre_y, float width, float height,
			texture_t& texture, uint16_t level);
	};
}