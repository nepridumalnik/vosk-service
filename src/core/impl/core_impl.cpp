#include <impl/core_impl.hpp>

namespace vosk_server
{
namespace core
{

std::unique_ptr<Listener> CoreImpl::GetListener(const std::string &modelName)
{
    return {};
}

void CoreImpl::AddModel(const std::string &path, const std::string &name)
{
}

} // namespace core
} // namespace vosk_server
