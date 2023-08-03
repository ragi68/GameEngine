project "OpenGL"
	kind "StaticLib"
	language "C"

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
		buildoptions{"-std=cll", "-ldgi32" }
		systemversion "latest" 
		staticruntime "On" 
		
		
	
	filter {"system:windows", "configurations:Release"}
		buildoptions "/MT"
