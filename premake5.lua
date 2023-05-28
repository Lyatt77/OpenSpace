workspace "OpenSpace"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "OpenSpace"
	location "OpenSpace"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OP_PLATFORM_WINDOWS" , 
			"OP_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox" )
		}

	filter "configurations:Debug"
		defines "OP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OP_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"OpenSpace/vendor/spdlog/include",
		"OpenSpace/src"
	}

	links
	{
		"OpenSpace"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OP_PLATFORM_WINDOWS" 
		}


	filter "configurations:Debug"
		defines "OP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OP_DIST"
		optimize "On"