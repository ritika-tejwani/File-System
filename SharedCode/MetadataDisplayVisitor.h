#pragma once
// declaration of MetadataDisplayVisitor here
#include <iostream>
#include "AbstractFileVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	void visit_ImageFile(ImageFile*);
	void visit_TextFile(TextFile*);
};
