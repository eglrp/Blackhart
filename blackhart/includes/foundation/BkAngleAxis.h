#ifndef __BK_ANGLE_AXIS_H__
#define __BK_ANGLE_AXIS_H__

// blackhart headers.
#include "foundation\BkExport.h"
#include "foundation\BkAtomicDataType.h"
#include "foundation\BkVector3.h"

// Type definitions.
struct BkAngleAxis
{
	real angle;
	struct BkVector3 axis;
};

// ~~~~~ Dcl(PUBLIC) ~~~~~

/*! \brief Constructs a BkAngleAxis object with the angle and axis components filled.
 *
 * \param angle The angle of rotation. [Must be in degrees]
 * \param axis The axis of rotation. [Must be normalized]
 * \return The new BkAngleAxis object.
 */
extern BK_API struct BkAngleAxis    BkAngleAxis_FromAngleAxis(real const angle, struct BkVector3 const* axis);

/*! \brief Sets the angle of rotation.
 *
 * \param obj The BkAngleAxis struct to modify.
 * \param angle The angle of rotation. [Must be in degrees]
 */
extern BK_API void  BkAngleAxis_SetAngle(struct BkAngleAxis* obj, real const angle);

/*! \brief Sets the axis of rotation.
 *
 * \param obj The BkAngleAxis to modify.
 * \param axis The axis of rotation. [Must be normalized]
 */
extern BK_API void  BkAngleAxis_SetAxis(struct BkAngleAxis* obj, struct BkVector3 const* axis);

#endif
