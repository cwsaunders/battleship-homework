#pragma once
#include <iostream>
#include "Fleet.h"

class Strike : public Fleet
{


public:
	Strike() = default;
	virtual void hitOrMiss() const override;
};