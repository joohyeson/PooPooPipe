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
};

inline ComponentType StringToComponent(const std::string& string)
{
	if (string == "COMPONENTTYPE_MESH")			    return ComponentType::COMPONENTTYPE_MESH;
	if (string == "COMPONENTTYPE_TRANSFORM")			    return ComponentType::COMPONENTTYPE_TRANSFORM;
	if (string == "COMPONENTTYPE_PIPE")			    return ComponentType::COMPONENTTYPE_PIPE;
	return ComponentType::COMPONENTTYPE_NULL;
}

inline std::string ComponentToString(ComponentType type)
{
	if (type == ComponentType::COMPONENTTYPE_MESH)		        return "COMPONENTTYPE_MESH";
	if (type == ComponentType::COMPONENTTYPE_TRANSFORM)		        return "COMPONENTTYPE_TRANSFORM";
	if (type == ComponentType::COMPONENTTYPE_PIPE)		        return "COMPONENTTYPE_PIPE";

	return "COMPONENTTYPE_NULL";
}