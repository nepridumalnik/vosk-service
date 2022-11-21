#pragma once

#include <controllers/interfaces/server.hpp>

#include <boost/asio.hpp>

namespace controllers
{

namespace server
{

class ServerImpl : public Server
{
public:
    /// @brief see Server
    void Start() override;

    /// @brief see Server
    void Stop() override;

private:
    boost::asio::io_context context_;
};
;

} // namespace server

} // namespace controllers
