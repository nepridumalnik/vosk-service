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

    ~CoreImpl() override = default;

private:
    std::unordered_map<std::string, std::unique_ptr<Model>> models_;
};

} // namespace core
} // namespace vosk_server
