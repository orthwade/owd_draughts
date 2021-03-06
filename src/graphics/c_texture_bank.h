#pragma once
#include "../filesystem/c_file_bank.h"
#include "c_texture.h"

namespace owd
{
	class c_texture_bank : public c_file_bank<c_texture>
	{
	public:
		static c_texture_bank* get_instance();
		static void terminate();

	private:
		static c_texture_bank* m_singleton;

		c_texture_bank();
		~c_texture_bank();

		c_texture_bank(const c_texture_bank&) = delete;
		c_texture_bank& operator=(const c_texture_bank&) = delete;
	};
}