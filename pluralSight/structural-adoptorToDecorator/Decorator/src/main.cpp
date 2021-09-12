#include "OutputStream.h"
#include "StreamDecorator.h"

int main() {

    ConsoleStream stream;
    EncryptedStreamDecorator encrypted(&stream, 'b');

    std::cout << std::endl;
    encrypted.write("Hello encrypted");
    std::cout << std::endl;

    return 0;
}