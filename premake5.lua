workspace "GameEngineProto"
	architecture "x64"
	configurations{"Debug", "Release", "Dist"} --debug, release, and distribution

outputDirectory = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" --sets output directory extension dynamically. Format is {Configuration}-{System(OS)}-{Architectire(x32/x64)}

IncludeDir = {}
IncludeDir["glfw"] = "GameEnginePrototype/externalLibs/glfw/include"
IncludeDir["opengl"] = "GameEnginePrototype/externalLibs/opengl/include"
IncludeDir["imgui"] = "GameEnginePrototype/externalLibs/ImGui"


include "GameEnginePrototype/externalLibs/glfw"
include "GameEnginePrototype/externalLibs/OpenGL"
include "GameEnginePrototype/externalLibs/ImGui"


project "GameEnginePrototype"
	location "GameEnginePrototype"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputDirectory .. "/%{prj.name}") --puts all targeted files into the given output directory
	objdir("bin-int/" .. outputDirectory .. "/%{prj.name}") --sets path of all object/intermediate files

	pchheader "PrecompiledHeaders.h"
	pchsource "GameEnginePrototype/src/PrecompiledHeaders.cpp"

	files{
		"%{prj.name}/src/**.h", --takes all files in src with .h 
		"%{prj.name}/src/**.cpp" --takes all files with .cpp
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/externalLibs/spdlogging/include", --include directories in project building 
		"%{IncludeDir.glfw}",
		"%{IncludeDir.opengl}",
		"%{IncludeDir.imgui}"
	}

	links{
		"glfw",
		"opengl",
		"imgui",
		"opengl32.lib"
	}
	

	--only set for windows system (maybe mac/linux?)
	filter "system:windows"
		cppdialect "C++17" --sets c++ dialect
		staticruntime "On" --sets runtimeLibrary to MultiThreaded and to allow DLL use
		systemversion "latest" --sets SDK version to latest

		defines{
			"PROTO_PLATFORM_WINDOWS",
			"PROTO_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDirectory .. "/Prototype") --post-build command copies DLL file to the EXE Prototype file
		}
	--filters to define macros for different configurations
	filter "configurations:Debug"
		defines "DEBUG_APP"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "RELEASE_PROTO"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "DISTRIBUTION_VERSION"
		buildoptions "/MD"
		optimize "On"

	--later multithread support??

project "Prototype"
	location "Prototype"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputDirectory .. "/%{prj.name}") --puts all targeted files into the given output directory
	objdir("bin-int/" .. outputDirectory .. "/%{prj.name}") --sets path of all object/intermediate files

	files{
		"%{prj.name}/src/**.h", --takes all files in src with .h 
		"%{prj.name}/src/**.cpp" --takes all files with .cpp
	}
	--include directories in project building 
	includedirs{
		"GameEnginePrototype/externalLibs/spdlogging/include",
		"GameEnginePrototype/src"
	}

	links{
		"GameEnginePrototype"
	}
	

	--only set for windows system (maybe mac/linux?)
	filter "system:windows"
		cppdialect "C++17" --setes c++ dialect
		staticruntime "On" --sets runtimeLibrary to MultiThreaded and to allow DLL use
		systemversion "latest" --sets SDK version to latest

		defines{
			"PROTO_PLATFORM_WINDOWS"
		}

	--filters to define macros for different configurations
	filter "configurations:Debug"
		defines "DEBUG_APP"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "RELEASE_PROTO"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "DISTRIBUTION_VERSION"
		buildoptions "/MD"
		optimize "On"