#include "c_draughts_controls.h"

namespace owd
{
	c_draughts_controls* c_draughts_controls::m_singleton = nullptr;

	c_draughts_controls* c_draughts_controls::get_instance()
	{
		if (m_singleton == nullptr)
		{
			m_singleton = new c_draughts_controls();
		}
		else
		{
		}
		return m_singleton;
	}

	void c_draughts_controls::terminate()
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

	c_draughts_controls::c_draughts_controls()
	{
		//m_controls.add_action(GLFW_KEY_UP, key_press, )

	}
}