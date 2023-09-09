#pragma once
#include "AbstractParsingStrategy.h"


class EditDisplayStrategy : public AbstractParsingStrategy {
private:
	AbstractParsingStrategy* parsing_strategy;
public:
	std::vector<std::string> parse(std::string);
};