// Напишите программу, используя технику TDD. Реализуйте калькулятор,
// поддерживающий операции: +, -, *, /. Проверьте тестами свойства операций
// и законы элементарной алгебры.

#include <cassert>

namespace Command { char Add = '+', Sub = '-', Mul = '*', Div = '/'; }

double calc(char operation, double x, double y) {
    if (operation == '+') {
        return x + y;
    }
    if (operation == '-') {
        return x - y;
    }
    if (operation == '*') {
        return x * y;
    }
    if (operation == '/') {
        assert(y != 0);
        return x / y;
    }
    return 0;
}

int main() {
    assert(calc(Command::Add, 0.0, 0.0) == 0.0);
    assert(calc(Command::Sub, 0.0, 0.0) == 0.0);
    assert(calc(Command::Mul, 0.0, 0.0) == 0.0);

    // Коммутативность сложения
    assert(calc(Command::Add, 2.0, 1.0) == 3.0);
    assert(calc(Command::Add, 1.0, 2.0) == 3.0);
    // Продолжить
    assert(calc(Command::Add, 6.9, 2.6) == 9.5);
    assert(calc(Command::Add, -6.9, -2.6) == -9.5);
    assert(calc(Command::Add, 0.0, 7.8) == 7.8);
    assert(calc(Command::Sub, 1.0, 4.0) == -3.0);
    assert(calc(Command::Sub, 0.0, 3.3) == -3.3);
    assert(calc(Command::Mul, 0.0, 9.93) == 0.0);
    assert(calc(Command::Mul, 0.5, 28.6) == 14.3);
    assert(calc(Command::Mul, 4.0, -5.0) == -20.0);
    assert(calc(Command::Div, 20.0, 5.0) == 4.0);
    assert(calc(Command::Div, -10.0, 4.0) == -2.5);
    assert(calc(Command::Div, -10.0, 3.0) == -10. / 3);
    // Коммутативность умножения
    assert(calc(Command::Mul, 0.5, 8.0) == 4.0);
    assert(calc(Command::Mul, 8.0, 0.5) == 4.0);
    return 0;
}
