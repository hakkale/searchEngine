#include "LoadResult.hpp"

LoadResult::LoadResult(const std::string &body, const std::string &url, long status, CURLcode error)
{
    this->body = body;
    this->url = url;
    this->status = status;
    this->error = error;
}

const std::string &LoadResult::getBody() const
{
    return this->body;
}

const std::string &LoadResult::getUrl() const
{
    return this->url;
}

long LoadResult::getStatus() const
{
    return status;
}
CURLcode LoadResult::isError() const {
    
    return this->error;
}