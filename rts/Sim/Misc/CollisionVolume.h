/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef COLLISION_VOLUME_H
#define COLLISION_VOLUME_H

#include "float3.h"
#include "creg/creg_cond.h"
#include "Util.h"

const float EPS = 0.0000000001f;

struct CollisionVolume
{
	CR_DECLARE_STRUCT(CollisionVolume);

	enum COLVOL_SHAPE_TYPES {
		COLVOL_TYPE_DISABLED  = -1,
		COLVOL_TYPE_ELLIPSOID =  0,
		COLVOL_TYPE_CYLINDER  =  1,
		COLVOL_TYPE_BOX       =  2,
		COLVOL_TYPE_SPHERE    =  3,
		COLVOL_TYPE_FOOTPRINT =  4, // intersection of sphere and footprint-prism
		COLVOL_NUM_SHAPES     =  5, // number of non-disabled collision volume types
	};

	enum COLVOL_AXES {
		COLVOL_AXIS_X   = 0,
		COLVOL_AXIS_Y   = 1,
		COLVOL_AXIS_Z   = 2,
		COLVOL_NUM_AXES = 3         // number of collision volume axes
	};
	enum COLVOL_HITTEST_TYPES {
		COLVOL_HITTEST_DISC = 0,
		COLVOL_HITTEST_CONT = 1,
		COLVOL_NUM_HITTESTS = 2     // number of hit-test types
	};

	CollisionVolume();
	CollisionVolume(const CollisionVolume* v, float defaultRadius = 0.0f);
	CollisionVolume(const std::string& volTypeStr, const float3& scales, const float3& offsets, int hitTestType);

	/**
	 * Called if a unit or feature does not define a custom volume.
	 * @param r the object's default radius
	 */
	void Init(float r);
	void Init(const float3& scales, const float3& offsets, int vType, int tType, int pAxis);

	int GetVolumeType() const { return volumeType; }
	int GetTestType() const { return testType; }
	void SetVolumeType(int type) { volumeType = type; }
	void SetTestType(int type) { testType = type; }
	void Enable() { disabled = false; }
	void Disable() { disabled = true; }

	int GetPrimaryAxis() const { return primaryAxis; }
	int GetSecondaryAxis(int axis) const { return secondaryAxes[axis]; }

	float GetBoundingRadius() const { return volumeBoundingRadius; }
	float GetBoundingRadiusSq() const { return volumeBoundingRadiusSq; }

	float GetOffset(int axis) const { return axisOffsets[axis]; }
	const float3& GetOffsets() const { return axisOffsets; }

	float GetScale(int axis) const { return axisScales[axis]; }
	float GetHScale(int axis) const { return axisHScales[axis]; }
	float GetHScaleSq(int axis) const { return axisHScalesSq[axis]; }
	const float3& GetScales() const { return axisScales; }
	const float3& GetHScales() const { return axisHScales; }
	const float3& GetHScalesSq() const { return axisHScalesSq; }
	const float3& GetHIScales() const { return axisHIScales; }

	void RescaleAxes(float xs, float ys, float zs);

	bool IsDisabled() const { return disabled; }
	bool DefaultScale() const { return defaultScale; }
	bool IsSphere() const { return volumeType == COLVOL_TYPE_SPHERE; }
	bool UseFootprint() const { return volumeType == COLVOL_TYPE_FOOTPRINT; }

private:
	void SetAxisScales(float xs, float ys, float zs);
	void SetBoundingRadius();

	float3 axisScales;                  ///< full-length axis scales
	float3 axisHScales;                 ///< half-length axis scales
	float3 axisHScalesSq;               ///< half-length axis scales (squared)
	float3 axisHIScales;                ///< half-length axis scales (inverted)
	float3 axisOffsets;                 ///< offsets wrt. the model's mid-position (world-space)

	float volumeBoundingRadius;         ///< radius of minimally-bounding sphere around volume
	float volumeBoundingRadiusSq;       ///< squared radius of minimally-bounding sphere
	int volumeType;
	int testType;
	int primaryAxis;
	int secondaryAxes[2];

	bool disabled;
	bool defaultScale;
};

#endif
