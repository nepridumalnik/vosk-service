#pragma once

#include <controllers/interfaces/server.hpp>

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
};

} // namespace server

} // namespace controllers
