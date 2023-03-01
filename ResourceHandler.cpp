//
// Created by Haibin Cao on 2/28/23.
//

#ifndef TYPING_SFML_RESOURCEHANDLER_CPP
#define TYPING_SFML_RESOURCEHANDLER_CPP
#include "ResourceHandler.h"
template<typename ID, typename Resource>
std::map<ID, Resource> ResourceHandler<ID, Resource>::resourceMap;

template <typename ID, typename Resource>
ResourceHandler<ID, Resource>::ResourceHandler()
{

}

template <typename ID, typename Resource>
void ResourceHandler<ID, Resource>::load(ID id, const std::string& fileName)
{
    Resource resource;
    if(!resource.loadFromFile(fileName))
    {
        throw std::runtime_error("Failed to load " + fileName);
    };
    resourceMap.insert(std::make_pair(id, resource));
}

template<typename ID, typename Resource>
Resource& ResourceHandler<ID, Resource>::get(ID id)
{
//    typename std::map<ID, Resource>::iterator it;
//    it = resourceMap.find(id);
//    auto found = resourceMap.find(id);
//    return found->second;
    return resourceMap[id];
}

#endif