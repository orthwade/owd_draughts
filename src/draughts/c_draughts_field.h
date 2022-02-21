#pragma once
#include "c_draughts_entity.h"

namespace owd
{
	class c_draughts_square
	{
	public:
		c_draughts_square();
		c_draughts_square
		(float x_, float y_, uint16_t x_int, uint16_t y_int, float width_, float height_, bool black_);

		float x{};
		float y{};

		uint16_t x_int{};
		uint16_t y_int{};

		float width{};
		float height{};

		float red{};
		float green{};
		float blue{};

		bool black = true;
		inline g_unit_t& g_square() { return m_g_square; }

	private:
		g_unit_t m_g_square{};

	};

	class c_draughts_coordinate
	{
	public:
		c_draughts_coordinate();
		c_draughts_coordinate(bool vertical, char symbol, uint8_t position, g_unit_textured_t& mark);

		c_draughts_coordinate(const c_draughts_coordinate& other);
		c_draughts_coordinate& operator=(const c_draughts_coordinate& other) = default;

		~c_draughts_coordinate();

		inline g_unit_textured_t& g_mark() { return m_g_mark; }

	private:

		bool		m_vertical{};
		uint8_t		m_position{};
		char		m_symbol{};

		g_unit_textured_t m_g_mark{};

	};

	class c_draughts_field : public c_draughts_entity
	{
	private:
		

	public:
		c_draughts_field();
		~c_draughts_field();

		inline std::array<std::array<c_draughts_square, 8>, 8>& get_squares() { return m_squares; }

	private:
		float m_width  = 1.99f;
		float m_height = 1.99f;

		uint16_t m_width_int  = 8;
		uint16_t m_height_int = 8;

		c_texture_bank* m_texture_bank = c_texture_bank::get_instance();
		
		std::array<std::array<c_draughts_square, 8>, 8> m_squares{};
		std::array<std::array<c_draughts_coordinate, 8>, 2> m_marks{};
	};
}