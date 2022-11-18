#include <interfaces/listener.hpp>

#include <types/data_types.hpp>

namespace vosk_server
{
namespace core
{

class ListenerImpl : public Listener
{
public:
    explicit ListenerImpl(RecognizerPtr recognizer);

    std::string operator<<(const std::string &audio) override;

    ~ListenerImpl() = default;

private:
    RecognizerPtr recognizer_;
};

} // namespace core
} // namespace vosk_server
