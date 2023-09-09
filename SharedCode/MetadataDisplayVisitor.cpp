// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"


using namespace std;


void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {
	cout << file->getName() << " " << "image" << " " << file->getSize() << endl;
}
void MetadataDisplayVisitor::visit_TextFile(TextFile*file) {
	cout << file->getName() << " " << "text" << " " << file->getSize() << endl;
}
