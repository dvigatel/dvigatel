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
IncludeDir["glm"] = "dvigatel/vendor/glm"

include "dvigatel/vendor/GLFW"
include "dvigatel/vendor/GLAD"
include "dvigatel/vendor/imgui"

project "dvigatel"
	location "dvigatel"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "dvgpch.h"
	pchsource "dvigatel/src/dvgpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"${prj.name}/vendor/glm/glm/**.hpp",
		"${prj.name}/vendor/glm/glm/**.inl",
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"DVG_PLATFORM_WINDOWS", 
			"DVG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "DVG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "DVG_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "DVG_DIST"
		runtime "Release"
		optimize "on"

project "sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"dvigatel/vendor/spdlog/include",
		"dvigatel/src",
		"dvigatel/vendor",
		"%{IncludeDir.glm}"
	}

	links {
		"dvigatel"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"DVG_PLATFORM_WINDOWS", 
		}

	filter "configurations:Debug"
		defines "DVG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "DVG_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "DVG_DIST"
		runtime "Release"
		optimize "on"

