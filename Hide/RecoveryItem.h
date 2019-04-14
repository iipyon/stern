#pragma once
#include"Item.h"

class RecoveryItem : public Item {
public:
	RecoveryItem(Point);
private:
	void efficacy() override;
};