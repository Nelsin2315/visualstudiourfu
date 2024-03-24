#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileEncryptor {
private:
    string inputFile;
    string outputFile;
    string key;

public:
    FileEncryptor(const string& inputFile, const string& outputFile, const string& key)
        : inputFile(inputFile), outputFile(outputFile), key(key) {}

    void encrypt() {
        ifstream fin(inputFile, ios::binary); // Открытие входного файла в бинарном режиме для чтения
        ofstream fout(outputFile, ios::binary); // Открытие выходного файла в бинарном режиме для записи

        if (!fin || !fout) {
            cerr << "Ошибка, фалй открыт" << endl;
            return;
        }

        size_t keyLength = key.length();
        size_t index = 0; 

        char ch;
        while (fin.get(ch)) { // Чтение файла посимвольно
            ch ^= key[index]; 

            fout.put(ch); // Запись зашифрованного символа в выходной файл

            // Переход к следующему символу ключа
            index = (index + 1) % keyLength;
        }

        fin.close();
        fout.close();

        cout << "Файл зашифрован" << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 4) { // Проверка корректного количества аргументов командной строки
        cerr << "Используйте: " << argv[0] << "1.txt" << endl;
        return 1;
    }

    string inputFile = argv[1]; // Имя входного файла
    string outputFile = argv[2]; // Имя выходного файла
    string key = argv[3]; // Ключ шифрования

    FileEncryptor encryptor(inputFile, outputFile, key);
    encryptor.encrypt();

    // Повторное шифрование зашифрованного файла с тем же ключом для проверки правильности программы
    FileEncryptor encryptorAgain(outputFile, "2.txt", key);
    encryptorAgain.encrypt();

    return 0;
}