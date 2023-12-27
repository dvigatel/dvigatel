workspace "dvigatel"
	architecture "x64"

    configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["GLFW"] = "dvigatel/vendor/GLFW/include"

include "dvigatel/vendor/GLFW"

project "dvigatel"
	location "dvigatel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "dvgpch.h"
	pchsource "dvigatel/src/dvgpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links {
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines {
			"DVG_PLATFORM_WINDOWS", 
			"DVG_BUILD_DLL",
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
		}


	filter "configurations:Debug"
		defines "DVG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DVG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DVG_DIST"
		optimize "On"

project "sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"dvigatel/vendor/spdlog/include",
		"dvigatel/src"
	}

	links {
		"dvigatel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"DVG_PLATFORM_WINDOWS", 
		}

	filter "configurations:Debug"
		defines "DVG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DVG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DVG_DIST"
		optimize "On"

