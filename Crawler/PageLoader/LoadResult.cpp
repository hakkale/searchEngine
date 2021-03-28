#include "LoadResult.hpp"

LoadResult::LoadResult(const std::string& body, long status) : body(body), status(status)
{}

std::string LoadResult::getBody() const
{
    return body;
}

long LoadResult::getStatus() const
{
    return status;  
}