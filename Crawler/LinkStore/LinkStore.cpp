#include "LinkStore.hpp"
#include <algorithm>
#include <iterator>
#include <optional>

const std::vector<Link> LinkStore::getAll() const
{
    return this->all;
}

std::optional<Link> LinkStore::getByUrl(const std::string &url) const
{
    for (auto &link : all)
    {
        if (link.getUrl() == url)
        {
            return link;
        }
    }
    return {};
}

std::vector<Link> LinkStore::getBy(const std::string &domain, const LinkStatus status, std::size_t count) const
{
    std::vector<Link> result;
    for (const auto &link : all)
    {
        if (count == 0){
            break;
        }
        if (link.getStatus() == status){
            result.push_back(link);
            --count;
        }
    }
    return result;
}

void LinkStore::add(const Link &link)
{
    all.push_back(link);
}

void LinkStore::update(Link link)
{
    for(auto &newLink : all)
    {
        if(newLink.getUrl() == link.getUrl())
        {
            newLink = link;
            return;
        }
    }
    all.push_back(link);
    
}

std::size_t LinkStore::count() const
{
    return this->all.size();
}
