workspace "SoonMoom"
	architecture "x64"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir={}
IncludeDir["GLFW"] = "SoonMoom/vendor/GLFW/include"
IncludeDir["Glad"] = "SoonMoom/vendor/Glad/include"
IncludeDir["Imgui"] = "SoonMoom/vendor/imgui"
IncludeDir["glm"] = "SoonMoom/vendor/glm"

include "SoonMoom/vendor/GLFW"
include "SoonMoom/vendor/Glad"
include "SoonMoom/vendor/imgui"

project "SoonMoom"
	location "SoonMoom"
	kind"SharedLib"
	language "C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	pchheader "smpch.h"
	pchsource "SoonMoom/src/smpch.cpp"

	files
	{
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.Imgui}"
	}
	
	links
	{
		"GLFW",
		"Glad",
		"ImGui"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SM_PLATFORM_WINDOWS",
			"SM_BUIILD_DLL"                                      
		}

		postbuildcommands 
		{
			("{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .."/Sandbox/")
		}



	filter "configurations:Debug"
		defines "SM_DEBUG"
		buildoptions "/MDd"
		symbols "On" 
		
	filter "configurations:Release"
		defines "SM_RELEASE"
		buildoptions "/MD"
		optimize "On"   

	filter "configurations:Dist"
		defines "SM_DIST"
		buildoptions "/MD"
		optimize "On"




project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")




	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SoonMoom/src",
		"SoonMoom/vendor/glm",
		"SoonMoom/vendor/spdlog/include"

	} 

	links
	{
		"SoonMoom"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SM_PLATFORM_WINDOWS"
		}




	filter "configurations:Debug"
		defines "SM_DEBUG"
		buildoptions "/MDd"
		symbols "On" 
		
	filter "configurations:Release"
		defines "SM_RELEASE"
		buildoptions "/MD"
		optimize "On"   

	filter "configurations:Dist"
		defines "SM_DIST"
		buildoptions "/MD"
		optimize "On"