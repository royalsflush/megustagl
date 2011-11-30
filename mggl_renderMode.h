#ifndef MGGL_RENDER_MODES_H
#define MGGL_RENDER_MODES_H

enum renderMode {
	MGGL_OPENGL_STYLE,
	MGGL_RAYTRACING
};

void setRenderMode(renderMode nRenderMode);
renderMode getRenderMode();

#endif // MGGL_RENDER_MODES_H
