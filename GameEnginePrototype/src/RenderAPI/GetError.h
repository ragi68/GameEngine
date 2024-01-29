#pragma once

namespace Proto {
	class Error {
	public:
		Error() = default;
		virtual void GetErrors() = 0;

		static Error* SeeError();
	};

	
}
