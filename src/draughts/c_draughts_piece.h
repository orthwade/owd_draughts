#pragma once
#include "c_draughts_entity.h"
#include "c_draughts_square.h"
#include "c_draughts_field.h"

namespace owd
{
	enum class enm_draughts_piece { man, king };
	constexpr enm_draughts_piece draughts_man = enm_draughts_piece::man;
	constexpr enm_draughts_piece draughts_king = enm_draughts_piece::king;
}
namespace owd
{
	class c_draughts_piece : public c_draughts_entity
	{
	public:
		c_draughts_piece();
		//c_draughts_piece(uint16_t x, uint16_t y, enm_draughts_colour black, enm_draughts_piece type);
		c_draughts_piece(const c_draughts_square& square_, enm_draughts_colour black_, enm_draughts_piece type);

		c_draughts_piece(const c_draughts_piece&);
		c_draughts_piece& operator=(const c_draughts_piece&);

		inline bool is_black() { return m_colour == draughts_black; }
		inline bool is_king() { return m_type == draughts_king; }
		static inline void set_radius(float radius) { m_radius = radius; }

		static void set_field_parameters
		(float square_width, float square_height, uint16_t square_count_x, uint16_t square_count_y);

		void move(const c_draughts_square& square_);

		inline c_draughts_square& get_default_square() { return m_field_ptr->get_default(); }

	protected:
		enm_draughts_piece m_type{};
		g_unit_t m_circle_1{};
		g_unit_t m_circle_2{};
		float m_x{};
		float m_y{};

		uint16_t m_x_int{};
		uint16_t m_y_int{};

		enm_draughts_colour m_colour = draughts_white;

		float m_red_1{};
		float m_green_1{};
		float m_blue_1{};

		static float m_radius;
		static float m_king_radius_2;

		static float	 m_square_width;
		static float	 m_square_height;
		static uint16_t  m_square_count_x;
		static uint16_t  m_square_count_y;

		static c_draughts_field* m_field_ptr;

		static float m_red_2;
		static float m_green_2;
		static float m_blue_2;

		static c_draughts_piece m_default;
	};

}