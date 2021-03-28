#ifndef LOAD_RESULT_HPP
#define LOAD_RESULT_HPP

#include <string>
#include <memory>

class LoadResult
{
private:

    std::string body;

    long status;

public:
    LoadResult(const std::string& body, long status);

    std::string getBody() const;

    long getStatus() const;
};

#endif 