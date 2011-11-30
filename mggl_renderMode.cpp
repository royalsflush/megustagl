#include "mggl_renderMode.h"

static renderMode currMode=MGGL_OPENGL_STYLE;

void setRenderMode(renderMode nRenderMode) {
	currMode=nRenderMode;
}

renderMode getRenderMode() {
	return currMode;
}
