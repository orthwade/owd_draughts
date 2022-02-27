#pragma once
#include "c_draughts_field.h"
#include "c_draughts_piece.h"

namespace owd
{
	class c_draughts
	{
	public:
		static c_draughts* get_instance();
		static void terminate();

	protected:
		c_draughts_field* m_field_ptr = c_draughts_field::get_instance();
		c_draughts_field& m_field = *m_field_ptr;
		std::vector<c_draughts_piece> m_pieces_white{};
		std::vector<c_draughts_piece> m_pieces_black{};

		uint16_t m_starting_lines_count = 3;

		static c_draughts* m_singleton;

		c_draughts();
		~c_draughts();
		
		c_draughts(const c_draughts&) = delete;
		c_draughts& operator=(const c_draughts&) = delete;
	};
}