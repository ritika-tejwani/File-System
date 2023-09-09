#pragma once

#include "AbstractParsingStrategy.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
private: 
	AbstractParsingStrategy* parsing_strategy; 
public:
	std::vector<std::string> parse(std::string);

};