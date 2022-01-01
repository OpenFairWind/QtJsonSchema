#include "QtJsonSchema/jsonschemanodevalidator07.h"
#include "QtJsonSchema/referenceresolver.h"

JsonSchemaNodeValidator07::JsonSchemaNodeValidator07()
{
  referenceResolver.reset(new ReferenceResolver());
}
