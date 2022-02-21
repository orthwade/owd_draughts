#pragma once
#include "c_draughts_field.h"
#include "c_draughts_piece.h"

namespace owd
{
	class c_draughts
	{
	public:
		static c_draughts* get_instance();
		//void init();
		static void terminate();
		//void reset();
	protected:
		c_draughts_field m_field{};
		std::vector<c_draughts_man>  m_men{};
		std::vector<c_draughts_king> m_kings{};

		uint16_t m_starting_lines_count = 3;

		static c_draughts* m_singleton;

		c_draughts();
		~c_draughts();
		
		c_draughts(const c_draughts&) = delete;
		c_draughts& operator=(const c_draughts&) = delete;
	};
}