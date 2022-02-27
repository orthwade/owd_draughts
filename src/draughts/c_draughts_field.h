#pragma once
#include "c_draughts_entity.h"

namespace owd
{
	class c_draughts_square
	{
	public:
		c_draughts_square();
		c_draughts_square
		(float x_, float y_, uint16_t x_int, uint16_t y_int, float width_, float height_, 
			enm_draughts_colour colour);

		float x{};
		float y{};

		uint16_t x_int{};
		uint16_t y_int{};

		float width{};
		float height{};

		float red{};
		float green{};
		float blue{};

		enm_draughts_colour colour = draughts_white;
		inline g_unit_t& g_square() { return m_g_square; }

		inline bool is_black() { return colour == draughts_white; }

	private:
		g_unit_t m_g_square{};

	};

	class c_draughts_field : public c_draughts_entity
	{
	public:
		inline std::array<std::array<c_draughts_square, 8>, 8>& get_squares() { return m_squares; }
		inline c_draughts_square& get_default() { return m_squares[0][0]; }
		static c_draughts_field* get_instance();
		static void terminate();
	private:
		float m_width  = 1.99f;
		float m_height = 1.99f;

		uint16_t m_width_int  = 8;
		uint16_t m_height_int = 8;

		c_texture_bank* m_texture_bank = c_texture_bank::get_instance();
		
		std::array<std::array<c_draughts_square, 8>, 8> m_squares{};

		c_draughts_field();
		~c_draughts_field();
		static c_draughts_field* m_singleton;
	};
}