#ifndef MGGL_RENDER_MODES_H
#define MGGL_RENDER_MODES_H

enum mggl_renderMode {
	MGGL_OPENGL_STYLE,
	MGGL_RAYTRACING
};

void mggl_setRenderMode(mggl_renderMode nRenderMode);
mggl_renderMode mggl_getRenderMode();

#endif // MGGL_RENDER_MODES_H
