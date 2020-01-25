#pragma once
#include <iostream>
#include "Fleet.h"

class Miss : public Fleet
{


public:
	Miss() = default;
	virtual void hitOrMiss() const override;
};