//
// Created by Haibin Cao on 2/28/23.
//

#ifndef TYPING_SFML_RESOURCEHANDLER_H
#define TYPING_SFML_RESOURCEHANDLER_H
#include <SFML/Graphics.hpp>
#include <map>

template <typename ID, typename Resource>
class ResourceHandler
{
private:
    static std::map<ID, Resource> resourceMap;
public:
    ResourceHandler();
    static void load(ID id, const std::string& fileName);
    static Resource& get(ID id);
};
#include "ResourceHandler.cpp"

#endif //TYPING_SFML_RESOURCEHANDLER_H
