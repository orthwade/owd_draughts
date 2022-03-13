#pragma once
#include <vector>
#include "c_draughts_event.h"

namespace owd
{
	class c_draughts_pipeline
	{
	public:
		void add_event(const c_draughts_event& event);
		static c_draughts_pipeline* get_instance();
		static void terminate();
	protected:
		std::vector<c_draughts_event> m_vec_events{};
		static c_draughts_pipeline* m_singleton;

		c_draughts_pipeline();
		~c_draughts_pipeline();
		
		c_draughts_pipeline(const c_draughts_pipeline&) = delete;
		c_draughts_pipeline& operator=(const c_draughts_pipeline&) = delete;
	};
}