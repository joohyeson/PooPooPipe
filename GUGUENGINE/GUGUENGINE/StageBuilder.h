#pragma once

//Forward declaration
class Stage;

//! Base Builder class to create Game Stages via a StageFactory
class StageBuilder
{
public:
	virtual ~StageBuilder() {} //empty virtual destructor
	//! Virtual Build call that must be overloaded by all Derived Builders
	virtual Stage* Build(void) = 0;
};

/*! Templated builder derived class so I don't need to create a Builder for each
Stage type*/
template <typename T>
class StageTBuilder : public StageBuilder
{
public:
	virtual Stage* Build(void);
};

//! Creates a new M5Stage of type T
template <typename T>
Stage* StageTBuilder<T>::Build(void)
{
	return new T();
}
