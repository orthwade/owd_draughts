#pragma once
#include <iostream>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <vector>

#include"../../debug/logger/logger.h"
#include "codec.h"
#include "vorbisfile.h"
#include "../../misc/misc_defines.h"
#include "../c_sound_file.h"

#pragma comment(lib, "ogg.lib")
#pragma comment(lib, "vorbisfile.lib")
#pragma comment(lib, "vorbisenc.lib")
#pragma comment(lib, "vorbis.lib")

namespace owd
{
	class c_ogg_file : public c_sound_file
	{
	public:
		c_ogg_file();
		~c_ogg_file();

		bool load(std::wstring_view filepath) override;
		bool load(std::wstring_view filepath, std::wstring_view name) override;
		
		void reset() override;

		inline	byte_t* sound_data_ptr() override { return m_sound_data_ptr; }

	private:
		byte_t*		m_sound_data_ptr = nullptr;
		byte_t*		m_sound_data_ptr_start_position = nullptr;
	};
}
