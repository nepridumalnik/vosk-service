#pragma once

namespace controllers
{

class Server
{
    /// @brief Начать работу
    virtual void Start() = 0;

    /// @brief Остановить работу
    virtual void Stop() = 0;
};

} // namespace controllers
