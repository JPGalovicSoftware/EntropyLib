#include "Camera.h"
#include "../Math/Converters.h"

#include <cmath>

Entropy::Camera::Camera(Math::Vec3 position, Math::Vec3 up, float yaw, float pitch)
	: position(position), front(Math::Vec3(0.0f, 0.0f, -1.0f)), worldUp(up), yaw(yaw), pitch(pitch), zoom(45.0f)
{
	updateVectors();
}

Entropy::Math::Mat4 Entropy::Camera::getViewMatrix()
{
	return Math::Look(position, position + front, up);
}

void Entropy::Camera::updatePosition(CameraMovement direction, float deltaTime, float velocity)
{
	float adjustedVelocity = velocity * deltaTime;
	if (direction == CAMERA_FORWARD)
		position += front * adjustedVelocity;
	if (direction == CAMERA_BACKWARD)
		position -= front * adjustedVelocity;
	if (direction == CAMERA_RIGHT)
		position += right * adjustedVelocity;
	if (direction == CAMERA_LEFT)
		position -= right * adjustedVelocity;
	if (direction == CAMERA_UP)
		position += up * adjustedVelocity;
	if (direction == CAMERA_DOWN)
		position -= up * adjustedVelocity;

	if (direction == WORLD_UP)
		position += worldUp * adjustedVelocity;
	if (direction == WORLD_DOWN)
		position -= worldUp * adjustedVelocity;
}

void Entropy::Camera::updateRotation(float xOffset, float yOffset, bool constrainPitch, float minPitch, float maxPitch)
{
	yaw -= xOffset;
	pitch -= yOffset;

	if (constrainPitch)
	{
		if (pitch > maxPitch)
			pitch = maxPitch;
		if (pitch < minPitch)
			pitch = minPitch;
	}

	updateVectors();
}

void Entropy::Camera::updateFOV(float offset)
{
	zoom -= offset;
	if (zoom < 1.0f)
		zoom = 1.0f;
	if (zoom > 110.0f)
		zoom = 110.0f;
}

void Entropy::Camera::updateVectors()
{
	Math::Vec3 direction(
		cos(Math::Radians(yaw)) * cos(Math::Radians(pitch)),
		sin(Math::Radians(pitch)),
		sin(Math::Radians(yaw)) * cos(Math::Radians(pitch)));

	front = normalize(direction);
	right = normalize(cross(worldUp, front));
	up = normalize(cross(front, right));
}