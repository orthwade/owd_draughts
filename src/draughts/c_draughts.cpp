#include "c_draughts.h"

namespace owd
{
	c_draughts* c_draughts::m_singleton = nullptr;
	
	c_draughts* owd::c_draughts::get_instance()
	{
		if (m_singleton == nullptr)
		{
			m_singleton = new c_draughts();
		}

		return m_singleton;
	}
	void c_draughts::terminate()
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
	c_draughts::c_draughts()
    {
		auto& squares_ = m_field.get_squares();
		auto& squares_lines_ = squares_;
		auto& squares_line_ = squares_lines_[0];
		auto& square_ = squares_line_[0];

		c_draughts_piece::set_field_parameters
		(square_.width, square_.height, squares_line_.size(), squares_lines_.size());

		bool black_ = false;

		for (uint16_t y = 0; y != squares_lines_.size(); ++y)
		{
			squares_line_ = squares_[y];
			for (uint16_t x = 0; x != squares_line_.size(); ++x)
			{
				if (y < m_starting_lines_count)
				{
					square_ = squares_line_[x];
					if (square_.is_black())
					{
						auto piece_ = c_draughts_piece(square_, draughts_white, draughts_man);
						m_pieces_white.push_back(piece_);
					}
				}
				else if (y >= squares_lines_.size() - m_starting_lines_count)
				{
					square_ = squares_line_[x];
					if (square_.is_black())
					{
						auto piece_ = c_draughts_piece(square_, draughts_black, draughts_man);
						m_pieces_black.push_back(piece_);
					}
				}
			}
		}
    }
    c_draughts::~c_draughts()
    {
    }
}
