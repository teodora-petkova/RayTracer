//---------------------------------------------------------------------
// camera.h Header
//---------------------------------------------------------------------
#ifndef CAMERA_H
#define CAMERA_H

#pragma once

#pragma warning(push, 0)
#include <tuple>
#pragma warning(pop)

#include "raytracer_exports.h"
#include "tuple.h"

class RAYTRACER_EXPORT Camera
{
public:
	Camera();
	Camera(const Tuple& lookFromPoint, const Tuple& lookAtPoint, const Tuple& viewUpVector,
		float fieldOfViewAngleY, int width, int height);

	Tuple CalculateDirectionRayForPixel(int x, int y) const;
	void UpdateLookAt(int x, int y);

	Tuple getOrigin() const;

private:
	Tuple lookAt;
	Tuple lookFrom;
	Tuple viewUp;
	Tuple w;
	Tuple u;
	Tuple v;
	float fovx;
	float fovy;
	int width;
	int height;
};
#endif