#include <impl/core_impl.hpp>

#include <fstream>

static constexpr char ModelPath[] = "D:/Programming/C++/vosk-api/models/vosk-model-ru-0.22";
static constexpr char ModelName[] = "russian";
static constexpr char Voice[] = "D:/Programming/C++/vosk-api/resources/novy_god.wav";

int main(int argc, char const *argv[])
{
    vosk_server::core::CoreImpl core;
    core.AddModel(ModelPath, ModelName);

    std::string buffer;
    std::string result;

    // Прочитать файл
    {
        std::ifstream in{Voice, std::ios::binary};
        in.seekg(0, std::ios::end);
        buffer.resize(in.tellg());
        in.seekg(44, std::ios::beg);
        in.read(&buffer[0], buffer.size());
        in.close();
    }

    auto listener = core.GetListener(ModelName);
    result = listener->Recognize(buffer);

    // Записать файл
    {
        std::ofstream out{"test_output.txt"};
        out << result;
    }

    return 0;
}
