#pragma once
#include <iostream>
#include "Fleet.h"

class HitAgain : public Fleet
{


public:
	HitAgain() = default;
	virtual void hitOrMiss() const override;
};