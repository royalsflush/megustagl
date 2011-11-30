#include "mggl_renderMode.h"

static mggl_renderMode currMode=MGGL_OPENGL_STYLE;

void mggl_setRenderMode(mggl_renderMode nRenderMode) {
	currMode=nRenderMode;
}

mggl_renderMode mggl_getRenderMode() {
	return currMode;
}
