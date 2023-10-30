project "OpenGL"
	kind "StaticLib"
	language "C"
	cppdialect "C++17"
	staticruntime "On" 

	targetdir("bin/" .. outputDirectory .. "/%{prj.name}")
	objdir("bin-int/" .. outputDirectory .. "/%{prj.name}")

	files{
		"include/glad/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c"
	}

	includedirs{
		"include"
	}

	filter "system:windows" 
		systemversion "latest" 

		
		
	
	filter "configurations:Debug"
		defines "DEBUG_APP"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RELEASE_PROTO"
		runtime "Release"
		optimize "On"
