#include <interfaces/core.hpp>

#include <unordered_map>

namespace vosk_server
{
namespace core
{

class CoreImpl : public Core
{
public:
    /// @see Core
    std::unique_ptr<Listener> GetListener(const std::string &modelName) override;

    /// @see Core
    void AddModel(const std::string &path, const std::string &name) override;

    /// @brief Деструктор
    ~CoreImpl() override = default;

private:
    std::unordered_map<std::string, std::unique_ptr<Model>> models_;
};

} // namespace core
} // namespace vosk_server
