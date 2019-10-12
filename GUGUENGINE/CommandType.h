#pragma once
#include <string>

enum ComponentType {
	COMPONENTTYPE_NULL = 0,
	CHAGNE_STATE,
	QUTI,
	COMPONENTTYPE_MESH,
	COMPONENTTYPE_TRANSFORM
};

inline ComponentType StringToCommand(const std::string& string)
{
	if (string == "CHAGNE_STATE")				return ComponentType::CHAGNE_STATE;
	if (string == "QUTI")				    return ComponentType::QUTI;
	return ComponentType::COMPONENTTYPE_NULL;
}

inline std::string CommandToString(ComponentType type)
{
	if (type == ComponentType::CHAGNE_STATE)				return "CHAGNE_STATE";
	if (type == ComponentType::QUTI)				        return "QUTI";

	return "COMPONENTTYPE_NULL";
}
