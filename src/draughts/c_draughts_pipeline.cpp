#include "c_draughts_pipeline.h"

namespace owd
{
	c_draughts_pipeline* c_draughts_pipeline::m_singleton = nullptr;
	
	void c_draughts_pipeline::add_event(const c_draughts_event& event)
	{
		m_vec_events.push_back(event);
	}

	c_draughts_pipeline* owd::c_draughts_pipeline::get_instance()
	{
		if (m_singleton == nullptr)
		{
			m_singleton = new c_draughts_pipeline();
		}

		return m_singleton;
	}
	
	void c_draughts_pipeline::terminate()
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
    c_draughts_pipeline::c_draughts_pipeline()
    {
    }
    c_draughts_pipeline::~c_draughts_pipeline()
    {
    }
}
