#include "c_draughts_event.h"

namespace owd
{
    void c_draughts_event::run()
    {
        if (m_enabled)
        {
            m_action();
        }
    }
}

