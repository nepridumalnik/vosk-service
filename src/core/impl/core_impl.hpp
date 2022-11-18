#include <interfaces/core.hpp>

#include <unordered_map>

namespace vosk_server
{
namespace core
{

class CoreImpl : public Core
{
public:
    std::unique_ptr<Listener> GetListener(const std::string &modelName) override;
    void AddModel(const std::string &path, const std::string &name) override;

private:
    std::unordered_map<const std::string, Model> models_;
};

} // namespace core
} // namespace vosk_server
