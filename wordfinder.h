#ifndef WORDFINDER_H
#define WORDFINDER_H

#include "letterpoint.h"
#include <stack>
#include <string>
#include <vector>

namespace WordFinder {
    bool findPattern(
            const std::vector<std::vector<wchar_t> > &matrix,
            const std::wstring& pattern,
            std::stack<LetterPoint>& path);
}

#endif // WORDFINDER_H
