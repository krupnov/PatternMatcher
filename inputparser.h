#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include"common.h"
#include <string>

namespace inputparser {
    matrix_type parseInputFile(const std::string& fileName);
}

#endif // INPUTPARSER_H
