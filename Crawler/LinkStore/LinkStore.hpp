#ifndef LinkStore_hpp
#define LinkStore_hpp

#include "Link.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <optional>
class LinkStore
{
private:
    /*
     * The all effective urls
     */
    std::vector<Link> all;

public:
    LinkStore(){};
    /*
     * Return all urls
     */
    const std::vector<Link> getAll() const;

    std::optional<Link> getByUrl(const std::string& url) const;
    std::vector<Link> getBy(const std::string &domain, const LinkStatus status, std::size_t count) const;
    /*
     * Add new link to store
     */
    void add(const Link &link);

    /*
     * Update info for link
     */
    void update(Link link);
    /*
     * The count of links for editing
     */

    std::size_t count() const;
    LinkStore& operator=(const LinkStore&)= default;

};

#endif