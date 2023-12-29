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
IncludeDir["Glad"] = "dvigatel/vendor/Glad/include"
IncludeDir["ImGui"] = "dvigatel/vendor/imgui"

include "dvigatel/vendor/GLFW"
include "dvigatel/vendor/GLAD"
include "dvigatel/vendor/imgui"

project "dvigatel"
	location "dvigatel"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines {
			"DVG_PLATFORM_WINDOWS", 
			"DVG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
		}


	filter "configurations:Debug"
		defines "DVG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "DVG_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "DVG_DIST"
		runtime "Release"
		optimize "On"

project "sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		systemversion "latest"

		defines {
			"DVG_PLATFORM_WINDOWS", 
		}

	filter "configurations:Debug"
		defines "DVG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "DVG_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "DVG_DIST"
		runtime "Release"
		optimize "On"

