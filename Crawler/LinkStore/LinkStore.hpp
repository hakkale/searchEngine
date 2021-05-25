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
    std::vector<Link> all;

public:
    LinkStore(){};
    //kveradardzni bolor linkery
    const std::vector<Link> getAll() const;

    std::optional<Link> getByUrl(const std::string& url) const;

    //amen angam vercnelu enq ayn linkery voronq spasman mej en, hnaravor e che vor amen angam 1000 hat spasox link lini dra hamar el vercnum enq count vor orinak arajin 10 haty vercnenq
    std::vector<Link> getBy(const std::string &domain, const LinkStatus status, std::size_t count) const;

    //add kogtagorcenq erb hertakan ejy crawl aneluc heto linkery stananq u avelacnenq, bayc ete arden ka chavelacnenq
    void add(const Link &link);

    //ete mi link mshakecinq vory spasman mej er gtnvum, petq e statusy poxel dardznel loaded kam error
    void update(const Link &link);

    std::size_t count() const;

};

#endif