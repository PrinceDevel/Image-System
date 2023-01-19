project "Test"

	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"
	systemversion "latest"

	targetdir   (out_dir .. "/%{prj.name}")
	objdir      (int_dir .. "/%{prj.name}")

	files {
        "source/**.h",
		"source/**.c",
		"source/**.hpp",
		"source/**.cpp",

        "resource/**.*"
	}

	includedirs {
		"source",
        "%{wks.location}/ImageSystem/include"
    }

    links {
        "ImageSystem"
    }


	filter "configurations:Debug"
		defines "_CONFIG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "_CONFIG_RELEASE"
		runtime "Release"
		optimize "on"