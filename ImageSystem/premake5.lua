project "ImageSystem"

	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir   (out_dir .. "/%{prj.name}")
	objdir      (int_dir .. "/%{prj.name}")

	pchheader "include/ImageSystem/precompiled.hpp"
	pchsource "source/precompiled.cpp"

	files {
        "include/ImageSystem/**.h",
		"include/ImageSystem/**.hpp",
        
        "source/**.c",
		"source/**.cpp"
	}

	includedirs {
		"include"
	}

	filter "configurations:Debug"
		defines "_CONFIG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "_CONFIG_RELEASE"
		runtime "Release"
		optimize "on"
