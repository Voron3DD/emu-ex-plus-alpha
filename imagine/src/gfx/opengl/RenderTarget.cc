/*  This file is part of Imagine.

	Imagine is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Imagine is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Imagine.  If not, see <http://www.gnu.org/licenses/> */

#include <imagine/gfx/RenderTarget.hh>
#include <imagine/base/GLContext.hh>
#include "private.hh"

namespace Gfx
{

void RenderTarget::init()
{
	glGenFramebuffers(1, &fbo);
	logMsg("init FBO:0x%X", fbo);
}

void RenderTarget::deinit()
{
	if(fbo)
	{
		logMsg("deinit FBO:0x%X", fbo);
		glDeleteFramebuffers(1, &fbo);
		fbo = 0;
	}
	tex.deinit();
}

void RenderTarget::setFormat(Renderer &r, IG::PixmapDesc pix)
{
	if(!tex)
		tex.init(r, {pix});
	else
		tex.setFormat(pix, 1);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, tex.texName(), 0);
	r.setRenderTarget({});
	logMsg("set texture:0x%X as FBO:0x%X target", tex.texName(), fbo);
}

RenderTarget::operator bool() const
{
	return fbo;
}

}
