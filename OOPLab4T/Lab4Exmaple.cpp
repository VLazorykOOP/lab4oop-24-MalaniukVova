//4.1
#include <iostream>

class VectorUInt {
private:
    unsigned int* data;
    size_t size;
    int codeError;

public:
    // Constructors
    VectorUInt() : data(new unsigned int[1]), size(1), codeError(0) {
        *data = 0;
    }

    VectorUInt(size_t newSize) : size(newSize), codeError(0) {
        data = new unsigned int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }

    VectorUInt(size_t newSize, unsigned int initValue) : size(newSize), codeError(0) {
        data = new unsigned int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = initValue;
        }
    }

    VectorUInt(const VectorUInt& other) : size(other.size), codeError(other.codeError) {
        data = new unsigned int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Destructor
    ~VectorUInt() {
        delete[] data;
    }

    // Assignment operator
    VectorUInt& operator=(const VectorUInt& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            codeError = other.codeError;
            data = new unsigned int[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Unary operators
    VectorUInt operator++(int) { // Post-increment
        VectorUInt temp(*this);
        for (size_t i = 0; i < size; ++i) {
            data[i]++;
        }
        return temp;
    }

    VectorUInt operator--(int) { // Post-decrement
        VectorUInt temp(*this);
        for (size_t i = 0; i < size; ++i) {
            data[i]--;
        }
        return temp;
    }

    VectorUInt& operator++() { // Pre-increment
        for (size_t i = 0; i < size; ++i) {
            ++data[i];
        }
        return *this;
    }

    VectorUInt& operator--() { // Pre-decrement
        for (size_t i = 0; i < size; ++i) {
            --data[i];
        }
        return *this;
    }

    bool operator!() const { // Logical NOT
        return size == 0;
    }

    VectorUInt operator~() const { // Bitwise NOT
        VectorUInt result(*this);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = ~result.data[i];
        }
        return result;
    }

    VectorUInt operator-() const { // Unary minus
        VectorUInt result(*this);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = -result.data[i];
        }
        return result;
    }

    // Compound assignment operators
    VectorUInt& operator+=(const VectorUInt& other) {
        if (size != other.size) {
            codeError = 1; // Error: sizes are different
        }
        else {
            for (size_t i = 0; i < size; ++i) {
                data[i] += other.data[i];
            }
        }
        return *this;
    }

    VectorUInt& operator-=(const VectorUInt& other) {
        if (size != other.size) {
            codeError = 1; // Error: sizes are different
        }
        else {
            for (size_t i = 0; i < size; ++i) {
                data[i] -= other.data[i];
            }
        }
        return *this;
    }

    VectorUInt& operator*=(unsigned int scalar) {
        for (size_t i = 0; i < size; ++i) {
            data[i] *= scalar;
        }
        return *this;
    }

    VectorUInt& operator/=(unsigned int divisor) {
        if (divisor == 0) {
            codeError = 2; // Error: division by zero
        }
        else {
            for (size_t i = 0; i < size; ++i) {
                data[i] /= divisor;
            }
        }
        return *this;
    }

    VectorUInt& operator%=(unsigned int divisor) {
        if (divisor == 0) {
            codeError = 2; // Error: division by zero
        }
        else {
            for (size_t i = 0; i < size; ++i) {
                data[i] %= divisor;
            }
        }
        return *this;
    }

    // Binary arithmetic operators
    VectorUInt operator+(const VectorUInt& other) const {
        if (size != other.size) {
            codeError = 1; // Error: sizes are different
            return VectorUInt();
        }
        else {
            VectorUInt result(*this);
            for (size_t i = 0; i < size; ++i) {
                result.data[i] += other.data[i];
            }
            return result;
        }
    }

    VectorUInt operator-(const VectorUInt& other) const {
        if (size != other.size) {
            codeError = 1; // Error: sizes are different
            return VectorUInt();
        }
        else {
            VectorUInt result(*this);
            for (size_t i = 0; i < size; ++i) {
                result.data[i] -= other.data[i];
            }
            return result;
        }
    }

    VectorUInt operator*(unsigned int scalar) const {
        VectorUInt result(*this);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] *= scalar;
        }
        return result;
    }

    VectorUInt operator/(unsigned int divisor) const {
        if (divisor == 0) {
            codeError = 2; // Error: division by zero
            return VectorUInt();
        }
        else {
            VectorUInt result(*this);
            for (size_t i = 0; i < size; ++i) {
                result.data[i] /= divisor;
            }
            return result;
        }
    }

    VectorUInt operator%(unsigned int divisor) const {
        if (divisor == 0) {
            codeError = 2; // Error: division by zero
            return VectorUInt();
        }
        else {
            VectorUInt result(*this);
            for (size_t i = 0; i < size; ++i) {
                result.data[i] %= divisor;
            }
            return result;
        }
    }

    // Bitwise binary operators
    VectorUInt operator|(const VectorUInt& other) const {
        if (size != other.size) {
            codeError = 1; // Error: sizes are different
            return VectorUInt();
        }
        else {
            VectorUInt result(*this);
            for (size_t i = 0; i < size; ++i) {
                result.data[i] |= other.data[i];
            }
            return result;
        }
    }

    VectorUInt operator^(const VectorUInt& other) const {
        if (size != other.size) {
            codeError = 1; // Error: sizes are different
            return VectorUInt();
        }
        else {
            VectorUInt result(*this);
            for (size_t i = 0; i < size; ++i) {
                result.data[i] ^= other.data[i];
            }
            return result;
        }
    }

    VectorUInt operator&(const VectorUInt& other) const {
        if (size != other.size) {
            codeError = 1; // Error: sizes are different
            return VectorUInt();
        }
        else {
            VectorUInt result(*this);
            for (size_t i = 0; i < size; ++i) {
                result.data[i] &= other.data[i];
            }
            return result;
        }
    }

    // Indexing operator
    unsigned int& operator[](size_t index) {
        if (index >= size) {
            codeError = 3; // Error: index out of bounds
            return data[size - 1]; // Return the last element
        }
        else {
            return data[index];
        }
    }

    // Comparison operators
    bool operator==(const VectorUInt& other) const {
        if (size != other.size) {
            codeError = 1; // Error: sizes are different
            return false;
        }
        else {
            for (size_t i = 0; i < size; ++i) {
                if (data[i] != other.data[i]) return false;
            }
            return true;
        }
    }

    bool operator!=(const VectorUInt& other) const {
        return !(*this == other);
    }

    // Utility methods
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Getters
    size_t getSize() const { return size; }
    int getErrorCode() const { return codeError; }
};

int main() {
    VectorUInt vec1(5);
    VectorUInt vec2(5, 10);
    VectorUInt vec3(vec1); // Copy constructor

    vec1.print(); // Output: 0 0 0 0 0
    vec2.print(); // Output: 10 10 10 10 10
    vec3.print(); // Output: 0 0 0 0 0

    vec1[2] = 15; // Modify element at index 2

    std::cout << "Size of vec1: " << vec1.getSize() << std::endl;
    std::cout << "Error code of vec1: " << vec1.getErrorCode() << std::endl;

    VectorUInt vec4 = vec1 + vec2; // Addition

    vec4.print(); // Output: 10 10 25 10 10

    return 0;
}


//4.2
class BankAccountInfo {
private:
    std::map<std::string, std::string> data;

public:
    void addInfo(const std::string& key, const std::string& value) {
        data[key] = value;
    }

    std::string& operator[](const std::string& key) {
        if (data.find(key) != data.end()) {
            return data[key];
        }
        else {
            static std::string error = "CodeError";
            return error;
        }
    }

    friend std::istream& operator>>(std::istream& input, BankAccountInfo& obj);

    friend std::ostream& operator<<(std::ostream& output, const BankAccountInfo& obj);
};
std::ostream& operator<<(std::ostream& output, const BankAccountInfo& obj) {
    output << "Surname: " << obj.data.at("Surname") << std::endl;
    output << "First Name: " << obj.data.at("First Name") << std::endl;
    output << "Patronymic: " << obj.data.at("Patronymic") << std::endl;
    return output;
}
std::istream& operator>>(std::istream& input, BankAccountInfo& obj) {
    std::string value;
    std::cout << "Enter surname: ";
    input >> value;
    obj.addInfo("Surname", value);
    std::cout << "Enter first name: ";
    input >> value;
    obj.addInfo("First Name", value);
    std::cout << "Enter patronymic: ";
    input >> value;
    obj.addInfo("Patronymic", value);
    return input;
}