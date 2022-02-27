#include "c_oal_debug.h"

namespace owd
{
	c_oal_debug* c_oal_debug::m_sinaleton = nullptr;

	c_oal_debug* owd::c_oal_debug::get_instance()
	{
		if (m_sinaleton == nullptr)
		{
			m_sinaleton = new c_oal_debug();
		}

		return m_sinaleton;
	}

	void c_oal_debug::terminate()
	{
		if (m_sinaleton == nullptr)
		{

		}
		else
		{
			delete m_sinaleton;
			m_sinaleton = nullptr;
		}
	}
	std::wstring_view c_oal_debug::error_view(ALenum error_code)
	{
		switch (error_code)
		{
		case AL_INVALID_NAME:
			al_error_str = L"[AL_INVALID_NAME] a bad name(ID) was passed to an OpenAL function";
			break;
		case AL_INVALID_ENUM:
			al_error_str = L"[AL_INVALID_ENUM] an invalid enum value was passed to an OpenAL function";
			break;;
		case AL_INVALID_VALUE:
			al_error_str = L"[AL_INVALID_VALUE] an invalid value was passed to an OpenAL function";
			break;;
		case AL_INVALID_OPERATION:
			al_error_str = L"[AL_INVALID_OPERATION] the requested operation is not valid";
			break;;
		case AL_OUT_OF_MEMORY:
			al_error_str = L"[AL_OUT_OF_MEMORY] the requested operation resulted in OpenAL running out of memory";
			break;
		default:
			al_error_str = L"uknown error";
			break;

		}
		return al_error_str;
	}
	bool c_oal_debug::al_log_call()
	{
		while (ALenum error = alGetError())
		{
			if (error != AL_NO_ERROR)
			{
				al_logger << L"----OpenAL call ERROR:\n" << error_view(error) << '\n';
				return false;
			}
		}
		al_logger << L"----OpenAL call SUCCESS\n";
		return true;
	}
	c_oal_debug::c_oal_debug()
	{
	}
	c_oal_debug::~c_oal_debug()
	{
	}
}
