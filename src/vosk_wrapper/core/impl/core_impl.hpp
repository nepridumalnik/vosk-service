#include <vosk_wrapper/interfaces/core.hpp>

#include <types/macro.hpp>

#include <mutex>
#include <unordered_map>

namespace vosk_wrapper
{
namespace core
{

class CoreImpl : public Core
{
public:
    /// @see Core
    VOSK_EXPORT std::unique_ptr<Listener> GetListener(const std::string &modelName) override;

    /// @see Core
    VOSK_EXPORT void AddModel(const std::string &path, const std::string &name) override;

    /// @see Core
    VOSK_EXPORT void RemoveModel(const std::string &name) override;

    /// @brief Деструктор
    ~CoreImpl() override = default;

private:
    /// @brief Неупорядоченный словарь с языковыми моделями
    std::unordered_map<std::string, std::shared_ptr<Model>> models_;

    /// @brief Мьютекс
    std::mutex mutex_;
};

} // namespace core
} // namespace vosk_wrapper
