#include "smpch.h"
#include "RenderCommand.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace SoonMoom
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;



}