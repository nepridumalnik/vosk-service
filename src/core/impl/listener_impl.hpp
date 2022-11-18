#include <interfaces/listener.hpp>

#include <types/data_types.hpp>

namespace vosk_server
{
namespace core
{

class ListenerImpl : public Listener
{
public:
    /// @brief Конструктор
    /// @param recognizer Распознаватель
    explicit ListenerImpl(RecognizerPtr recognizer);

    /// @see Listener
    std::string Recognize(const std::string &audio) override;

    /// @brief Деструктор
    ~ListenerImpl() = default;

private:
    /// @brief Распознаватель
    RecognizerPtr recognizer_;
};

} // namespace core
} // namespace vosk_server
