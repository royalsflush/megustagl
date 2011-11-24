#ifndef MGGL_VERTEX_OPS_H
#define MGGL_VERTEX_OPS_H

class Vector;

Vector mggl_processVertex(const Vector& v, const Vector& n);

//Transforms, one by one
Vector mggl_modelViewTransform(const Vector& v);
Vector mggl_normalToEyeTransform(const Vector& v);
Vector mggl_projectionTransform(const Vector& v);
Vector mggl_viewportTransform(const Vector& v);

#endif // MGGL_VERTEX_OPS_H
