// Blackhart.foundation headers.
#include "foundation\BkCamera.h"


// ~~~~~ Def(ALL) ~~~~~

void	BkCamera_Initialize(struct BkCamera* camera)
{
	camera->transform.cam_to_world = BkMatrix4x4_Identity();
	camera->transform.world_to_cam = BkMatrix4x4_Identity();
	camera->mode = AUTOMATIC;
	camera->sensor.sensor_width = BK_REAL(36.0);
	camera->sensor.sensor_height = BK_REAL(24.0);
	camera->sensor.resolution_width = 1920;
	camera->sensor.resolution_height = 1080;
	camera->sensor.iso = 100;
	camera->motor.shutter_speed = BK_REAL(1.0 / 1000.0);
	camera->lens.aperture = BK_REAL(8.0);
	camera->lens.focal_length = 50;
}

void	BkCamera_LookAt(struct BkCamera* camera, struct BkPoint3 const* from, struct BkPoint3 const* to, struct BkVector3 const* up)
{
	struct BkVector3 f = BkPoint3_Sub_BkPoint3(to, from);
	f = BkVector3_Normalize(&f);

	struct BkVector3 r = BkVector3_Cross(up, &f);

	struct BkVector3 u = BkVector3_Cross(&f, &r);

	struct BkMatrix4x4* m = &(camera->transform.cam_to_world);

	m->m11 = r.x;            m->m12 = u.x;            m->m13 = f.x;            m->m14 = from->x;
	m->m21 = r.y;            m->m22 = u.y;            m->m23 = f.y;            m->m24 = from->y;
	m->m31 = r.z;            m->m32 = u.z;            m->m33 = f.z;            m->m34 = from->z;
	m->m41 = BK_REAL(0.0);   m->m42 = BK_REAL(0.0);   m->m43 = BK_REAL(0.0);   m->m44 = BK_REAL(1.0);
	
	camera->transform.world_to_cam = BkMatrix4x4_Inverse(m);
}