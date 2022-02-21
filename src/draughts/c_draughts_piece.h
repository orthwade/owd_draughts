#pragma once
#include "c_draughts_entity.h"
#include "c_draughts_square.h"
#include "c_draughts_field.h"

namespace owd
{
	class c_draughts_piece : public c_draughts_entity
	{
	public:
		static inline void set_radius(float radius) { m_radius = radius; }
		static void set_field_parameters
		(float square_width, float square_height, uint16_t square_count_x, uint16_t square_count_y);

		c_draughts_piece(uint16_t x, uint16_t y, bool black);
		c_draughts_piece(const c_draughts_square& square_, bool black_);

	protected:
		static float m_radius;
		static float m_king_radius_2;

		static float	 m_square_width  ;
		static float	 m_square_height ;
		static uint16_t  m_square_count_x;
		static uint16_t  m_square_count_y;

		float m_x{};
		float m_y{};

		uint16_t m_x_int{};
		uint16_t m_y_int{};

		bool m_black = false;

		float m_red_1{};
		float m_green_1{};
		float m_blue_1{};

	};

	class c_draughts_man : public c_draughts_piece
	{
	public:
		c_draughts_man(const c_draughts_square& square_, bool black_)
			: c_draughts_piece(square_, black_)
		{
			add_circle(m_x, m_y, m_radius, m_red_1, m_green_1, m_blue_1, 1.0f, 3);
		}

	private:
	};

	class c_draughts_king : public c_draughts_piece
	{
	public:
		c_draughts_king(uint16_t x, uint16_t y, bool black);

	private:
		static float m_red_2  ;
		static float m_green_2;
		static float m_blue_2 ;

	};

}