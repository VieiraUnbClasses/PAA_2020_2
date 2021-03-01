/* spoj submit code: https://www.spoj.com/status/ns=27492585
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;
std::vector<int> split(std::vector<int> vecInput);

std::vector<int> merge(std::vector<int> first, std::vector<int> second)
{
    if (first.size() == 1 && second.size() == 1)
    {
        if (first[0] < second[0])
        {
            return std::vector<int>({first[0], second[0]});
        }
        else
        {
            auto res = std::vector<int>({second[0], first[0]});
            return res;
        }
    }

    if (first.size() == 1 && second.size() == 2)
    {
        auto secOrdered = split(second);
        auto location = std::lower_bound(secOrdered.begin(), secOrdered.end(), first[0]);
        secOrdered.insert(location, first[0]);
        return secOrdered;
    }

    std::vector<int> res(split(first));
    auto secSplit = split(second);
    for (auto elem : secSplit)
    {
        auto location = std::lower_bound(res.begin(), res.end(), elem);
        res.insert(location, elem);
    }

    return res;
}

std::vector<int> split(std::vector<int> vecInput)
{

    auto half = vecInput.size() / 2;
    std::vector<int> first(vecInput.begin(), vecInput.begin() + half);

    std::vector<int> second(vecInput.begin() + half, vecInput.end());
    auto res = merge(first, second);
    return res;
}

int main()
{
    std::string input;
    getline(cin, input);
    auto iss = std::istringstream(input);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());

    std::vector<int> intInput;

    for (auto s : results)
    {
        auto intV = atoi(s.c_str());
        intInput.push_back(intV);
    }

    auto s = split(intInput);
    for (auto elem : s)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}