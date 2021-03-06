#pragma once
#include "c_openal_object.h"


namespace owd
{
	class c_sound_buffer : public c_openal_object
	{
	public:
		c_sound_buffer();
		~c_sound_buffer();

		void set_data(void* data, ALsizei bytes_count, ALsizei freq, ALenum format);
		ALuint* openal_buffer();

		void release();

	private:
		void m_gen_buffer();

		std::shared_ptr<ALuint> m_openal_buffer_ptr = std::make_shared<ALuint>();

	};
}


