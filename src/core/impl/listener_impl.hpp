#include <interfaces/listener.hpp>

namespace vosk_server
{
namespace core
{

class ListenerImpl : public Listener
{
public:
    std::string operator<<(const std::string &audio) override;
};

} // namespace core
} // namespace vosk_server
