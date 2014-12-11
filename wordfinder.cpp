#include "wordfinder.h"
#include <boost/unordered_map.hpp>
#include <vector>


typedef boost::unordered_map<wchar_t, std::vector<LetterPoint> > map_type;

namespace {
    bool isNeighbours(const LetterPoint& center, const LetterPoint& neighbour)
    {
        return (center.getX() == neighbour.getX() && (center.getY() == neighbour.getY() + 1 || center.getY() == neighbour.getY() - 1))
                || (center.getY() == neighbour.getY() && (center.getX() == neighbour.getX() + 1 || center.getX() == neighbour.getX() - 1));
    }

    bool findInMap(map_type& map, const std::wstring& pattern, LetterPoint& currentPoint, std::stack<LetterPoint>& path)
    {
        currentPoint.setUsed(true);
        path.push(currentPoint);

        if (pattern.size() == 0)
        {
            return true;
        }
        if (map.count(pattern.at(0)) == 0)
        {
            return false;
        }
        std::vector<LetterPoint>& nextPointList = map.find(pattern.at(0))->second;

        for (size_t i = 0 ; i < nextPointList.size() ; ++i)
        {
            if (!nextPointList.at(i).isUsed() && isNeighbours(currentPoint, nextPointList.at(i)) &&
                    findInMap(map, pattern.substr(1), map.find(pattern.at(0))->second.at(i), path))
            {
                return true;
            }
        }

        currentPoint.setUsed(false);
        path.pop();
        return false;
    }
}

namespace WordFinder {
    bool findPattern(
            const std::vector<std::vector<wchar_t> >& matrix,
            const std::wstring& pattern,
            std::stack<LetterPoint>& path)
    {
        boost::unordered_map<wchar_t, std::vector<LetterPoint> > map;
        for (size_t i = 0 ; i < matrix.size() ; ++i)
        {
            for (size_t j = 0 ; j < matrix.at(i).size() ; ++j)
            {
                map_type::value_type initList(matrix.at(i).at(j), std::vector<LetterPoint>());
                map.insert(initList);
                map_type::iterator iterator = map.find(matrix.at(i).at(j));
                iterator->second.push_back(LetterPoint(i, j, matrix.at(i).at(j)));
            }
        }

        if (map.count(pattern.at(0)) == 0)
        {
            return false;
        }

        for (size_t i = 0 ; i < map.find(pattern.at(0))->second.size() ; ++i)
        {
            if (findInMap(map, pattern.substr(1), map.find(pattern.at(0))->second.at(i), path))
            {
                return true;
            }
        }

        return false;
    }
}
