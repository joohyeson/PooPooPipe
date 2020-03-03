#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *11.18.2019
 *digipen.hagyeong@gmail.com
 *CompotnentType.h
 *this is component type header
 */
#include <string>

enum ComponentType {
	COMPONENTTYPE_NULL=0, 
	COMPONENTTYPE_MESH, 
	COMPONENTTYPE_TRANSFORM,
	COMPONENTTYPE_PIPE,
	COMPONENTTYPE_COORDINATES,
	COMPONENTTYOE_COLLISIONCHECK
};

inline ComponentType StringToComponent(const std::string& string)
{
	if (string == "COMPONENTTYPE_MESH")			    return ComponentType::COMPONENTTYPE_MESH;
	if (string == "COMPONENTTYPE_TRANSFORM")			    return ComponentType::COMPONENTTYPE_TRANSFORM;
	if (string == "COMPONENTTYPE_PIPE")			    return ComponentType::COMPONENTTYPE_PIPE;
	if (string == "COMPONENTTYPE_COORDINATES")			    return ComponentType::COMPONENTTYPE_COORDINATES;
	if (string == "COMPONENTTYOE_COLLISIONCHECK")			    return ComponentType::COMPONENTTYOE_COLLISIONCHECK;

	return ComponentType::COMPONENTTYPE_NULL;
}

inline std::string ComponentToString(ComponentType type)
{
	if (type == ComponentType::COMPONENTTYPE_MESH)		        return "COMPONENTTYPE_MESH";
	if (type == ComponentType::COMPONENTTYPE_TRANSFORM)		        return "COMPONENTTYPE_TRANSFORM";
	if (type == ComponentType::COMPONENTTYPE_PIPE)		        return "COMPONENTTYPE_PIPE";
	if (type == ComponentType::COMPONENTTYPE_COORDINATES)		        return "COMPONENTTYPE_COORDINATES";
	if (type == ComponentType::COMPONENTTYOE_COLLISIONCHECK)		        return "COMPONENTTYOE_COLLISIONCHECK";

	return "COMPONENTTYPE_NULL";
}