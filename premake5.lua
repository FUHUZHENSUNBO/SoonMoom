workspace "SoonMoom"
    architecture "x64"
    startproject "Sandbox"


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
IncludeDir["glm"] = "SoonMoom/vendor/glm"
IncludeDir["Imgui"] = "SoonMoom/vendor/imgui"

include "SoonMoom/vendor/GLFW"
include "SoonMoom/vendor/Glad"
include "SoonMoom/vendor/imgui"


project "SoonMoom"
    location "SoonMoom"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"


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


    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
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
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "SM_PLATFORM_WINDOWS",
            "SM_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines "SOONMOOM_DEBUG"
        runtime "Debug"
        symbols "on" 

    filter "configurations:Release"
        defines "SOONMOOM_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "SOONMOOM_DIST"
        runtime "Release"
        optimize "on"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("bin-int/"..outputdir.."/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "SoonMoom/vendor/spdlog/include",
        "SoonMoom/src",
        "%{IncludeDir.glm}",
        "SoonMoom/vendor"
    } 

    links
    {
        "SoonMoom"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "SM_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SOONMOOM_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "SOONMOOM_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "SOONMOOM_DIST"
        runtime "Release"
        optimize "on"