#pragma once
#include "../input/c_input_manager.h"

namespace owd
{
	class c_draughts_controls
	{
	public:
		static c_draughts_controls* get_instance();
		static void terminate();
	private:
		
		c_input_manager* m_controls_ptr = c_input_manager::get_instance();
		c_input_manager& m_controls = *m_controls_ptr;

		static c_draughts_controls* m_singleton;
		c_draughts_controls();
	};
}