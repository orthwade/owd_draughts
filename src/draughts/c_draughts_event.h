#pragma once
#include <functional>

namespace owd
{
	class c_draughts_event
	{
	public:
		inline void set_action(std::function<void()> function) { m_action = function; }
		inline void enable() { m_enabled = true; }
		inline void disable() { m_enabled = false; }

		void run();

	private:
		bool m_enabled = false;
		std::function<void()> m_action{};
	};
}